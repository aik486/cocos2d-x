TEMPLATE   = subdirs
SUBDIRS   += \
	libcocos2dx \
	cocos_qtscript_bindings \
	qtscript_bindings

libcocos2dx.file = cocos2dx/proj.qt/libcocos2dx.pro
qtscript_bindings.file = scripting/javascript/qtscript_bindings/qtscript_bindings.pro
cocos_qtscript_bindings.file = cocos2dx/proj.qt/cocos_qtscript_bindings.pro

win32-msvc* {
    SUBDIRS += pthreads4w
    pthreads4w.file = cocos2dx/proj.qt/pthreads4w.pro
    libcocos2dx.depends = pthreads4w
}

cocos_qtscript_bindings.depends = libcocos2dx qtscript_bindings

