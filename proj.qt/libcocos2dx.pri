include(liboutdir.pri)

include($$COCOS2DX_PATH/external/freetype2/qt/freetype_depend.pri)

DEFINES += \
    QT_COCOS \
    QT_COCOS_SCRIPT_BINDING \
    CC_STATIC \
    CC_ENABLE_CACHE_TEXTURE_DATA=0 \
    CC_USE_CULLING=0 \
    CC_ENABLE_CHIPMUNK_INTEGRATION=0 \
    CC_USE_PHYSICS=0 \
    CC_ENABLE_BULLET_INTEGRATION=0 \
    CC_ENABLE_SCRIPT_BINDING=0

CONFIG(debug, debug|release)|!isEmpty(DEBUG_COCOS) {
    emscripten:DEFINES += COCOS2D_DEBUG=0
    else:DEFINES += COCOS2D_DEBUG=1
    DEBUG_COCOS = 1
}


linux {
    LIBS += -Wl,-Bstatic -lz -Wl,-Bdynamic
    DEFINES += LINUX
    DEFINES += CC_USE_QT_OPENGL
    
}

macx {
    LIBS += \
        -framework Foundation \
        -framework CoreGraphics \
        -framework CoreVideo \
        -framework AppKit
    DEFINES += CC_TEXTURE_ATLAS_USE_VAO=1
}

win32|emscripten {
    !mingw:INCLUDEPATH += $$[QT_INSTALL_HEADERS]/QtZlib
}

win32 {
    LIBS += -lgdi32 -lopengl32 -luser32 -ladvapi32 -lshell32 -lws2_32
    mingw: LIBS += -lz
    DEFINES += _WINDOWS
    DEFINES += CC_TEXTURE_ATLAS_USE_VAO=0
    DEFINES += CC_USE_QT_OPENGL
}

macx {
    LIBS += -lz
    DEFINES += TARGET_OS_MAC
}


INCLUDEPATH += \
    $$COCOS2DX_QT_PATH/src \
    $$COCOS2DX_PATH \
    $$COCOS2DX_PATH/cocos \
    $$COCOS2DX_PATH/external
