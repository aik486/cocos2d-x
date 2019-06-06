/****************************************************************************
 Copyright (c) 2010-2012 cocos2d-x.org
 
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

#include "CCScriptSupport.h"
#include "CCScheduler.h"

bool CC_DLL cc_assert_script_compatible(const char *msg)
{
    cocos2d::CCScriptEngineProtocol* pEngine = cocos2d::CCScriptEngineManager::sharedManager()->getScriptEngine();
    if (pEngine && pEngine->handleAssert(msg))
    {
        return true;
    }
    return false;
}

NS_CC_BEGIN

 #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
// #pragma mark -
// #pragma mark CCScriptHandlerEntry
#endif

CCScriptHandlerEntry* CCScriptHandlerEntry::create(int64_t nHandler)
{
    CCScriptHandlerEntry* entry = new CCScriptHandlerEntry(nHandler);
    entry->autorelease();
    return entry;
}

CCScriptHandlerEntry::~CCScriptHandlerEntry(void)
{
	if (m_nHandler != 0)
	{
        CCScriptEngineManager::sharedManager()->getScriptEngine()->removeScriptHandler(m_nHandler);
        m_nHandler = 0;
    }
}

CCScriptHandlerEntry::CCScriptHandlerEntry(int64_t nHandler)
    : m_nHandler(nHandler)
{
    static unsigned newEntryId = 0;
    newEntryId++;
    m_nEntryId = newEntryId;
}

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
// #pragma mark -
// #pragma mark CCSchedulerScriptHandlerEntry
#endif

CCSchedulerScriptHandlerEntry* CCSchedulerScriptHandlerEntry::create(int64_t nHandler, float fInterval, bool bPaused)
{
    CCSchedulerScriptHandlerEntry* pEntry = new CCSchedulerScriptHandlerEntry(nHandler);
    pEntry->init(fInterval, bPaused);
    pEntry->autorelease();
    return pEntry;
}

bool CCSchedulerScriptHandlerEntry::init(float fInterval, bool bPaused)
{
    m_pTimer = new CCTimer();
    m_pTimer->initWithScriptHandler(m_nHandler, fInterval);
    m_pTimer->autorelease();
    m_pTimer->retain();
    m_bPaused = bPaused;
    LUALOG("[LUA] ADD script schedule: %d, entryID: %d", m_nHandler, m_nEntryId);
    return true;
}

CCSchedulerScriptHandlerEntry::~CCSchedulerScriptHandlerEntry(void)
{
    m_pTimer->release();
    LUALOG("[LUA] DEL script schedule %d, entryID: %d", m_nHandler, m_nEntryId);
}

CCSchedulerScriptHandlerEntry::CCSchedulerScriptHandlerEntry(int64_t nHandler)
    : CCScriptHandlerEntry(nHandler)
    , m_pTimer(nullptr)
    , m_bPaused(false)
    , m_bMarkedForDeletion(false)
{
}

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
// #pragma mark -
// #pragma mark CCTouchScriptHandlerEntry
#endif

CCTouchScriptHandlerEntry* CCTouchScriptHandlerEntry::create(int64_t nHandler,
                                                             bool bIsMultiTouches,
                                                             int nPriority,
                                                             bool bSwallowsTouches)
{
    CCTouchScriptHandlerEntry* pEntry = new CCTouchScriptHandlerEntry(nHandler);
    pEntry->init(bIsMultiTouches, nPriority, bSwallowsTouches);
    pEntry->autorelease();
    return pEntry;
}

CCTouchScriptHandlerEntry::~CCTouchScriptHandlerEntry(void)
{
    if (m_nHandler != 0)
    {
        CCScriptEngineManager::sharedManager()->getScriptEngine()->removeScriptHandler(m_nHandler);
        LUALOG("[LUA] Remove touch event handler: %d", m_nHandler);
        m_nHandler = 0;
    }
}

CCTouchScriptHandlerEntry::CCTouchScriptHandlerEntry(int64_t nHandler)
    : CCScriptHandlerEntry(nHandler)
    , m_bIsMultiTouches(false)
    , m_nPriority(0)
    , m_bSwallowsTouches(false)
{
}

bool CCTouchScriptHandlerEntry::init(bool bIsMultiTouches, int nPriority, bool bSwallowsTouches)
{
    m_bIsMultiTouches = bIsMultiTouches;
    m_nPriority = nPriority;
    m_bSwallowsTouches = bSwallowsTouches;
    
    return true;
}

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
// #pragma mark -
// #pragma mark CCScriptEngineManager
#endif

static CCScriptEngineManager* s_pSharedScriptEngineManager = NULL;


CCScriptEngineManager::~CCScriptEngineManager(void)
{
    removeScriptEngine();
}

void CCScriptEngineManager::setScriptEngine(CCScriptEngineProtocol *pScriptEngine)
{
    removeScriptEngine();
    m_pScriptEngine = pScriptEngine;
}

void CCScriptEngineManager::removeScriptEngine(void)
{
    if (m_pScriptEngine)
    {
        delete m_pScriptEngine;
        m_pScriptEngine = NULL;
    }
}

CCScriptEngineManager* CCScriptEngineManager::sharedManager(void)
{
    if (!s_pSharedScriptEngineManager)
    {
        s_pSharedScriptEngineManager = new CCScriptEngineManager();
    }
    return s_pSharedScriptEngineManager;
}

void CCScriptEngineManager::purgeSharedManager(void)
{
    if (s_pSharedScriptEngineManager)
    {
        delete s_pSharedScriptEngineManager;
        s_pSharedScriptEngineManager = NULL;
    }
}

CCScriptEngineProtocol::~CCScriptEngineProtocol() {}

ccScriptType CCScriptEngineProtocol::getScriptType() { return kScriptTypeNone; }

void CCScriptEngineProtocol::removeScriptHandler(int64_t) {}

int CCScriptEngineProtocol::reallocateScriptHandler(int64_t) { return -1;}

int CCScriptEngineProtocol::executeEventWithArgs(int64_t, CCArray *) { return 0; }

NS_CC_END
