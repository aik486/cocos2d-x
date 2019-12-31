include(cocos_qtscript_bindings.pri)

QT += script

CONFIG += c++11 warn_off
DESTDIR = $$COCOS2DX_LIB
TARGET = cocos_qtscript_bindings
TEMPLATE = lib
CONFIG += staticlib

emscripten {
    DEFINES += QT_FORCE_ASSERTS
}

CONFIG(debug, debug|release) {
    DEFINES += DEBUG
} else {
    DEFINES += NDEBUG
}

msvc {
    QMAKE_CXXFLAGS_WARN_OFF -= -W0
    QMAKE_CXXFLAGS += -W3 /wd4251 /wd4573
    DEFINES += _CRT_SECURE_NO_WARNINGS
    DEFINES += _SCL_SECURE_NO_WARNINGS
    CONFIG += no_batch
    QMAKE_CXXFLAGS += /wd4005 /wd4244 /bigobj
} else {
    clang|gcc {
        QMAKE_CXXFLAGS += \
            -Wno-unknown-pragmas \
            -Wno-overloaded-virtual \
            -Wno-unused-function \
            -Wno-deprecated-declarations
    
        clang:QMAKE_CXXFLAGS += \
            -Wno-unused-private-field \
            -Wno-unneeded-internal-declaration \
            -Wno-null-conversion \
            -Wno-unsequenced \
            -Wno-nonnull
        else:gcc:QMAKE_CXXFLAGS += \
            -Wno-nonnull-compare \
            -Wno-sequence-point \
            -Wno-sign-compare \
            -Wno-misleading-indentation

        DEFINES += USE_FILE32API
    }
}

SOURCES +=\
    src/QtCocosScriptEngine.cpp \
    src/js_bindings/generated/qtscript_cocos2dx.cpp \
    src/js_bindings/manual/QtScriptCCObject.cpp \
    src/js_bindings/manual/QtScriptCCObjectHolder.cpp

HEADERS += \
    src/QtCocosScriptEngine.h \
    src/js_bindings/generated/qtscript_cocos2dx.hpp \
    src/js_bindings/manual/QtScriptCCObject.hpp \
    src/QtCocosEnums.h \
    src/js_bindings/manual/QtScriptCCObjectHolder.h

OTHER_FILES += \
    src/js_bindings/generated/mac/userconf.ini \
    src/js_bindings/generated/win32/userconf.ini \
    src/js_bindings/generated/js_bindings.ini
