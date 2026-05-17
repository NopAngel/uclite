#include <stdlib.h>
#include <stdio.h>


static FILE _stdin  = { .fd = 0, .buffer = NULL, .buf_size = 0, .buf_pos = 0, .flags = 0 };
static FILE _stdout = { .fd = 1, .buffer = NULL, .buf_size = 0, .buf_pos = 0, .flags = 0 };
static FILE _stderr = { .fd = 2, .buffer = NULL, .buf_size = 0, .buf_pos = 0, .flags = 0 };

FILE *stdin  = &_stdin;
FILE *stdout = &_stdout;
FILE *stderr = &_stderr;
