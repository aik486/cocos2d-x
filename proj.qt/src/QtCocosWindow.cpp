#include "QtCocosWindow.h"

#include "QtCocosHelper.h"
#include "QtCocosContext.h"

#include "2d/CCNode.h"
#include "2d/CCClippingNode.h"
#include "2d/CCScene.h"
#include "2d/CCCamera.h"
#include "base/CCDirector.h"
#include "platform/qt/CCGLViewImpl-qt.h"

#include <QFocusEvent>
#include <QDebug>
#include <QWidget>
#include <QApplication>
#include <QOpenGLContext>
#include <QOpenGLFunctions>
#include <QScreen>

using namespace cocos2d;

class QtCocosWindow::InternalMainNode : public Node
{
public:
	InternalMainNode(QtCocosWindow *window);

	virtual void setScale(float scale) override;

	void initialized(float);

private:
	QtCocosWindow *window;
};

QtCocosWindow::QtCocosWindow()
	: QOpenGLWindow(NoPartialUpdate)
	, Application()
	, mEGLView(new GLViewImpl)
	, mMainNode(nullptr)
	, mScene(nullptr)
	, mScale(100)
	, mMouseButtons(0)
	, mState(ANIMATING)
	, mBgColor(Qt::transparent)
	, mMasterWidget(nullptr)
	, mHasFocus(false)
	, mEnabled(true)
	, mRunning(false)
	, mInitialized(false)
	, mFixedWheelScale(false)
{
	auto surfaceFormat = format();
	surfaceFormat.setStencilBufferSize(8);
	surfaceFormat.setRenderableType(QSurfaceFormat::OpenGL);
#ifdef Q_OS_MACOS
	surfaceFormat.setProfile(QSurfaceFormat::CompatibilityProfile);
#endif
	setFormat(surfaceFormat);

	connect(qApp, &QApplication::primaryScreenChanged, this,
		&QtCocosWindow::fixScale);
	QtCocosContext::setBackgroundColorSetter(
		[this](const QColor &color) { setBackgroundColor(color); });
}

QtCocosWindow::~QtCocosWindow()
{
	if (mScene)
	{
		makeCurrent();

		CC_SAFE_RELEASE_NULL(mMainNode);
		CC_SAFE_RELEASE_NULL(mScene);
		auto director = Director::getInstance();
		director->end();
		director->mainLoop();
	}

	QtCocosContext::setContextSetter(nullptr);
	QtCocosContext::setBackgroundColorSetter(nullptr);
	delete mEGLView;
}

QWidget *QtCocosWindow::createWidget(QWidget *parent)
{
	Q_ASSERT(sm_pSharedApplication == nullptr);

	auto window = new QtCocosWindow;

	return window->makeContainerWidget(parent);
}

QWidget *QtCocosWindow::makeContainerWidget(QWidget *parent)
{
	auto result = QWidget::createWindowContainer(this, parent);

	mMasterWidget = result;

	return result;
}

bool QtCocosWindow::isAnimating() const
{
	return 0 != (mState & ANIMATING);
}

void QtCocosWindow::animate(bool yes)
{
	if (isAnimating() != yes)
	{
		if (yes)
		{
			mState |= ANIMATING;
		} else
		{
			mState &= ~ANIMATING;
		}

		updateAnimationState(true);
	}
}

void QtCocosWindow::setScale(int value)
{
	if (value < 5)
		value = 5;
	else if (value > 1600)
		value = 1600;
	if (mScale == value)
		return;

	mScale = value;
	if (nullptr != mMainNode)
	{
		mMainNode->setScale(getScaleForMainNode());
	} else
	{
		emit ScaleChanged();
	}
}

Scene *QtCocosWindow::scene() const
{
	return mScene;
}

QtCocosWindow *QtCocosWindow::instance()
{
	return dynamic_cast<QtCocosWindow *>(sm_pSharedApplication);
}

QColor QtCocosWindow::backgroundColor() const
{
	return mBgColor;
}

void QtCocosWindow::setBackgroundColor(const QColor &color)
{
	mBgColor = color;
	auto ccColor = qColorToCcColor4F(color);
	if (mScene)
	{
		Director::getInstance()->setClearColor(ccColor);
	}
}

