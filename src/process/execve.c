#include <process.h>
#include <syscall.h>
#include <errno.h>

int execve(const char *pathname, char *const argv[], char *const envp[]) {
    
    long ret = __syscall3(59, (long)pathname, (long)argv, (long)envp);
    
    
    
    if (ret < 0) {
        errno = (int)-ret;
        return -1;
    }
    
    return (int)ret;
}
