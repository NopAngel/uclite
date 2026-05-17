#include <string.h>

unsigned long strlen(const char *s) {
    unsigned long i = 0;
    while (s[i]) {
        i++;
    }
    return i;
}
