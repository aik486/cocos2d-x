#include "CocosGLWidget.h"

#include "cocos2dx_qt.h"

#include <QMouseEvent>

using namespace cocos2d;

#define LOG_MOUSE_EVENT(...) CCLOG(__VA_ARGS__)

class InternalMainNode : public CCNode
{
public:
	InternalMainNode(CocosGLWidget *widget);

	virtual void setScale(float scale) override;

	void initialized(float);

private:
	CocosGLWidget *widget;
};

bool CocosGLWidget::applicationDidFinishLaunching()
{
	return true;
}

void CocosGLWidget::applicationDidEnterBackground()
{
	// do nothing
}

void CocosGLWidget::applicationWillEnterForeground()
{
	// do nothing
}

void CocosGLWidget::setAnimationInterval(double)
{
	// do nothing
}

CocosGLWidget::CocosGLWidget(QWidget *parent)
	: QOpenGLWidget(parent)
	, CCApplication()
	, mMutex(QMutex::Recursive)
	, mRootNode(nullptr)
	, mMainNode(nullptr)
	, mScene(nullptr)
	, mMouseButtons(0)
	, mScale(100)
	, mBeginNoTouch(false)
	, mUseRenderBuffer(false)
{
	mEGLView = new CCEGLViewQt;

	connect(
		this, &QOpenGLWidget::aboutToResize, this,
		&CocosGLWidget::BeforeResize);

	mTimer = new QTimer(this);
	connect(
		mTimer, &QTimer::timeout,
		this, static_cast<void (QWidget::*)()>(&QWidget::update));
}

CocosGLWidget::~CocosGLWidget()
{
	QMutexLocker locker(&mMutex);

	mTimer->stop();

	makeCurrent();

	CC_SAFE_RELEASE_NULL(mMainNode);

	auto director = CCDirector::sharedDirector();
	director->end();
	director->mainLoop();

	delete mEGLView;
}

void CocosGLWidget::useRenderBuffer(bool use)
{
	if (use != mUseRenderBuffer)
	{
		mUseRenderBuffer = use;

		if (nullptr != mMainNode)
		{
			QMutexLocker locker(&mMutex);
			auto size = mEGLView->getFrameSize();
			makeCurrent();
			updateRenderBuffer(int(size.width), int(size.height));
		}
	}
}

void CocosGLWidget::SetScale(int value)
{
	if (mScale != value)
	{
		if (nullptr != mMainNode)
		{
			QMutexLocker locker(&mMutex);
			mMainNode->setScale(value / 100.f);
		} else
		{
			if (value < 10)
				value = 10;
			else
			if (value > 1600)
				value = 1600;
			mScale = value;

			emit ScaleChanged();
		}
	}
}

void CocosGLWidget::Synchronize(const std::function<void()> &safeCode)
{
	QMutexLocker locker(&mMutex);

	makeCurrent();
	safeCode();
}

