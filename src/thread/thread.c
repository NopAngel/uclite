#include <thread.h>
#include <stdlib.h>


#define THREAD_STACK_SIZE (64 * 1024)


extern int __uclite_clone(thread_func_t fn, void *stack_top, int flags, void *arg);

int thread_create(thread_func_t fn, void *arg) {
    
    void *stack_base = malloc(THREAD_STACK_SIZE);
    if (!stack_base) return -1;

    
    void *stack_top = (char *)stack_base + THREAD_STACK_SIZE;

    
    int flags = CLONE_VM | CLONE_FS | CLONE_FILES | CLONE_SIGHAND | CLONE_THREAD;

    
    return __uclite_clone(fn, stack_top, flags, arg);
}
