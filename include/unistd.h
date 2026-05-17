#ifndef UCLITE_UNISTD_H
#define UCLITE_UNISTD_H

#include <stddef.h>

// Macros estándar para el posicionamiento en archivos
#define SEEK_SET 0  // Desde el inicio del archivo
#define SEEK_CUR 1  // Desde la posición actual
#define SEEK_END 2  // Desde el final del archivo

extern char **__environ;

int open(const char *pathname, int flags, ...);
int close(int fd);
long read(int fd, void *buf, size_t count);
long write(int fd, const void *buf, size_t count);
long lseek(int fd, long offset, int whence);
void _exit(int status);

#endif
