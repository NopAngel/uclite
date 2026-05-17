#include <process.h>
#include <syscall.h>
#include <errno.h>

int fork(void) {
    
    long ret = __syscall3(57, 0, 0, 0);
    
    if (ret < 0) {
        errno = (int)-ret; 
        return -1;
    }
    
    return (int)ret; 
}
