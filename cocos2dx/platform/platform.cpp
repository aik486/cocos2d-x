/****************************************************************************
Copyright (c) 2010 cocos2d-x.org

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

#include "platform.h"

NS_CC_BEGIN

int CCTime::gettimeofdayCocos2d(struct cc_timeval *tp)
{
    return gettimeofday((struct timeval *)tp, NULL);   
}

int64_t CCTime::currentTimeMicros()
{
	struct cc_timeval now;

	gettimeofdayCocos2d(&now);

	return int64_t(now.tv_sec) * 1000000 + now.tv_usec;
}

double CCTime::currentTimeSeconds()
{
	struct cc_timeval now;

	gettimeofdayCocos2d(&now);

	return now.tv_sec + now.tv_usec / 1000000.0;
}

float CCTime::currentTimeSecondsF()
{
	struct cc_timeval now;

	gettimeofdayCocos2d(&now);

	return now.tv_sec + now.tv_usec / 1000000.f;
}

double CCTime::deltaTime(cc_timeval *start, cc_timeval *end)
{
    if (!start || !end)
    {
        return 0.0;
    }
    
    return (end->tv_sec - start->tv_sec) + (end->tv_usec - start->tv_usec) / 1000000.0;
}

float CCTime::deltaTimeF(cc_timeval *start, cc_timeval *end)
{
    if (!start || !end)
    {
        return 0.f;
    }
    
    return (end->tv_sec - start->tv_sec) + (end->tv_usec - start->tv_usec) / 1000000.f;
}

double CCTime::timersubCocos2d(struct cc_timeval *start, struct cc_timeval *end)
{  
    return deltaTime(start, end) * 1000.0;
}

NS_CC_END