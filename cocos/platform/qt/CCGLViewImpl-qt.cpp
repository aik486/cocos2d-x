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
#include "CCGLViewImpl-qt.h"

#include "base/CCTouch.h"
#include "base/CCDirector.h"
#include "base/CCEventDispatcher.h"

#include <memory>

namespace cocos2d {

static std::unique_ptr<Touch> touchPool[10];
static int curTouch = 10;

static Touch *getFreeTouch()
{
    CC_ASSERT(curTouch > 0);
    auto &touch = touchPool[--curTouch];
    if (!touch) {
        return new Touch;
    }
    return touch.release();
}

static void releaseTouch(Touch *touch)
{
    touchPool[curTouch++].reset(touch);
}


bool GLViewImpl::isOpenGLReady()
{
    return true;
}

void GLViewImpl::end()
{
    //
}

void GLViewImpl::swapBuffers()
{
    //
}

void GLViewImpl::setIMEKeyboardState(bool)
{
    //
}

void GLViewImpl::handleTouchesBegin(int num, intptr_t ids[], float xs[], float ys[])
{
    EventTouch touchEvent;
    
    for (int i = 0; i < num; ++i)
    {
        auto id = ids[i];
        
        intptr_t id2 = id & ~DOUBLE_CLICK_FLAG;

        auto iter = touches.find(id2);
        if (iter != touches.end()) 
        {
            handleTouchesEnd(1, &id2, &xs[i], &ys[i]);
        }
        
        if (touches.count(id) == 0)
        {
            auto touch = getFreeTouch();
            SetTouchInfo(touch, id, xs[i], ys[i]);

            touchEvent._touches.push_back(touch);
            touches[id] = touch;
        }
    }

    if (touchEvent._touches.empty())
    {
        return;
    }
    
    touchEvent._eventCode = EventTouch::EventCode::BEGAN;
    auto dispatcher = Director::getInstance()->getEventDispatcher();
    dispatcher->dispatchEvent(&touchEvent);
}

void GLViewImpl::handleTouchesMove(
        int num, intptr_t ids[], float xs[], float ys[])
{
    GLView::handleTouchesMove(num, ids, xs, ys);
}

void GLViewImpl::handleTouchesMove(
        int num, intptr_t ids[], float xs[], float ys[], 
        float fs[], float ms[])
{
    EventTouch touchEvent;
    
    for (int i = 0; i < num; ++i)
    {
        auto id = ids[i];

        auto it = touches.find(id);
        if (it == touches.end())
        {
            id |= DOUBLE_CLICK_FLAG;
            it = touches.find(id);
        }
        
        if (it != touches.end())
        {
            auto force = fs ? fs[i] : 0.0f;
            auto maxForce = ms ? ms[i] : 0.0f;
            auto touch = it->second;

            SetTouchInfo(touch, id, xs[i], ys[i], force, maxForce);

            touchEvent._touches.push_back(touch);
        }
    }

    if (touchEvent._touches.empty())
    {
        return;
    }
    
    touchEvent._eventCode = EventTouch::EventCode::MOVED;
    auto dispatcher = Director::getInstance()->getEventDispatcher();
    dispatcher->dispatchEvent(&touchEvent);
}

void GLViewImpl::handleTouchesEnd(
        int num, intptr_t ids[], float xs[], float ys[])
{
    FillTouchesEndOrCancel(EventTouch::EventCode::ENDED, num, ids, xs, ys);
}

void GLViewImpl::handleTouchesCancel(
        int num, intptr_t ids[], float xs[], float ys[])
{
    FillTouchesEndOrCancel(EventTouch::EventCode::CANCELLED, num, ids, xs, ys);
}

void GLViewImpl::FillTouchesEndOrCancel(EventTouch::EventCode eventCode, int num, intptr_t ids[], float xs[], float ys[])
{
    EventTouch touchEvent;
    
    for (int i = 0; i < num; ++i)
    {
        auto id = ids[i];

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

			touchEvent._touches.push_back(touch);

			touch->release();

			touches.erase(it);
		}
    }

    if (touchEvent._touches.empty())
    {
        return;
    }
    
    touchEvent._eventCode = eventCode;
    auto dispatcher = Director::getInstance()->getEventDispatcher();
    dispatcher->dispatchEvent(&touchEvent);
    
    for (auto& touch : touchEvent._touches)
    {
        releaseTouch(touch);
    }
}

void GLViewImpl::SetTouchInfo(
		Touch *touch, int id, float x, float y, float force, float maxForce)
{
	touch->setTouchInfo(
		id, (x - _viewPortRect.origin.x) / _scaleX,
		(y - _viewPortRect.origin.y) / _scaleY, force, maxForce);
}


}
