/****************************************************************************
Copyright (c) 2020 Alexandra Cherdantseva

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
#pragma once

#include "platform/CCGLView.h"

#include <map>

namespace cocos2d {

class CC_DLL GLViewImpl : public GLView
{
public:
	enum
	{
		DOUBLE_CLICK_FLAG = 0x10000000
	};
	
    virtual bool isOpenGLReady() override;
    virtual void end() override;
    virtual void swapBuffers() override;
    virtual void setIMEKeyboardState(bool) override;
    
    virtual void handleTouchesBegin(
            int num, intptr_t ids[], float xs[], float ys[]) override;
    virtual void handleTouchesMove(
            int num, intptr_t ids[], float xs[], float ys[]) override;
    virtual void handleTouchesMove(
            int num, intptr_t ids[], float xs[], float ys[], 
            float fs[], float ms[]) override;
    virtual void handleTouchesEnd(
            int num, intptr_t ids[], float xs[], float ys[]) override;
    virtual void handleTouchesCancel(
            int num, intptr_t ids[], float xs[], float ys[]) override;
    
private:
	void FillTouchesEndOrCancel(EventTouch::EventCode eventCode, 
		int num, intptr_t ids[], float xs[], float ys[]);
	void SetTouchInfo(Touch *touch, int id, float x, float y,
					  float force = 0.f, float maxForce = 0.f);

	std::map<intptr_t, Touch *> touches;
};

} // end of namespace   cocos2d
