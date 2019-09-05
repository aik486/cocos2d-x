#pragma once

#include "cocos_warnings_off.h"
#include "CCEGLView.h"
#include "cocos_warnings_pop.h"

#include <map>

namespace cocos2d
{
class EGLTouchDelegate;
class CCTouch;
}

class QtCocosEGLView : public cocos2d::CCEGLView
{
public:
	QtCocosEGLView();
	virtual ~QtCocosEGLView() override;

	virtual void end() override;
	virtual bool isOpenGLReady() override;
	virtual void swapBuffers() override;
	virtual void setIMEKeyboardState(bool) override;

	virtual void handleTouchesBegin(
		int num, int ids[], float xs[], float ys[]) override;
	virtual void handleTouchesMove(
		int num, int ids[], float xs[], float ys[]) override;
	virtual void handleTouchesEnd(
		int num, int ids[], float xs[], float ys[]) override;
	virtual void handleTouchesCancel(
		int num, int ids[], float xs[], float ys[]) override;

	bool InitGL();

	enum
	{
		DOUBLE_CLICK_FLAG = 0x10000000
	};

private:
	void FillTouchesEndOrCancel(
		cocos2d::CCSet &set, int num, int ids[], float xs[], float ys[]);
	void SetTouchInfo(cocos2d::CCTouch *touch, int id, float x, float y);

	std::map<int, cocos2d::CCTouch *> touches;
	bool openglReady;
};
