#include <stdlib.h>
#include <string.h>





void *realloc(void *ptr, size_t size) {
    
    if (!ptr) {
        return malloc(size);
    }

    
    if (size == 0) {
        
        return (void *)0;
    }

    
    
    void *new_ptr = malloc(size);
    if (!new_ptr) return (void *)0; 

    
    
    
    
    memcpy(new_ptr, ptr, size);

    
    

    return new_ptr;
}
