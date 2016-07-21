#include "CocosGLWidget.h"

#include "cocos2dx_qt.h"

#include <QMouseEvent>

using namespace cocos2d;

#define LOG_MOUSE_EVENT(...) CCLOG(__VA_ARGS__)

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
	, mWidth(-1)
	, mHeight(-1)
	, mScale(1.0)
	, mMouseButtons(0)
	, mBeginNoTouch(false)
{
	mEGLView = new CCEGLViewQt;

	connect(this, SIGNAL(aboutToResize()), this, SLOT(BeforeResize()));

	mTimer = new QTimer(this);
	connect(mTimer, SIGNAL(timeout()), this, SLOT(update()));
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

void CocosGLWidget::Synchronize(const std::function<void ()> &safeCode)
{
	QMutexLocker locker(&mMutex);

	makeCurrent();
	safeCode();
}

class RenderBuffer : public CCRenderTexture
{
public:
	static RenderBuffer *create(int width, int height, double scale)
	{
		auto result = new RenderBuffer;
		bool ok = result->initWithWidthAndHeight(qFloor(width * scale),
												 qFloor(height * scale),
												 kTexture2DPixelFormat_RGBA8888);
		Q_ASSERT(ok);
		Q_UNUSED(ok);
		result->setAutoDraw(true);
		auto sprite = result->getSprite();
		auto size = sprite->getContentSize();
		sprite->setPosition(CCPointZero);
		sprite->setAnchorPoint(CCPoint(0.f, 1.f));
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

	class MainNode : public CCNode
	{
	public:
		MainNode(CocosGLWidget *widget)
			: widget(widget)
		{
		}

//		virtual void setScale(float scale) override
//		{
//			if (getScale() != scale)
//			{
//				CCNode::setScale(scale);

//				emit widget->VisibleFrameAdjusted();
//			}
//		}

		void initialized(float)
		{
			emit widget->Initialized();
		}

	private:
		CocosGLWidget *widget;
	};

	mMainNode = new MainNode(this);
	mMainNode->autorelease()->retain();
	mMainNode->scheduleOnce(schedule_selector(MainNode::initialized), 0);

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

void CocosGLWidget::updateRenderBuffer(int width, int height, double scale)
{
	if (mWidth == width && mHeight == height && mScale == scale)
		return;

	makeCurrent();

	mMainNode->removeFromParentAndCleanup(false);

	CCPoint position;

	if (nullptr != mRootNode)
	{
		position = mRootNode->convertToWorldSpace(mMainNode->getPosition());
		mRootNode->removeFromParent();
		mRootNode->release();
	} else
	{
		auto size = CCDirector::sharedDirector()->getVisibleSize();
		position.x = size.width * 0.5f;
		position.y = size.height * 0.5f;
	}

	mEGLView->setFrameSize(width, height);
	mEGLView->setDesignResolutionSize(width, height, kResolutionExactFit);

	mRootNode = RenderBuffer::create(width, height, scale);

	mMainNode->setPosition(mRootNode->convertToNodeSpace(position));
	mRootNode->addChild(mMainNode);

	mScene->addChild(mRootNode);

	mWidth = width;
	mHeight = height;
	mScale = scale;

	emit VisibleFrameAdjusted();
}

void CocosGLWidget::resizeGL(int width, int height)
{
	QOpenGLWidget::resizeGL(width, height);

	updateRenderBuffer(width, height, mScale);

	mTimer->start(20);
}

void CocosGLWidget::mousePressEvent(QMouseEvent *event)
{
	QMutexLocker locker(&mMutex);

	auto pos = event->localPos();

	int ids = (int) event->button();
	float xs = pos.x();
	float ys = pos.y();

	mMouseButtons |= ids;

	LOG_MOUSE_EVENT("Mouse Down: x = %2.2f, y = %2.2f, button = %d", xs, ys, ids);

	makeCurrent();
	mEGLView->handleTouchesBegin(1, &ids, &xs, &ys);
}

void CocosGLWidget::mouseReleaseEvent(QMouseEvent *event)
{
	QMutexLocker locker(&mMutex);

	auto pos = event->localPos();

	int ids = (int) event->button();
	float xs = pos.x();
	float ys = pos.y();

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
	float xs = pos.x();
	float ys = pos.y();

	mMouseButtons |= ids;

	LOG_MOUSE_EVENT("Mouse Double: x = %2.2f, y = %2.2f, button = %d", xs, ys, ids);

	ids |= CCEGLViewQt::DOUBLE_CLICK_FLAG;

	makeCurrent();
	mEGLView->handleTouchesBegin(1, &ids, &xs, &ys);
}

void CocosGLWidget::mouseMoveEvent(QMouseEvent *event)
{
	QMutexLocker locker(&mMutex);

	auto pos = event->localPos();
	float pos_x = pos.x();
	float pos_y = pos.y();

	std::vector<int> ids;
	std::vector<float> xs;
	std::vector<float> ys;

	auto buttons = event->buttons();

	if (0 != (buttons & Qt::LeftButton))
	{
		ids.push_back(Qt::LeftButton);
		xs.push_back(pos_x);
		ys.push_back(pos_y);

		LOG_MOUSE_EVENT("Mouse Move: x = %2.2f, y = %2.2f, button = %d", pos_x, pos_y, Qt::LeftButton);
	}

	if (0 != (buttons & Qt::RightButton))
	{
		ids.push_back(Qt::RightButton);
		xs.push_back(pos_x);
		ys.push_back(pos_y);

		LOG_MOUSE_EVENT("Mouse Move: x = %2.2f, y = %2.2f, button = %d", pos_x, pos_y, Qt::RightButton);
	}

	if (0 != (buttons & Qt::MiddleButton))
	{
		ids.push_back(Qt::MiddleButton);
		xs.push_back(pos_x);
		ys.push_back(pos_y);

		LOG_MOUSE_EVENT("Mouse Move: x = %2.2f, y = %2.2f, button = %d", pos_x, pos_y, Qt::MiddleButton);
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
			mEGLView->handleTouchesBegin(ids.size(), (int *) ids.data(), (float *) xs.data(), (float *) ys.data());
		}
	}

	mEGLView->handleTouchesMove(ids.size(), (int *) ids.data(), (float *) xs.data(), (float *) ys.data());
}

void CocosGLWidget::wheelEvent(QWheelEvent *event)
{
	auto y = event->angleDelta().y();

	if (y != 0)
	{
		QMutexLocker locker(&mMutex);

		int newScale = (y > 0 ? 110.0 : 90.0) * mScale;
		int mod = newScale % 5;
		if (mod != 0)
		{
			newScale -= mod;
			if (y > 0)
				newScale += 5;
		}

		if (newScale < 10)
			newScale = 10;
		else
		if (newScale > 1600)
			newScale = 1600;

		updateRenderBuffer(mWidth, mHeight, newScale / 100.0);
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
		mEGLView->handleTouchesEnd(ids.size(), ids.data(), xs.data(), ys.data());
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
