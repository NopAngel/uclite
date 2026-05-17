#include <stdlib.h>

int mblen(const char *s, size_t n) {
    if (!s || *s == '\0' || n == 0) {
        return 0;
    }

    unsigned char c = (unsigned char)*s;

    
    if (c < 0x80) return 1;

    
    if ((c & 0xE0) == 0xC0) return (n >= 2) ? 2 : -1;

    
    if ((c & 0xF0) == 0xE0) return (n >= 3) ? 3 : -1;

    
    if ((c & 0xF8) == 0xF0) return (n >= 4) ? 4 : -1;

    
    return -1;
}
