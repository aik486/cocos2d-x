include(liboutdir.pri)

LIBS += -L$$COCOS2DX_LIB
LIBS += -lcocos2dx

include(libcocos2dx.pri)


msvc {
    PRE_TARGETDEPS += \
        $$COCOS2DX_LIB/cocos2dx.lib \
        $$COCOS2DX_LIB/pthreads4w.lib
} else {
    PRE_TARGETDEPS += $$COCOS2DX_LIB/libcocos2dx.a
}

