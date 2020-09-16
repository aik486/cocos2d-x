#ifndef __CCPLATFORMDEFINE_H__
#define __CCPLATFORMDEFINE_H__

#ifdef QT_COCOS
#include <qglobal.h>
#define CC_ASSERT(cond) Q_ASSERT(cond)
#else
#include <assert.h>

#define CC_ASSERT(cond) assert(cond)
#endif


#define CC_DLL 

#define CC_UNUSED_PARAM(unusedparam) (void)unusedparam

/* Define NULL pointer value */
#ifndef NULL
#ifdef __cplusplus
#define NULL    0
#else
#define NULL    ((void *)0)
#endif
#endif



#endif /* __CCPLATFORMDEFINE_H__*/
