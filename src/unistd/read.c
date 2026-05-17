#include <unistd.h>
#include <syscall.h>

long read(int fd, void *buf, unsigned long count) {
    
    return __syscall3(0, fd, (long)buf, count);
}
