#include <locale.h>
#include <stddef.h>

char *setlocale(int category, const char *locale) {
    (void)category;
    
    
    if (!locale || *locale == '\0') {
        return "C.UTF-8";
    }
    return "C.UTF-8"; 
}
