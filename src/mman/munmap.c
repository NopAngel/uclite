#include <sys/mman.h>
#include <syscall.h>

int munmap(void *addr, unsigned long length) {
    
    return (int)__syscall3(11, (long)addr, length, 0);
}
