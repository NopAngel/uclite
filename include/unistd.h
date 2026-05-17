#ifndef UCLITE_UNISTD_H
#define UCLITE_UNISTD_H

#include <stddef.h>

#define SEEK_SET 0  
#define SEEK_CUR 1  
#define SEEK_END 2  

extern char **__environ;

int open(const char *pathname, int flags, ...);
int close(int fd);
long read(int fd, void *buf, size_t count);
long write(int fd, const void *buf, size_t count);
long lseek(int fd, long offset, int whence);
void _exit(int status);

#endif
