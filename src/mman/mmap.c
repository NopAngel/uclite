#include <sys/mman.h>
#include <syscall.h>

void *mmap(void *addr, unsigned long length, int prot, int flags, int fd, long offset) {
    
    long ret = __syscall6(9, (long)addr, length, prot, flags, fd, offset);
    return (void *)ret;
}
