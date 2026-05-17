#ifndef UCLITE_STDLIB_H
#define UCLITE_STDLIB_H

#include <stddef.h>

void exit(int status);
char *getenv(const char *name);
void *malloc(size_t size);
void *realloc(void *ptr, size_t size);
int atoi(const char *str);
int mblen(const char *s, size_t n);
char *itoa(int num, char *str, int base);
void free(void *ptr);

#endif
