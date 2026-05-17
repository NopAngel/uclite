#ifndef UCLITE_THREAD_H
#define UCLITE_THREAD_H

#include <stddef.h>

#define CLONE_VM       0x00000100  
#define CLONE_FS       0x00000200  
#define CLONE_FILES    0x00000400  
#define CLONE_SIGHAND  0x00000800  
#define CLONE_THREAD   0x00010000  

typedef int (*thread_func_t)(void *);

int thread_create(thread_func_t fn, void *arg);

#endif
