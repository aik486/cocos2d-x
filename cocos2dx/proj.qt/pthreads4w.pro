include(liboutdir.pri)

CONFIG += c++11

DESTDIR = $$COCOS2DX_LIB

TARGET = pthreads4w
TEMPLATE = lib
CONFIG += staticlib

DEFINES += HAVE_CONFIG_H __PTW32_BUILD_INLINED
INCLUDEPATH += $$PTHREADS_PATH

SOURCES += $$PTHREADS_PATH/pthread.c

HEADERS += \
    $$PTHREADS_PATH/cleanup.c \
    $$PTHREADS_PATH/create.c \
    $$PTHREADS_PATH/dll.c \
    $$PTHREADS_PATH/errno.c \
    $$PTHREADS_PATH/global.c \
    $$PTHREADS_PATH/pthread_attr_destroy.c \
    $$PTHREADS_PATH/pthread_attr_getaffinity_np.c \
    $$PTHREADS_PATH/pthread_attr_getdetachstate.c \
    $$PTHREADS_PATH/pthread_attr_getinheritsched.c \
    $$PTHREADS_PATH/pthread_attr_getname_np.c \
    $$PTHREADS_PATH/pthread_attr_getschedparam.c \
    $$PTHREADS_PATH/pthread_attr_getschedpolicy.c \
    $$PTHREADS_PATH/pthread_attr_getscope.c \
    $$PTHREADS_PATH/pthread_attr_getstackaddr.c \
    $$PTHREADS_PATH/pthread_attr_getstacksize.c \
    $$PTHREADS_PATH/pthread_attr_init.c \
    $$PTHREADS_PATH/pthread_attr_setaffinity_np.c \
    $$PTHREADS_PATH/pthread_attr_setdetachstate.c \
    $$PTHREADS_PATH/pthread_attr_setinheritsched.c \
    $$PTHREADS_PATH/pthread_attr_setname_np.c \
    $$PTHREADS_PATH/pthread_attr_setschedparam.c \
    $$PTHREADS_PATH/pthread_attr_setschedpolicy.c \
    $$PTHREADS_PATH/pthread_attr_setscope.c \
    $$PTHREADS_PATH/pthread_attr_setstackaddr.c \
    $$PTHREADS_PATH/pthread_attr_setstacksize.c \
    $$PTHREADS_PATH/pthread_barrier_destroy.c \
    $$PTHREADS_PATH/pthread_barrier_init.c \
    $$PTHREADS_PATH/pthread_barrier_wait.c \
    $$PTHREADS_PATH/pthread_barrierattr_destroy.c \
    $$PTHREADS_PATH/pthread_barrierattr_getpshared.c \
    $$PTHREADS_PATH/pthread_barrierattr_init.c \
    $$PTHREADS_PATH/pthread_barrierattr_setpshared.c \
    $$PTHREADS_PATH/pthread_cancel.c \
    $$PTHREADS_PATH/pthread_cond_destroy.c \
    $$PTHREADS_PATH/pthread_cond_init.c \
    $$PTHREADS_PATH/pthread_cond_signal.c \
    $$PTHREADS_PATH/pthread_cond_wait.c \
    $$PTHREADS_PATH/pthread_condattr_destroy.c \
    $$PTHREADS_PATH/pthread_condattr_getpshared.c \
    $$PTHREADS_PATH/pthread_condattr_init.c \
    $$PTHREADS_PATH/pthread_condattr_setpshared.c \
    $$PTHREADS_PATH/pthread_delay_np.c \
    $$PTHREADS_PATH/pthread_detach.c \
    $$PTHREADS_PATH/pthread_equal.c \
    $$PTHREADS_PATH/pthread_exit.c \
    $$PTHREADS_PATH/pthread_getconcurrency.c \
    $$PTHREADS_PATH/pthread_getname_np.c \
    $$PTHREADS_PATH/pthread_getschedparam.c \
    $$PTHREADS_PATH/pthread_getspecific.c \
    $$PTHREADS_PATH/pthread_getunique_np.c \
    $$PTHREADS_PATH/pthread_getw32threadhandle_np.c \
    $$PTHREADS_PATH/pthread_join.c \
    $$PTHREADS_PATH/pthread_key_create.c \
    $$PTHREADS_PATH/pthread_key_delete.c \
    $$PTHREADS_PATH/pthread_kill.c \
    $$PTHREADS_PATH/pthread_mutex_consistent.c \
    $$PTHREADS_PATH/pthread_mutex_destroy.c \
    $$PTHREADS_PATH/pthread_mutex_init.c \
    $$PTHREADS_PATH/pthread_mutex_lock.c \
    $$PTHREADS_PATH/pthread_mutex_timedlock.c \
    $$PTHREADS_PATH/pthread_mutex_trylock.c \
    $$PTHREADS_PATH/pthread_mutex_unlock.c \
    $$PTHREADS_PATH/pthread_mutexattr_destroy.c \
    $$PTHREADS_PATH/pthread_mutexattr_getkind_np.c \
    $$PTHREADS_PATH/pthread_mutexattr_getpshared.c \
    $$PTHREADS_PATH/pthread_mutexattr_getrobust.c \
    $$PTHREADS_PATH/pthread_mutexattr_gettype.c \
    $$PTHREADS_PATH/pthread_mutexattr_init.c \
    $$PTHREADS_PATH/pthread_mutexattr_setkind_np.c \
    $$PTHREADS_PATH/pthread_mutexattr_setpshared.c \
    $$PTHREADS_PATH/pthread_mutexattr_setrobust.c \
    $$PTHREADS_PATH/pthread_mutexattr_settype.c \
    $$PTHREADS_PATH/pthread_num_processors_np.c \
    $$PTHREADS_PATH/pthread_once.c \
    $$PTHREADS_PATH/pthread_rwlock_destroy.c \
    $$PTHREADS_PATH/pthread_rwlock_init.c \
    $$PTHREADS_PATH/pthread_rwlock_rdlock.c \
    $$PTHREADS_PATH/pthread_rwlock_timedrdlock.c \
    $$PTHREADS_PATH/pthread_rwlock_timedwrlock.c \
    $$PTHREADS_PATH/pthread_rwlock_tryrdlock.c \
    $$PTHREADS_PATH/pthread_rwlock_trywrlock.c \
    $$PTHREADS_PATH/pthread_rwlock_unlock.c \
    $$PTHREADS_PATH/pthread_rwlock_wrlock.c \
    $$PTHREADS_PATH/pthread_rwlockattr_destroy.c \
    $$PTHREADS_PATH/pthread_rwlockattr_getpshared.c \
    $$PTHREADS_PATH/pthread_rwlockattr_init.c \
    $$PTHREADS_PATH/pthread_rwlockattr_setpshared.c \
    $$PTHREADS_PATH/pthread_self.c \
    $$PTHREADS_PATH/pthread_setaffinity.c \
    $$PTHREADS_PATH/pthread_setcancelstate.c \
    $$PTHREADS_PATH/pthread_setcanceltype.c \
    $$PTHREADS_PATH/pthread_setconcurrency.c \
    $$PTHREADS_PATH/pthread_setname_np.c \
    $$PTHREADS_PATH/pthread_setschedparam.c \
    $$PTHREADS_PATH/pthread_setspecific.c \
    $$PTHREADS_PATH/pthread_spin_destroy.c \
    $$PTHREADS_PATH/pthread_spin_init.c \
    $$PTHREADS_PATH/pthread_spin_lock.c \
    $$PTHREADS_PATH/pthread_spin_trylock.c \
    $$PTHREADS_PATH/pthread_spin_unlock.c \
    $$PTHREADS_PATH/pthread_testcancel.c \
    $$PTHREADS_PATH/pthread_timechange_handler_np.c \
    $$PTHREADS_PATH/pthread_timedjoin_np.c \
    $$PTHREADS_PATH/pthread_tryjoin_np.c \
    $$PTHREADS_PATH/pthread_win32_attach_detach_np.c \
    $$PTHREADS_PATH/ptw32_calloc.c \
    $$PTHREADS_PATH/ptw32_callUserDestroyRoutines.c \
    $$PTHREADS_PATH/ptw32_cond_check_need_init.c \
    $$PTHREADS_PATH/ptw32_getprocessors.c \
    $$PTHREADS_PATH/ptw32_is_attr.c \
    $$PTHREADS_PATH/ptw32_MCS_lock.c \
    $$PTHREADS_PATH/ptw32_mutex_check_need_init.c \
    $$PTHREADS_PATH/ptw32_new.c \
    $$PTHREADS_PATH/ptw32_processInitialize.c \
    $$PTHREADS_PATH/ptw32_processTerminate.c \
    $$PTHREADS_PATH/ptw32_relmillisecs.c \
    $$PTHREADS_PATH/ptw32_reuse.c \
    $$PTHREADS_PATH/ptw32_rwlock_cancelwrwait.c \
    $$PTHREADS_PATH/ptw32_rwlock_check_need_init.c \
    $$PTHREADS_PATH/ptw32_semwait.c \
    $$PTHREADS_PATH/ptw32_spinlock_check_need_init.c \
    $$PTHREADS_PATH/ptw32_threadDestroy.c \
    $$PTHREADS_PATH/ptw32_threadStart.c \
    $$PTHREADS_PATH/ptw32_throw.c \
    $$PTHREADS_PATH/ptw32_timespec.c \
    $$PTHREADS_PATH/ptw32_tkAssocCreate.c \
    $$PTHREADS_PATH/ptw32_tkAssocDestroy.c \
    $$PTHREADS_PATH/sched_get_priority_max.c \
    $$PTHREADS_PATH/sched_get_priority_min.c \
    $$PTHREADS_PATH/sched_getscheduler.c \
    $$PTHREADS_PATH/sched_setaffinity.c \
    $$PTHREADS_PATH/sched_setscheduler.c \
    $$PTHREADS_PATH/sched_yield.c \
    $$PTHREADS_PATH/sem_close.c \
    $$PTHREADS_PATH/sem_destroy.c \
    $$PTHREADS_PATH/sem_getvalue.c \
    $$PTHREADS_PATH/sem_init.c \
    $$PTHREADS_PATH/sem_open.c \
    $$PTHREADS_PATH/sem_post.c \
    $$PTHREADS_PATH/sem_post_multiple.c \
    $$PTHREADS_PATH/sem_timedwait.c \
    $$PTHREADS_PATH/sem_trywait.c \
    $$PTHREADS_PATH/sem_unlink.c \
    $$PTHREADS_PATH/sem_wait.c \
    $$PTHREADS_PATH/signal.c \
    $$PTHREADS_PATH/w32_CancelableWait.c \
    $$PTHREADS_PATH/_ptw32.h \
    $$PTHREADS_PATH/config.h \
    $$PTHREADS_PATH/context.h \
    $$PTHREADS_PATH/implement.h \
    $$PTHREADS_PATH/need_errno.h \
    $$PTHREADS_PATH/pthread.h \
    $$PTHREADS_PATH/sched.h \
    $$PTHREADS_PATH/semaphore.h
