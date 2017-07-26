#pragma once

#ifdef QT_MAC
#include "platform/mac/CCEGLView.h"
#endif

#ifdef QT_WIN32
#include "CCGL.h"
#include "platform/win32/CCEGLView.h"
#endif


