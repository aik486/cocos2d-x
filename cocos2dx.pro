TEMPLATE   = subdirs
SUBDIRS   += \
	libcocos2dx \
	cocos_qtscript_bindings \
	qtscript_bindings

libcocos2dx.file = proj.qt/libcocos2dx.pro
qtscript_bindings.file = scripting/javascript/qtscript_bindings/qtscript_bindings.pro
cocos_qtscript_bindings.file = proj.qt/cocos_qtscript_bindings.pro

cocos_qtscript_bindings.depends = libcocos2dx qtscript_bindings