class RenderBuffer : public CCRenderTexture
{
public:
	static RenderBuffer *create(int width, int height)
	{
		auto result = new RenderBuffer;
		bool ok = result->initWithWidthAndHeight(
				width,
				height,
				kTexture2DPixelFormat_RGBA8888,
				GL_DEPTH24_STENCIL8);
		Q_ASSERT(ok);
		Q_UNUSED(ok);
		result->setAutoDraw(true);
		result->setClearFlags(
			GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

		auto sprite = result->getSprite();
		auto size = sprite->getContentSize();

		sprite->setScale(1);
		sprite->setFlipY(true);
		sprite->setAnchorPoint(CCPointZero);
		sprite->setPosition(CCPointZero);

		result->setContentSize(size);
		result->setAnchorPoint(CCPointZero);
		return result;
	}

};

void CocosGLWidget::initializeGL()
{
	QOpenGLWidget::initializeGL();

	auto director = CCDirector::sharedDirector();

	if (false == mEGLView->InitGL())
		abort();

	director->setOpenGLView(mEGLView);

	mMainNode = new InternalMainNode(this);
	mMainNode->autorelease()->retain();
	mMainNode->scheduleOnce(
		schedule_selector(InternalMainNode::initialized), 0);

	mMainNode->setAnchorPoint(ccp(0.5f, 0.5f));
	mMainNode->setContentSize(CCPointZero);

	mScene = CCScene::create();

	director->runWithScene(mScene);
}

void CocosGLWidget::paintGL()
{
	QMutexLocker locker(&mMutex);
	CCDirector::sharedDirector()->mainLoop();
}

void CocosGLWidget::BeforeResize()
{
	QMutexLocker locker(&mMutex);

	mTimer->stop();
}

void CocosGLWidget::updateRenderBuffer(int width, int height)
{
	mMainNode->removeFromParentAndCleanup(false);

	mEGLView->setFrameSize(width, height);
	mEGLView->setDesignResolutionSize(width, height, kResolutionExactFit);

	mMainNode->setPosition(CCPoint(width * 0.5f, height * 0.5f));
	if (nullptr != mRootNode)
	{
		mRootNode->removeFromParent();
		CC_SAFE_RELEASE_NULL(mRootNode);
	}

	if (mUseRenderBuffer)
	{
		mRootNode = RenderBuffer::create(width, height);

		mRootNode->addChild(mMainNode);

		mScene->addChild(mRootNode);
	} else
	{
		mScene->addChild(mMainNode);
	}
}

void CocosGLWidget::resizeGL(int width, int height)
{
	QOpenGLWidget::resizeGL(width, height);

	updateRenderBuffer(width, height);

	emit VisibleFrameAdjusted();

	CCDirector::sharedDirector()->mainLoop();

	mTimer->start(20);
}

void CocosGLWidget::mousePressEvent(QMouseEvent *event)
{
	QMutexLocker locker(&mMutex);

	auto pos = event->localPos();

	int ids = (int) event->button();
	auto xs = float(pos.x());
	auto ys = float(pos.y());

	mMouseButtons |= ids;

	LOG_MOUSE_EVENT(
		"Mouse Down: x = %2.2f, y = %2.2f, button = %d", xs, ys, ids);

	makeCurrent();
	mEGLView->handleTouchesBegin(1, &ids, &xs, &ys);
}

void CocosGLWidget::mouseReleaseEvent(QMouseEvent *event)
{
	QMutexLocker locker(&mMutex);

	auto pos = event->localPos();

	int ids = (int) event->button();
	auto xs = float(pos.x());
	auto ys = float(pos.y());

	mMouseButtons &= ~ids;

	LOG_MOUSE_EVENT("Mouse Up: x = %2.2f, y = %2.2f, button = %d", xs, ys, ids);

	makeCurrent();
	mEGLView->handleTouchesEnd(1, &ids, &xs, &ys);
}

void CocosGLWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
	QMutexLocker locker(&mMutex);

	auto pos = event->localPos();

	int ids = (int) event->button();
	auto xs = float(pos.x());
	auto ys = float(pos.y());

	mMouseButtons |= ids;

	LOG_MOUSE_EVENT(
		"Mouse Double: x = %2.2f, y = %2.2f, button = %d", xs, ys, ids);

	ids |= CCEGLViewQt::DOUBLE_CLICK_FLAG;

	makeCurrent();
	mEGLView->handleTouchesBegin(1, &ids, &xs, &ys);
}

