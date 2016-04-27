#ifdef QT_WIN32
#	include "platform/third_party/win32/OGLES/GL/glew.h"
#	define __CCGL_H__
#endif

#include "cocos_warnings_off.h"
#include "CCEGLView.h"
#include "cocos2d.h"
#include "cocos_warnings_pop.h"

namespace cocos2d
{

	void CCEGLViewQt::end()
	{
		// TODO
	}

	bool CCEGLViewQt::isOpenGLReady()
	{
		return true;
	}
	void CCEGLViewQt::swapBuffers()
	{
	}

	void CCEGLViewQt::setIMEKeyboardState(bool)
	{
		// do nothing
	}

	void CCEGLViewQt::handleTouchesBegin(int num, int ids[], float xs[], float ys[])
	{
		CCSet set;

		for (int i = 0; i < num; i++)
		{
			int id = ids[i];

			auto it = touches.find(id);

			if (it == touches.end())
			{
				auto &touch = touches[id];

				touch = new CCTouch;

				SetTouchInfo(touch, id, xs[i], ys[i]);

				set.addObject(touch);
			}
		}

		if (set.count() > 0)
			m_pDelegate->touchesBegan(&set, nullptr);
	}

	void CCEGLViewQt::handleTouchesMove(int num, int ids[], float xs[], float ys[])
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

	void CCEGLViewQt::handleTouchesEnd(int num, int ids[], float xs[], float ys[])
	{
		CCSet set;

		FillTouchesEndOrCancel(set, num, ids, xs, ys);

		if (set.count() > 0)
			m_pDelegate->touchesEnded(&set, nullptr);
	}

	void CCEGLViewQt::handleTouchesCancel(int num, int ids[], float xs[], float ys[])
	{
		CCSet set;

		FillTouchesEndOrCancel(set, num, ids, xs, ys);

		if (set.count() > 0)
			m_pDelegate->touchesCancelled(&set, nullptr);
	}

	#ifdef QT_WIN32

	extern bool CC_DLL glew_dynamic_binding();

	#endif

	bool CCEGLViewQt::InitGL()
	{
	#ifdef QT_WIN32
		const GLubyte* glVersion = glGetString(GL_VERSION);
		CCLOG("OpenGL version = %s", glVersion);

		auto version_code = atof((const char*)glVersion);
		if (version_code < 1.5)
		{
			CCLog("OpenGL version must be higher than 1.5");
			return false;
		}

		GLenum init_result = glewInit();
		if (GLEW_OK != init_result)
		{
			CCLog("glewInit() failed");
			return false;
		}

		if (GLEW_ARB_vertex_shader && GLEW_ARB_fragment_shader)
		{
			CCLog("Ready for GLSL");
		}
		else
		{
			CCLog("Not totally ready :(");
		}

		if (glewIsSupported("GL_VERSION_2_0"))
		{
			CCLog("Ready for OpenGL 2.0");
		}
		else
		{
			CCLog("OpenGL 2.0 not supported");
		}

		if (false == glew_dynamic_binding())
		{
			CCLog("Glew dynamic bind failed");
			return false;
		}

		// Enable point size by default on windows.
		glEnable(GL_VERTEX_PROGRAM_POINT_SIZE);
	#endif
		return true;
	}

	void CCEGLViewQt::FillTouchesEndOrCancel(CCSet &set, int num, int ids[], float xs[], float ys[])
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

	void CCEGLViewQt::SetTouchInfo(CCTouch *touch, int id, float x, float y)
	{
		touch->setTouchInfo(id, (x - m_obViewPortRect.origin.x) / m_fScaleX,
							(y - m_obViewPortRect.origin.y) / m_fScaleY);
	}

	CCEGLViewQt::CCEGLViewQt()
	{
		CCEGLView **view_ptr;

	#ifdef QT_MAC
		view_ptr = &s_sharedView;
	#endif

	#ifdef QT_WIN32
		view_ptr = &s_pEglView;
	#endif

		CC_ASSERT(nullptr == *view_ptr);

		*view_ptr = this;
	}

	CCEGLViewQt::~CCEGLViewQt()
	{
		for (auto &touch : touches)
			touch.second->release();
	}

}
