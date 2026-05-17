#include <string.h>

char *strcat(char *dest, const char *src) {
    char *save = dest;

    
    while (*dest) {
        dest++;
    }

    
    while ((*dest++ = *src++)) {
        
    }

    return save; 
}
