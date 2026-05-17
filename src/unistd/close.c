#include <unistd.h>
#include <syscall.h>

int close(int fd) {
    
    return (int)__syscall3(3, fd, 0, 0);
}
