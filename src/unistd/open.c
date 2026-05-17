#include <fcntl.h>
#include <syscall.h>
#include <stdarg.h>

int open(const char *pathname, int flags, ...) {
    unsigned int mode = 0;
    
    
    if (flags & O_CREAT) {
        va_list args;
        va_start(args, flags);
        mode = va_arg(args, unsigned int);
        va_end(args);
    }

    return (int)__syscall3(2, (long)pathname, flags, mode);
}
