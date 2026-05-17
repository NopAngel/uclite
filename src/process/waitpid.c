#include <process.h>
#include <syscall.h>
#include <errno.h>

int waitpid(int pid, int *wstatus, int options) {
    
    
    long ret = __syscall4(61, pid, (long)wstatus, options, 0);
    
    if (ret < 0) {
        errno = (int)-ret;
        return -1;
    }
    
    return (int)ret; 
}
