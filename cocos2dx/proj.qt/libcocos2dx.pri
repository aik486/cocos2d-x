include(liboutdir.pri)

DEFINES += QT_COCOS

CONFIG(debug, debug|release)|!isEmpty(DEBUG_COCOS) {
    DEFINES += COCOS2D_DEBUG=1
    DEBUG_COCOS = 1
}

DEFINES += CC_ENABLE_CACHE_TEXTURE_DATA=0

linux {
 LIBS += -Wl,-Bstatic -lz -Wl,-Bdynamic
 DEFINES += LINUX
 INCLUDEPATH += $$COCOS2DX_PATH/cocos2dx/platform/linux
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

win32-msvc* {
    LIBS += -lgdi32 -lopengl32 -luser32 -ladvapi32 -lpthreads4w -lshell32
    INCLUDEPATH += $$PTHREADS_PATH
}

win32|emscripten {
    INCLUDEPATH += $$[QT_INSTALL_HEADERS]/QtZlib
}

win32 {
    DEFINES += _WINDOWS
    DEFINES += CC_TEXTURE_ATLAS_USE_VAO=0
    DEFINES += CC_USE_QT_OPENGL
    INCLUDEPATH += \
        $$COCOS2DX_PATH/cocos2dx/platform/win32
}

macx {
    LIBS += -lz
    DEFINES += CC_TARGET_OS_MAC
    INCLUDEPATH += $$COCOS2DX_PATH/cocos2dx/platform/mac
}

emscripten {
    INCLUDEPATH += $$COCOS2DX_PATH/cocos2dx/platform/emscripten
}

DEFINES += CC_STATIC_LIB

greaterThan(QT_MINOR_VERSION,9) {
    win32-msvc {
       DEFINES += HAVE_STRUCT_TIMESPEC=1
    }
} else {
    win32-msvc2015 {
       DEFINES += HAVE_STRUCT_TIMESPEC=1
    }
}

INCLUDEPATH += \
    $$COCOS2DX_QT_PATH/src \
    $$COCOS2DX_PATH \
    $$COCOS2DX_PATH/cocos2dx/ \
    $$COCOS2DX_PATH/cocos2dx/include \
    $$COCOS2DX_PATH/cocos2dx/kazmath/include
