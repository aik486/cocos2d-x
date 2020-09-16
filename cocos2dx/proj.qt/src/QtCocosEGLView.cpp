#include "QtCocosEGLView.h"

#include "cocos2dx_qt.h"

using namespace cocos2d;

void QtCocosEGLView::end()
{
	// do nothing
}

bool QtCocosEGLView::isOpenGLReady()
{
	return openglReady;
}

void QtCocosEGLView::swapBuffers() {}

void QtCocosEGLView::setIMEKeyboardState(bool)
{
	// do nothing
}

void QtCocosEGLView::handleTouchesBegin(
	int num, int ids[], float xs[], float ys[])
{
	CCSet set;

	for (int i = 0; i < num; i++)
	{
		int id = ids[i];

		int id2 = id & ~DOUBLE_CLICK_FLAG;

		auto it = touches.find(id2);

		if (it != touches.end())
		{
			CCTouch *touch = it->second;
			CCSet set2;

			set2.addObject(touch);

			touch->release();

			touches.erase(it);

			m_pDelegate->touchesEnded(&set2, nullptr);
		}

		it = touches.find(id);

		if (it == touches.end())
		{
			auto touch = new CCTouch;

			SetTouchInfo(touch, id, xs[i], ys[i]);

			set.addObject(touch);

			touches[id] = touch;
		}
	}

	if (set.count() > 0)
		m_pDelegate->touchesBegan(&set, nullptr);
}

void QtCocosEGLView::handleTouchesMove(
	int num, int ids[], float xs[], float ys[])
{
	CCSet set;

	for (int i = 0; i < num; i++)
	{
		int id = ids[i];

		auto it = touches.find(id);

		if (it == touches.end())
		{
			id |= DOUBLE_CLICK_FLAG;
			it = touches.find(id);
		}

		if (it != touches.end())
		{
			auto touch = it->second;

			SetTouchInfo(touch, id, xs[i], ys[i]);

			set.addObject(touch);
		} else
			CCLOGWARN("[Touch %d] Move without begin", ids[i]);
	}

	if (set.count() > 0)
		m_pDelegate->touchesMoved(&set, nullptr);
}

void QtCocosEGLView::handleTouchesEnd(
	int num, int ids[], float xs[], float ys[])
{
	CCSet set;

	FillTouchesEndOrCancel(set, num, ids, xs, ys);

	if (set.count() > 0)
		m_pDelegate->touchesEnded(&set, nullptr);
}

void QtCocosEGLView::handleTouchesCancel(
	int num, int ids[], float xs[], float ys[])
{
	CCSet set;

	FillTouchesEndOrCancel(set, num, ids, xs, ys);

	if (set.count() > 0)
		m_pDelegate->touchesCancelled(&set, nullptr);
}

bool QtCocosEGLView::InitGL()
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
	const GLubyte *glVersion = cocos2d::glGetString(GL_VERSION);
	CCLOG("OpenGL version = %s", glVersion);

	auto version_code = atof((const char *) glVersion);
	if (version_code < 1.5)
	{
		CCLog("OpenGL version must be higher than 1.5");
		return false;
	}

	if (!glew_dynamic_binding())
	{
		CCLog("OpenGL failed");
		return false;
	}

    // Enable point size by default on windows
#endif
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 || CC_TARGET_PLATFORM == CC_PLATFORM_LINUX
    cocos2d::glEnable(GL_VERTEX_PROGRAM_POINT_SIZE);
#endif
	openglReady = true;
	return true;
}

void QtCocosEGLView::FillTouchesEndOrCancel(
	CCSet &set, int num, int ids[], float xs[], float ys[])
{
	for (int i = 0; i < num; i++)
	{
		int id = ids[i];

		auto it = touches.find(id);
		if (it == touches.end())
		{
			id |= DOUBLE_CLICK_FLAG;
			it = touches.find(id);
		}

		if (it != touches.end())
		{
			auto touch = it->second;

			SetTouchInfo(touch, id, xs[i], ys[i]);

			set.addObject(touch);

			touch->release();

			touches.erase(it);
		} else
			CCLOGWARN("[Touch %d] End without begin", ids[i]);
	}
}

void QtCocosEGLView::SetTouchInfo(CCTouch *touch, int id, float x, float y)
{
	touch->setTouchInfo(id, (x - m_obViewPortRect.origin.x) / m_fScaleX,
		(y - m_obViewPortRect.origin.y) / m_fScaleY);
}

QtCocosEGLView::QtCocosEGLView()
	: openglReady(false)
{
	CCEGLView **view_ptr;

#if CC_TARGET_PLATFORM == CC_PLATFORM_MAC
	view_ptr = &s_sharedView;
#elif CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
	view_ptr = &s_pEglView;
#elif CC_TARGET_PLATFORM == CC_PLATFORM_EMSCRIPTEN
	view_ptr = &s_pInstance;
#elif CC_TARGET_PLATFORM == CC_PLATFORM_LINUX
    view_ptr = &s_pEglView;
#endif

	CC_ASSERT(nullptr == *view_ptr);

	*view_ptr = this;
}

QtCocosEGLView::~QtCocosEGLView()
{
	for (auto &touch : touches)
	{
		touch.second->release();
	}
}