void CocosGLWidget::mouseMoveEvent(QMouseEvent *event)
{
	QMutexLocker locker(&mMutex);

	auto pos = event->localPos();
	auto pos_x = float(pos.x());
	auto pos_y = float(pos.y());

	std::vector<int> ids;
	std::vector<float> xs;
	std::vector<float> ys;

	auto buttons = event->buttons();

	if (0 != (buttons & Qt::LeftButton))
	{
		ids.push_back(Qt::LeftButton);
		xs.push_back(pos_x);
		ys.push_back(pos_y);

		LOG_MOUSE_EVENT(
			"Mouse Move: x = %2.2f, y = %2.2f, button = %d", pos_x,
			pos_y, Qt::LeftButton);
	}

	if (0 != (buttons & Qt::RightButton))
	{
		ids.push_back(Qt::RightButton);
		xs.push_back(pos_x);
		ys.push_back(pos_y);

		LOG_MOUSE_EVENT(
			"Mouse Move: x = %2.2f, y = %2.2f, button = %d", pos_x,
			pos_y, Qt::RightButton);
	}

	if (0 != (buttons & Qt::MiddleButton))
	{
		ids.push_back(Qt::MiddleButton);
		xs.push_back(pos_x);
		ys.push_back(pos_y);

		LOG_MOUSE_EVENT(
			"Mouse Move: x = %2.2f, y = %2.2f, button = %d", pos_x,
			pos_y, Qt::MiddleButton);
	}

	makeCurrent();

	if (ids.size() == 0)
	{
		ids.push_back(Qt::NoButton);
		xs.push_back(pos_x);
		ys.push_back(pos_y);

		if (!mBeginNoTouch)
		{
			mBeginNoTouch = true;
			mEGLView->handleTouchesBegin(
				ids.size(), (int *) ids.data(),
				(float *) xs.data(), (float *) ys.data());
		}
	}

	mEGLView->handleTouchesMove(
		ids.size(),
		(int *) ids.data(), (float *) xs.data(), (float *) ys.data());
}

void CocosGLWidget::wheelEvent(QWheelEvent *event)
{
	auto y = event->angleDelta().y();

	if (y != 0)
	{
		auto newScale = int((y > 0 ? 110.0 : 90.0) * mMainNode->getScale());
		int mod = newScale % 5;
		if (mod != 0)
		{
			newScale -= mod;
			if (y > 0)
				newScale += 5;
		}

		SetScale(newScale);
	}
}

void CocosGLWidget::enterEvent(QEvent *)
{
	CCLOG("Mouse Enter");
	emit MouseEntered();
}

void CocosGLWidget::leaveEvent(QEvent *)
{
	if (0 != mMouseButtons)
	{
		std::vector<int> ids;
		std::vector<float> xs;
		std::vector<float> ys;

		for (uint32_t i = 1; i != Qt::MaxMouseButton; i <<= 1)
		{
			if (0 != (mMouseButtons & i))
			{
				ids.push_back(i);
				xs.push_back(0);
				ys.push_back(0);
			}
		}

		makeCurrent();
		mEGLView->handleTouchesEnd(
			ids.size(), ids.data(), xs.data(),
			ys.data());
	}

	emit MouseLeft();
	CCLOG("Mouse Left");
}

void CocosGLWidget::keyPressEvent(QKeyEvent *event)
{
	QMutexLocker locker(&mMutex);

	makeCurrent();
	emit KeyDown(event);
}

void CocosGLWidget::keyReleaseEvent(QKeyEvent *event)
{
	QMutexLocker locker(&mMutex);

	makeCurrent();
	emit KeyUp(event);
}

InternalMainNode::InternalMainNode(CocosGLWidget *widget)
	: widget(widget)
{
}

void InternalMainNode::setScale(float scale)
{
	if (getScale() != scale)
	{
		int percentScale = qRound(scale * 100.f);

		if (percentScale < 10)
			percentScale = 10;
		else
		if (percentScale > 1600)
			percentScale = 1600;

		widget->mScale = percentScale;

		CCNode::setScale(percentScale / 100.f);

		emit widget->VisibleFrameAdjusted();
		emit widget->ScaleChanged();
	}
}

void InternalMainNode::initialized(float)
{
	CCNode::setScale(widget->mScale / 100.f);
	emit widget->Initialized();
}

CocosGLWidget *CocosGLWidget::instance()
{
	return dynamic_cast<CocosGLWidget *>(CCApplication::sharedApplication());
}
