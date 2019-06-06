COCOS2DX_QT_PATH = $$PWD
COCOS2DX_PATH = $$COCOS2DX_QT_PATH/../..

macx:COCOS2DX_LIB_TOP = $$COCOS2DX_QT_PATH/build/mac
win32:COCOS2DX_LIB_TOP = $$COCOS2DX_QT_PATH/build/win32

CONFIG(debug, debug|release) {
    COCOS2DX_LIB = $$COCOS2DX_LIB_TOP/debug
} else {
    COCOS2DX_LIB = $$COCOS2DX_LIB_TOP/release
}

win32 {
PTHREADS_PATH = $$PWD/../../external/pthreads4w
contains(QMAKE_TARGET.arch, x86_64) {
    COCOS2DX_LIB = $$COCOS2DX_LIB/x64
} else {
    COCOS2DX_LIB = $$COCOS2DX_LIB/x32
}
}

LIBS += -L$$COCOS2DX_LIB
