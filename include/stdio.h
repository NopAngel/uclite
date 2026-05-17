#ifndef UCLITE_STDIO_H
#define UCLITE_STDIO_H

typedef struct FILE {
    int fd;                 
    char *buffer;           
    unsigned long buf_size; 
    unsigned long buf_pos;  
    int flags;              
} FILE;

extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;

int printf(const char *format, ...);
int fflush(FILE *stream);
int fputc(int c, FILE *stream);
unsigned long fwrite(const void *ptr, unsigned long size, unsigned long nmemb, FILE *stream);
FILE *fopen(const char *pathname, const char *mode);
int fclose(FILE *stream);
int fgetc(FILE *stream);
unsigned long fread(void *ptr, unsigned long size, unsigned long nmemb, FILE *stream);

#endif