bool QtCocosWindow::applicationDidFinishLaunching()
{
	return nullptr != mScene;
}

void QtCocosWindow::applicationDidEnterBackground()
{
	if (!mRunning)
		return;

	mRunning = false;

	QObject::disconnect(this, &QOpenGLWindow::frameSwapped, this,
		static_cast<void (QPaintDeviceWindow::*)()>(
			&QPaintDeviceWindow::update));
}

void QtCocosWindow::applicationWillEnterForeground()
{
	if (mRunning)
		return;

	mRunning = true;

	QObject::connect(this, &QOpenGLWindow::frameSwapped, this,
		static_cast<void (QPaintDeviceWindow::*)()>(
			&QPaintDeviceWindow::update));

	update();
}

void QtCocosWindow::setAnimationInterval(float)
{
	// do nothing
}

bool QtCocosWindow::event(QEvent *e)
{
	switch (e->type())
	{
		case QEvent::ContextMenu:
			break;

		case QEvent::Enter:
			emit MouseEnter();
			break;

		case QEvent::Leave:
		{
			emit MouseLeave();
			break;
		}

		default:
			break;
	}

	return QOpenGLWindow::event(e);
}

void QtCocosWindow::initializeGL()
{
	QOpenGLWindow::initializeGL();

	mEGLView->setOpenGLReady(true);
	QtCocosContext::setContextSetter([this]() { makeCurrent(); });

	auto director = Director::getInstance();

	director->setOpenGLView(mEGLView);

	mMainNode = new InternalMainNode(this);
	mMainNode->autorelease()->retain();
	mMainNode->setAnchorPoint(Point::ANCHOR_MIDDLE);
	mMainNode->setContentSize(Size::ZERO);

	updateMainNodeScale();

	mScene = Scene::create();
	mScene->retain();
	mScene->addChild(mMainNode);

	director->setClearColor(qColorToCcColor4F(mBgColor));
	director->runWithScene(mScene);

	mInitialized = true;
	emit Initialized();
}

void QtCocosWindow::resizeGL(int w, int h)
{
	QOpenGLWindow::resizeGL(w, h);
	const qreal pixelRatio = devicePixelRatio();

	Size scaledSize(w * pixelRatio, h * pixelRatio);

	makeCurrent();
	mEGLView->setFrameSize(scaledSize.width, scaledSize.height);
	mEGLView->setDesignResolutionSize(
		scaledSize.width, scaledSize.height, ResolutionPolicy::NO_BORDER);

	mScene->setContentSize(scaledSize);
	mScene->getDefaultCamera()->initDefault();
	mMainNode->setPosition(
		Point(scaledSize.width * 0.5f, scaledSize.height * 0.5f));

	updateMainNodeScale();

	emit VisibleFrameAdjusted();

	makeCurrent();
	Director::getInstance()->mainLoop();
}

void QtCocosWindow::paintGL()
{
	Director::getInstance()->mainLoop();
}

void QtCocosWindow::focusInEvent(QFocusEvent *event)
{
	switch (event->reason())
	{
		case Qt::MouseFocusReason:
		case Qt::TabFocusReason:
		case Qt::BacktabFocusReason:
		case Qt::OtherFocusReason:
			emit FocusIn();
			break;

		default:
			break;
	}

	mHasFocus = true;
}

void QtCocosWindow::focusOutEvent(QFocusEvent *event)
{
	mHasFocus = false;

	if (0 != mMouseButtons)
	{
		std::vector<intptr_t> ids;
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

		mMouseButtons = 0;
		makeCurrent();

		mEGLView->handleTouchesCancel(
			int(ids.size()), ids.data(), xs.data(), ys.data());
	}

	switch (event->reason())
	{
		case Qt::MouseFocusReason:
		case Qt::TabFocusReason:
		case Qt::BacktabFocusReason:
		case Qt::OtherFocusReason:
			emit FocusOut();
			break;

		default:
			break;
	}
}

