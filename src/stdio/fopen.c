#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

FILE *fopen(const char *pathname, const char *mode) {
    int flags = 0;
    
    unsigned int permissions = 0644; 

    if (mode[0] == 'r') {
        flags = O_RDONLY;
    } else if (mode[0] == 'w') {
        flags = O_WRONLY | O_CREAT | O_TRUNC;
    } else if (mode[0] == 'a') {
        flags = O_WRONLY | O_CREAT | O_APPEND;
    } else {
        return NULL;
    }

    int fd = open(pathname, flags, permissions);
    if (fd < 0) return NULL;

    
    FILE *stream = malloc(sizeof(FILE));
    if (!stream) {
        close(fd);
        return NULL;
    }

    
    stream->buffer = malloc(1024);
    if (!stream->buffer) {
        free(stream);
        close(fd);
        return NULL;
    }

    stream->fd = fd;
    stream->buf_size = 1024;
    stream->buf_pos = 0;
    stream->flags = flags;

    return stream;
}

int fclose(FILE *stream) {
    if (!stream) return -1;

    
    fflush(stream);

    
    close(stream->fd);

    
    free(stream->buffer);
    free(stream);

    return 0;
}
