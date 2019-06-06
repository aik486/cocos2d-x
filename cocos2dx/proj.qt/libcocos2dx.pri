include(liboutdir.pri)

CONFIG += c++11 warn_off

DEFINES += QT_COCOS

CONFIG(debug, debug|release) {
    DEFINES += COCOS2D_DEBUG=1
    DEFINES += DEBUG
} else {
    DEFINES += NDEBUG
}

unix|win32-g++ {
    QMAKE_CXXFLAGS_WARN_OFF -= -w
    QMAKE_CXXFLAGS += -Wall
    *-clang {
        QMAKE_CXXFLAGS += -Wno-unused-private-field
    }
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
    QMAKE_CXXFLAGS_WARN_OFF -= -W0
    QMAKE_CXXFLAGS += -W3 /wd4251 /wd4573
    DEFINES += _CRT_SECURE_NO_WARNINGS
    DEFINES += _SCL_SECURE_NO_WARNINGS
    LIBS += -lgdi32 -lopengl32 -luser32 -ladvapi32 -lpthreads4w
}

win32 {
    DEFINES += _WINDOWS
    DEFINES += CC_TEXTURE_ATLAS_USE_VAO=0
    DEFINES += CC_USE_QT_OPENGL
    INCLUDEPATH += \
        $$[QT_INSTALL_HEADERS]/QtZlib \
        $$COCOS2DX_PATH/cocos2dx/platform/win32
}

macx {
    LIBS += -lz
    DEFINES += CC_TARGET_OS_MAC
    INCLUDEPATH += $$COCOS2DX_PATH/cocos2dx/platform/mac
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
