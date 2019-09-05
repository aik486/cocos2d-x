TEMPLATE   = subdirs
SUBDIRS   += \
	libcocos2dx \
	qtscript_bindings

libcocos2dx.file = cocos2dx/proj.qt/libcocos2dx.pro
qtscript_bindings.file = scripting/javascript/qtscript_bindings/qtscript_bindings.pro

win32-msvc* {
    SUBDIRS += pthreads4w
    pthreads4w.file = cocos2dx/proj.qt/pthreads4w.pro
    libcocos2dx.depends = pthreads4w
}
libcocos2dx.depends += qtscript_bindings
