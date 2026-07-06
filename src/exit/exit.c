#include <stdlib.h>
#include <stdio.h>

extern FILE *stdout;
extern FILE *stderr;
int fflush(FILE *stream);
void _exit(int status);

void exit(int status) 
{    
    if (stdout) fflush(stdout);
    if (stderr) fflush(stderr);

    _exit(status);
}
