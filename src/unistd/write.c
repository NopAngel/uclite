#include "../../arch/x86_64/syscall.h"

long write(int fd, const void *buf, unsigned long count) {
    return __syscall3(1, fd, (long)buf, count); 
}
