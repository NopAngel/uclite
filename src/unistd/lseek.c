#include <unistd.h>
#include <syscall.h>
#include <errno.h>

long lseek(int fd, long offset, int whence) {
    
    long ret = __syscall3(8, fd, offset, whence);
    
    if (ret < 0) {
        errno = -ret;
        return -1;
    }
    
    return ret; 
}
