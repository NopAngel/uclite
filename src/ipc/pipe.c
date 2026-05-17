#include <ipc.h>
#include <syscall.h>
#include <errno.h>

int pipe(int pipefd[2]) {
    
    long ret = __syscall1(22, (long)pipefd);
    
    if (ret < 0) {
        errno = -ret;
        return -1;
    }
    return 0;
}
