#include <stdio.h>
#include <unistd.h>

int fgetc(FILE *stream) {
    if (!stream) return -1;

    
    if (!stream->buffer) {
        unsigned char ch;
        if (read(stream->fd, &ch, 1) == 1) return ch;
        return -1;
    }

    
    
    
    if (stream->buf_pos >= stream->buf_size || stream->buf_size == 1024 && stream->buf_pos == 0) {
        
        
        long bytes_leidos = read(stream->fd, stream->buffer, 1024);
        
        if (bytes_leidos <= 0) {
            return -1; 
        }
        
        stream->buf_size = bytes_leidos; 
        stream->buf_pos = 0;             
    }

    
    return (unsigned char)stream->buffer[stream->buf_pos++];
}

unsigned long fread(void *ptr, unsigned long size, unsigned long nmemb, FILE *stream) {
    if (!stream || !ptr || size == 0 || nmemb == 0) return 0;

    unsigned long total_bytes = size * nmemb;
    unsigned char *data = ptr;

    for (unsigned long i = 0; i < total_bytes; i++) {
        int c = fgetc(stream);
        if (c == -1) {
            return i / size; 
        }
        data[i] = (unsigned char)c;
    }

    return nmemb;
}
