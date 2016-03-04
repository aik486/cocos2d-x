#include "CocosGLWidget.h"

#include "cocos2dx_qt.h"

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
	, mutex(QMutex::Recursive)
	, main_node(nullptr)
	, mouse_buttons(0)
	, begin_no_touch(false)
{
	egl_view = new CCEGLViewQt;

	connect(this, SIGNAL(aboutToResize()), this, SLOT(BeforeResize()));

	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(update()));
}

CocosGLWidget::~CocosGLWidget()
{
	QMutexLocker locker(&mutex);

	timer->stop();

	makeCurrent();

	CC_SAFE_RELEASE_NULL(main_node);

	auto director = CCDirector::sharedDirector();
	director->end();
	director->mainLoop();

	delete egl_view;
}

void CocosGLWidget::Synchronize(const std::function<void ()> &safe_code)
{
	QMutexLocker locker(&mutex);

	makeCurrent();
	safe_code();
}

void CocosGLWidget::initializeGL()
{
	QOpenGLWidget::initializeGL();

	auto director = CCDirector::sharedDirector();

	if (false == egl_view->InitGL())
		abort();

	director->setOpenGLView(egl_view);

	class MainNode : public CCNode
	{
	public:
		MainNode(CocosGLWidget *widget)
			: widget(widget)
		{
		}

		virtual void setScale(float scale) override
		{
			if (getScale() != scale)
			{
				CCNode::setScale(scale);

				emit widget->VisibleFrameAdjusted();
			}
		}

		void initialized(float)
		{
			emit widget->Initialized();
		}

	private:
		CocosGLWidget *widget;
	};

	main_node = new MainNode(this);
	main_node->autorelease()->retain();
	main_node->scheduleOnce(schedule_selector(MainNode::initialized), 0);

	main_node->setAnchorPoint(ccp(0.5f, 0.5f));
	main_node->setContentSize(CCPointZero);

	auto scene = CCScene::create();

	scene->addChild(main_node);

	director->runWithScene(scene);
}

void CocosGLWidget::paintGL()
{
	QMutexLocker locker(&mutex);
	CCDirector::sharedDirector()->mainLoop();
}

void CocosGLWidget::BeforeResize()
{
	QMutexLocker locker(&mutex);

	timer->stop();
}

void CocosGLWidget::resizeGL(int width, int height)
{
	QOpenGLWidget::resizeGL(width, height);	

	egl_view->setFrameSize(width, height);
	egl_view->setDesignResolutionSize(width, height, kResolutionExactFit);

	auto director = CCDirector::sharedDirector();

	auto size = director->getVisibleSize();

	main_node->setPosition(size.width * 0.5f, size.height * 0.5f);

	emit VisibleFrameAdjusted();

	timer->start(0);
}

void CocosGLWidget::mousePressEvent(QMouseEvent *event)
{
	QMutexLocker locker(&mutex);

	auto pos = event->localPos();

	int ids = (int) event->button();
	float xs = pos.x();
	float ys = pos.y();

	mouse_buttons |= ids;

	LOG_MOUSE_EVENT("Mouse Down: x = %2.2f, y = %2.2f, button = %d", xs, ys, ids);

	makeCurrent();
	egl_view->handleTouchesBegin(1, &ids, &xs, &ys);
}

void CocosGLWidget::mouseReleaseEvent(QMouseEvent *event)
{
	QMutexLocker locker(&mutex);

	auto pos = event->localPos();

	int ids = (int) event->button();
	float xs = pos.x();
	float ys = pos.y();

	mouse_buttons &= ~ids;

	LOG_MOUSE_EVENT("Mouse Up: x = %2.2f, y = %2.2f, button = %d", xs, ys, ids);

	makeCurrent();
	egl_view->handleTouchesEnd(1, &ids, &xs, &ys);
}

void CocosGLWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
	QMutexLocker locker(&mutex);

	auto pos = event->localPos();

	int ids = (int) event->button();
	float xs = pos.x();
	float ys = pos.y();

	mouse_buttons |= ids;

	LOG_MOUSE_EVENT("Mouse Double: x = %2.2f, y = %2.2f, button = %d", xs, ys, ids);

	ids |= CCEGLViewQt::DOUBLE_CLICK_FLAG;

	makeCurrent();
	egl_view->handleTouchesBegin(1, &ids, &xs, &ys);
}

void CocosGLWidget::mouseMoveEvent(QMouseEvent *event)
{
	QMutexLocker locker(&mutex);

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

		if (!begin_no_touch)
		{
			begin_no_touch = true;
			egl_view->handleTouchesBegin(ids.size(), (int *) ids.data(), (float *) xs.data(), (float *) ys.data());
		}
	}

	egl_view->handleTouchesMove(ids.size(), (int *) ids.data(), (float *) xs.data(), (float *) ys.data());
}

void CocosGLWidget::wheelEvent(QWheelEvent *event)
{
	auto y = event->angleDelta().y();

	if (y != 0)
	{
		QMutexLocker locker(&mutex);

		int new_scale = (y > 0 ? 110.f : 90.f) * main_node->getScale();
		int mod = new_scale % 5;
		if (mod != 0)
		{
			new_scale -= mod;
			if (y > 0)
				new_scale += 5;
		}

		if (new_scale < 10)
			new_scale = 10;
		else
		if (new_scale > 1600)
			new_scale = 1600;

		main_node->setScale(new_scale / 100.f);
	}
}

void CocosGLWidget::enterEvent(QEvent *)
{
	CCLOG("Mouse Enter");
	emit MouseEntered();
}

void CocosGLWidget::leaveEvent(QEvent *)
{
	if (0 != mouse_buttons)
	{
		std::vector<int> ids;
		std::vector<float> xs;
		std::vector<float> ys;

		for (uint32_t i = 1; i != Qt::MaxMouseButton; i <<= 1)
		{
			if (0 != (mouse_buttons & i))
			{
				ids.push_back(i);
				xs.push_back(0);
				ys.push_back(0);
			}
		}

		makeCurrent();
		egl_view->handleTouchesEnd(ids.size(), ids.data(), xs.data(), ys.data());
	}

	emit MouseLeft();
	CCLOG("Mouse Left");
}

void CocosGLWidget::keyPressEvent(QKeyEvent *event)
{
	QMutexLocker locker(&mutex);

	makeCurrent();
	emit KeyDown(event);
}

void CocosGLWidget::keyReleaseEvent(QKeyEvent *event)
{
	QMutexLocker locker(&mutex);

	makeCurrent();
	emit KeyUp(event);
}
