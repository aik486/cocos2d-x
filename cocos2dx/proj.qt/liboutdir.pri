COCOS2DX_QT_PATH = $$PWD
COCOS2DX_PATH = $$COCOS2DX_QT_PATH/../..

QTSCRIPT_BINDINGS_PATH = $$COCOS2DX_PATH/scripting/javascript/qtscript_bindings

win32-msvc*:PTHREADS_PATH = $$COCOS2DX_PATH/external/pthreads4w

COCOS2DX_LIB = $$PWD/bin

macx:COCOS2DX_LIB = $$COCOS2DX_LIB-macx
linux:COCOS2DX_LIB = $$COCOS2DX_LIB-linux
win32 {
    COCOS2DX_LIB = $$COCOS2DX_LIB-win32
    msvc:COCOS2DX_LIB = $$COCOS2DX_LIB-msvc
}
clang:COCOS2DX_LIB = $$COCOS2DX_LIB-clang
else::gcc:COCOS2DX_LIB = $$COCOS2DX_LIB-gcc

COCOS2DX_LIB = $$COCOS2DX_LIB-$$QT_ARCH

CONFIG(debug, debug|release) {
    COCOS2DX_LIB = $$COCOS2DX_LIB/debug
}
