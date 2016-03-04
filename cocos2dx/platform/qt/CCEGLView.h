#pragma once

#ifdef QT_MAC
#include "platform/mac/CCEGLView.h"
#endif

#ifdef QT_WIN32
#include "CCGL.h"
#include "platform/win32/CCEGLView.h"
#endif

#include <map>

namespace cocos2d
{
	class EGLTouchDelegate;
	class CCTouch;

	class CCEGLViewQt : public CCEGLView
	{
	public:
		CCEGLViewQt();
		virtual ~CCEGLViewQt();

		virtual void end() override;
		virtual bool isOpenGLReady() override;
		virtual void swapBuffers() override;
		virtual void setIMEKeyboardState(bool) override;

		virtual void handleTouchesBegin(int num, int ids[], float xs[], float ys[]) override;
		virtual void handleTouchesMove(int num, int ids[], float xs[], float ys[]) override;
		virtual void handleTouchesEnd(int num, int ids[], float xs[], float ys[]) override;
		virtual void handleTouchesCancel(int num, int ids[], float xs[], float ys[]) override;

		bool InitGL();

		enum
		{
			DOUBLE_CLICK_FLAG = 0x10000000
		};

	private:
		void FillTouchesEndOrCancel(CCSet &set, int num, int ids[], float xs[], float ys[]);
		void SetTouchInfo(CCTouch *touch, int id, float x, float y);

		std::map<int, CCTouch *> touches;
	};

}
