include(cocos_qtscript_bindings.pri)

QT += script

CONFIG += c++11
DESTDIR = $$COCOS2DX_LIB
TARGET = cocos_qtscript_bindings
TEMPLATE = lib
CONFIG += staticlib

CONFIG(debug, debug|release) {
    DEFINES += DEBUG
} else {
    DEFINES += NDEBUG
}

!isEmpty(DEBUG_COCOS) {
    emscripten:DEFINES += QT_FORCE_ASSERTS
}

msvc {
    QMAKE_CXXFLAGS_WARN_ON += /wd4251 /wd4573 /wd4005 /wd4244 /wd4100 /wd4189
    DEFINES += _CRT_SECURE_NO_WARNINGS
    DEFINES += _SCL_SECURE_NO_WARNINGS
    CONFIG += no_batch
    QMAKE_CXXFLAGS += /bigobj
} else {
    DEFINES += USE_FILE32API
    clang|gcc:QMAKE_CXXFLAGS_WARN_ON += \
        -Wno-deprecated-copy-with-user-provided-copy \
        -Wno-deprecated-copy \
        -Wno-missing-field-initializers \
        -Wno-null-pointer-subtraction \
        -Wno-overloaded-virtual \
        -Wno-sign-compare \
        -Wno-unknown-warning-option \
        -Wno-unknown-warning \
        -Wno-unused-but-set-variable \
        -Wno-unused-command-line-argument \
        -Wno-unused-function \
        -Wno-unused-parameter \
        -Wno-unused-private-field \
        -Wno-unused-variable
}

SOURCES +=\
    src/QtCocosScriptEngine.cpp \
    src/js_bindings/QtCocosScriptUtils.cpp \
    src/js_bindings/generated/qtscript_cocos2dx.cpp \
    src/js_bindings/manual/QtScriptCCCustomEffect.cpp \
    src/js_bindings/manual/QtScriptRef.cpp \
    src/js_bindings/manual/QtScriptRefHolder.cpp

HEADERS += \
    src/QtCocosScriptEngine.h \
    src/js_bindings/QtCocosScriptUtils.hpp \
    src/js_bindings/generated/qtscript_cocos2dx.hpp \
    src/js_bindings/manual/QtScriptCCCustomEffect.h \
    src/QtCocosEnums.h \
    src/js_bindings/manual/QtScriptRef.hpp \
    src/js_bindings/manual/QtScriptRefHolder.h

OTHER_FILES += \
    src/js_bindings/generated/mac/userconf.ini \
    src/js_bindings/generated/win32/userconf.ini \
    src/js_bindings/generated/js_bindings.ini
