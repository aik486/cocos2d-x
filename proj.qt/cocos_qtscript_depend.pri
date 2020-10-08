include(cocos2dx.pri)
include($$QTSCRIPT_BINDINGS_PATH/qtscript_bindings_depend.pri)

msvc {
    PRE_TARGETDEPS += \
        $$COCOS2DX_LIB/cocos_qtscript_bindings.lib
} else {
    PRE_TARGETDEPS += $$COCOS2DX_LIB/libcocos_qtscript_bindings.a
}

LIBS += -lcocos_qtscript_bindings
