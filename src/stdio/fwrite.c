#include <stdio.h>

long write(int fd, const void *buf, unsigned long count);

int fflush(FILE *stream) {
    if (!stream) return -1;
    
    
    if (stream->buffer && stream->buf_pos > 0) {
        long ret = write(stream->fd, stream->buffer, stream->buf_pos);
        stream->buf_pos = 0; 
        if (ret < 0) return -1;
    }
    return 0;
}

int fputc(int c, FILE *stream) {
    if (!stream) return -1;

    unsigned char ch = (unsigned char)c;

    
    if (!stream->buffer) {
        if (write(stream->fd, &ch, 1) == 1) return c;
        return -1;
    }

    
    stream->buffer[stream->buf_pos++] = ch;

    
    if (stream->buf_pos >= stream->buf_size || ch == '\n') {
        if (fflush(stream) != 0) return -1;
    }

    return c;
}

unsigned long fwrite(const void *ptr, unsigned long size, unsigned long nmemb, FILE *stream) {
    if (!stream || !ptr || size == 0 || nmemb == 0) return 0;

    unsigned long total_bytes = size * nmemb;
    const unsigned char *data = ptr;

    
    for (unsigned long i = 0; i < total_bytes; i++) {
        if (fputc(data[i], stream) == -1) {
            return i / size; 
        }
    }

    return nmemb;
}
