#include <time.h>
#include <syscall.h>
#include <errno.h>

int clock_gettime(int clock_id, struct timespec *tp) {
    
    long ret = __syscall2(228, clock_id, (long)tp);
    
    if (ret < 0) {
        errno = -ret;
        return -1;
    }
    
    return 0;
}
