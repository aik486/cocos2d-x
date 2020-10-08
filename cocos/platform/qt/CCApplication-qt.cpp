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

#include "CCApplication-qt.h"

#include <algorithm>
#include "platform/CCFileUtils.h"
#include "base/ccUtils.h"

#include <QApplication>
#include <QLocale>
#include <QDesktopServices>
#include <QUrl>

NS_CC_BEGIN

Application* Application::sm_pSharedApplication = nullptr;

Application::Application()
    : _currentLanguageCode(QLocale().name().toStdString())
{
    CCASSERT(! sm_pSharedApplication, "sm_pSharedApplication already exist");
    sm_pSharedApplication = this;
    
}

Application::~Application()
{
    CCASSERT(this == sm_pSharedApplication, "sm_pSharedApplication != this");
    sm_pSharedApplication = 0;
}


void Application::setAnimationInterval(float interval)
{
    _animationInterval = interval;
}

Application::Platform Application::getTargetPlatform()
{
    switch (CC_TARGET_PLATFORM)
    {
        case CC_PLATFORM_MAC:
            return Platform::OS_MAC;
        case CC_PLATFORM_WIN32:
            return Platform::OS_WINDOWS;
        case CC_PLATFORM_LINUX:
            return Platform::OS_LINUX;
        case CC_PLATFORM_EMSCRIPTEN:
            return Platform::OS_EMSCRIPTEN;
    }
    
    return Platform(-1);
}

std::string Application::getVersion()
{
    return QApplication::applicationVersion().toStdString();
}

/////////////////////////////////////////////////////////////////////////////////////////////////
// static member function
//////////////////////////////////////////////////////////////////////////////////////////////////

Application* Application::getInstance()
{
    return sm_pSharedApplication;
}

const char * Application::getCurrentLanguageCode()
{
    return _currentLanguageCode.c_str();
}

LanguageType Application::getCurrentLanguage()
{
    return utils::getLanguageTypeByISO2(_currentLanguageCode.c_str());
}

bool Application::openURL(const std::string &url)
{
    return QDesktopServices::openUrl(QUrl(QString::fromStdString(url)));
}

NS_CC_END
