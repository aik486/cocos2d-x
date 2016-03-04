#pragma once

#include "platform/CCPlatformMacros.h"
#include <cfloat>
#include <cmath>
#include <cstring>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstdint>

#if defined(QT_WIN32)
	typedef int32_t ssize_t;
#endif

#ifndef MIN
#define MIN(x,y) (((x) > (y)) ? (y) : (x))
#endif  // MIN

#ifndef MAX
#define MAX(x,y) (((x) < (y)) ? (y) : (x))
#endif  // MAX
