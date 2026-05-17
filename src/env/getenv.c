#include <unistd.h>
#include <string.h>

char *getenv(const char *name) {
    if (!name || !__environ) return (void *)0;

    size_t len = strlen(name);

    
    for (int i = 0; __environ[i] != (void *)0; i++) {
        
        
        if (strncmp(__environ[i], name, len) == 0 && __environ[i][len] == '=') {
            
            return &__environ[i][len + 1];
        }
    }

    return (void *)0; 
}
