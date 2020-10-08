include(liboutdir.pri)

LIBS += -L$$COCOS2DX_LIB
LIBS += -lcocos2dx

include(libcocos2dx.pri)


msvc {
    PRE_TARGETDEPS += $$COCOS2DX_LIB/cocos2dx.lib
} else {
    PRE_TARGETDEPS += $$COCOS2DX_LIB/libcocos2dx.a
}

msvc {
    QMAKE_LFLAGS += /ignore:4099 /ignore:4098
}