void QtCocosWindow::mousePressEvent(QMouseEvent *event)
{
	if (!mEnabled)
	{
		ignoredMouseEvent(event);
		return;
	}

	auto pos = event->localPos();

	if (mMasterWidget && isContextMenuEvent(event))
	{
		emit mMasterWidget->customContextMenuRequested(
			QPoint(int(pos.x()), int(pos.y())));
	}

	if (ignoredMouseEvent(event))
		return;

	const qreal pixelRatio = devicePixelRatio();
	Point scaledPos(pos.x() * pixelRatio, pos.y() * pixelRatio);

	auto ids = intptr_t(event->button());

	mMouseButtons |= ids;

	makeCurrent();
	mEGLView->handleTouchesBegin(1, &ids, &scaledPos.x, &scaledPos.y);

	emit MousePressed(event);
}

void QtCocosWindow::mouseReleaseEvent(QMouseEvent *event)
{
	if (ignoredMouseEvent(event))
		return;

	if (!mEnabled)
		return;

	auto pos = event->localPos();
	const qreal pixelRatio = devicePixelRatio();
	Point scaledPos(pos.x() * pixelRatio, pos.y() * pixelRatio);

	auto ids = intptr_t(event->button());

	mMouseButtons &= ~ids;

	makeCurrent();
	mEGLView->handleTouchesEnd(1, &ids, &scaledPos.x, &scaledPos.y);

	emit MouseReleased(event);
}

void QtCocosWindow::mouseDoubleClickEvent(QMouseEvent *event)
{
	if (!mEnabled)
		return;

#ifndef Q_OS_WASM
	if (!mHasFocus)
	{
		event->ignore();
		return;
	}
#endif

	auto pos = event->localPos();

	intptr_t ids = (int) event->button();
	const qreal pixelRatio = devicePixelRatio();
	Point scaledPos(pos.x() * pixelRatio, pos.y() * pixelRatio);

	mMouseButtons |= ids;

	ids |= GLViewImpl::DOUBLE_CLICK_FLAG;

	makeCurrent();
	mEGLView->handleTouchesBegin(1, &ids, &scaledPos.x, &scaledPos.y);
}

void QtCocosWindow::mouseMoveEvent(QMouseEvent *event)
{
	if (!mEnabled)
		return;

	auto buttons = event->buttons();

#ifndef Q_OS_WASM
	if (!mHasFocus && buttons != Qt::NoButton)
	{
		event->ignore();
		return;
	}
#endif

	auto pos = event->localPos();
	const qreal pixelRatio = devicePixelRatio();
	Point scaledPos(pos.x() * pixelRatio, pos.y() * pixelRatio);

	std::vector<intptr_t> ids;
	std::vector<float> xs;
	std::vector<float> ys;

	makeCurrent();

	if (buttons == Qt::NoButton)
	{
		ids.push_back(Qt::NoButton);
		xs.push_back(scaledPos.x);
		ys.push_back(scaledPos.y);

		if (0 == (mState & BEGIN_NO_TOUCH))
		{
			mState |= BEGIN_NO_TOUCH;
			mEGLView->handleTouchesBegin(
				int(ids.size()), ids.data(), xs.data(), ys.data());
		}
	} else
	{
		if (0 != (buttons & Qt::LeftButton))
		{
			ids.push_back(Qt::LeftButton);
			xs.push_back(scaledPos.x);
			ys.push_back(scaledPos.y);
		}

		if (0 != (buttons & Qt::RightButton))
		{
			ids.push_back(Qt::RightButton);
			xs.push_back(scaledPos.x);
			ys.push_back(scaledPos.y);
		}

		if (0 != (buttons & Qt::MiddleButton))
		{
			ids.push_back(Qt::MiddleButton);
			xs.push_back(scaledPos.x);
			ys.push_back(scaledPos.y);
		}
	}

	mEGLView->handleTouchesMove(
		int(ids.size()), ids.data(), xs.data(), ys.data());

	emit MouseMoved(event);
}

void QtCocosWindow::wheelEvent(QWheelEvent *event)
{
	if (!mEnabled)
		return;

	auto y = event->angleDelta().y();

	if (y == 0)
		return;

	int newScale = mScale;
	if (mFixedWheelScale)
	{
		static const int SCALE_TABLE[] = { 5, 12, 18, 25, 33, 50, 67, 100, 150,
			200, 300, 400, 550, 800, 1200, 1600 };

		int prev = 0;
		for (int cur : SCALE_TABLE)
		{
			if (newScale >= prev && newScale <= cur)
			{
				if (y > 0)
				{
					if (newScale == cur)
					{
						continue;
					}
					newScale = cur;
				} else
				{
					newScale = prev;
				}
				break;
			}
			prev = cur;
		}
	} else if (newScale <= 5 && y > 0)
	{
		newScale = 10;
	} else if ((y < 0 && newScale > 100 && newScale <= 110) ||
		(y > 0 && newScale >= 90 && newScale < 100))
	{
		newScale = 100;
	} else
	{
		newScale = int((y > 0 ? 110.0 : 90.0) * (newScale / 100.0));
		int mod = newScale % 5;

		if (mod != 0)
		{
			newScale -= mod;

			if (y > 0)
				newScale += 5;
		}
	}
	setScale(newScale);
}

