TEMPLATE   = subdirs
SUBDIRS   += libcocos2dx

libcocos2dx.file = libcocos2dx.pro

win32-msvc* {
    SUBDIRS += pthreads4w
    pthreads4w.file = pthreads4w.pro
    libcocos2dx.depends = pthreads4w
}
