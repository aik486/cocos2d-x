include(libcocos2dx.pri)

win32-msvc* {
    PRE_TARGETDEPS += \
        $$COCOS2DX_LIB/cocos2dx.lib \
        $$COCOS2DX_LIB/pthreads4w.lib
} else {
    PRE_TARGETDEPS += $$COCOS2DX_LIB/libcocos2dx.a
}

LIBS += -lcocos2dx