void QtCocosWindow::showEvent(QShowEvent *)
{
#ifdef Q_OS_MACOS
	// Dirty hack for a MacOS bug when exposeEvent is not executed
	// while showing window after hide
	fixScale();
#endif
}

void QtCocosWindow::exposeEvent(QExposeEvent *)
{
	makeCurrent();

	updateAnimationState(false);

	if (isExposed())
	{
		if (mMainNode)
		{
			mMainNode->setScale(getScaleForMainNode());
		}
		applicationWillEnterForeground();
	} else
		applicationDidEnterBackground();
}

void QtCocosWindow::keyPressEvent(QKeyEvent *event)
{
	if (!mEnabled)
		return;

	makeCurrent();
	emit KeyDown(event);
}

void QtCocosWindow::keyReleaseEvent(QKeyEvent *event)
{
	if (!mEnabled)
		return;

	makeCurrent();
	emit KeyUp(event);
}

bool QtCocosWindow::ignoredMouseEvent(QMouseEvent *event)
{
#ifndef Q_OS_WASM
	if (!mHasFocus)
	{
		if (mMasterWidget)
		{
			mMasterWidget->clearFocus();
			mMasterWidget->activateWindow();
			mMasterWidget->setFocus(Qt::MouseFocusReason);
		}

		event->ignore();

		return true;
	}
#endif
	return false;
}

void QtCocosWindow::updateAnimationState(bool force)
{
	bool exposed = isExposed();
	if (force || exposed != (0 != (mState & EXPOSED)))
	{
		if (exposed)
		{
			mState |= EXPOSED;
		} else
		{
			mState &= ~EXPOSED;
		}

		if (mScene)
		{
			auto director = Director::getInstance();
			if (exposed && isAnimating())
			{
				director->resume();
				director->startAnimation();
			} else
			{
				director->stopAnimation();
				director->pause();
			}
		}
	}
}

float QtCocosWindow::getScaleForMainNode() const
{
	return float((mScale / 100.0) * devicePixelRatio());
}

void QtCocosWindow::updateMainNodeScale()
{
	if (mMainNode)
	{
		mMainNode->Node::setScale(getScaleForMainNode());
	}
}

bool QtCocosWindow::isContextMenuEvent(QMouseEvent *event)
{
	auto buttons = event->buttons();
	auto button = event->button();
	auto modifiers = event->modifiers();

	if (buttons != Qt::RightButton || button != Qt::RightButton)
		return false;

#ifdef Q_OS_MACOS
	if (modifiers == Qt::MetaModifier)
		return true;
#endif

	return modifiers == Qt::NoModifier;
}

void QtCocosWindow::fixScale()
{
	// Dirty hack to fix scale after move from retina display or expose event bug
	if (mMasterWidget)
	{
		auto oldSize = size();
		resize(1, 1);
		mMasterWidget->resize(oldSize.width() + 1, oldSize.height() + 1);
	}
}

QtCocosWindow::InternalMainNode::InternalMainNode(QtCocosWindow *window)
	: window(window)
{
}

void QtCocosWindow::InternalMainNode::setScale(float scale)
{
	if (_scaleX != scale || _scaleY != scale || _scaleZ != scale)
	{
		const qreal pixelRatio = window->devicePixelRatio();
		int percentScale = qRound((scale / pixelRatio) * 100.0);

		if (percentScale < 5)
			percentScale = 5;
		else if (percentScale > 1600)
			percentScale = 1600;

		window->mScale = percentScale;
		window->updateMainNodeScale();

		emit window->VisibleFrameAdjusted();
		emit window->ScaleChanged();
	}
}
