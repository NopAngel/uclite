#include <network.h>
#include <syscall.h>
#include <errno.h>

int socket(int domain, int type, int protocol) {
    
    long ret = __syscall3(41, domain, type, protocol);
    
    if (ret < 0) {
        errno = -ret;
        return -1;
    }
    return (int)ret; 
}
