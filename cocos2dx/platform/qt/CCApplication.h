#pragma once

#ifdef QT_MAC
#include "platform/mac/CCApplication.h"
#endif

#ifdef QT_WIN32
#include "CCGL.h"
#include "platform/win32/CCApplication.h"
#endif
