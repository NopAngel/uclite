#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>


typedef struct Block {
    unsigned long size;
    int is_free;
    struct Block *next;
} Block;

#define BLOCK_SIZE sizeof(Block)


static Block *free_list = NULL;


static Block *request_space(unsigned long size) {
    
    unsigned long alloc_size = size + BLOCK_SIZE;
    if (alloc_size < 4096) alloc_size = 4096;
    else {
        
        alloc_size = (alloc_size + 4095) & ~4095;
    }

    Block *block = mmap(0, alloc_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (block == MAP_FAILED) return NULL;

    block->size = alloc_size - BLOCK_SIZE;
    block->is_free = 0;
    block->next = NULL;
    return block;
}

void *malloc(unsigned long size) {
    if (size == 0) return NULL;

    
    size = (size + 7) & ~7;

    
    Block *current = free_list;
    Block *last = NULL;

    while (current) {
        if (current->is_free && current->size >= size) {
            
            current->is_free = 0;
            
            return (void *)(current + 1);
        }
        last = current;
        current = current->next;
    }

    
    Block *block = request_space(size);
    if (!block) return NULL;

    
    if (!free_list) {
        free_list = block;
    } else if (last) {
        last->next = block;
    }

    
    return (void *)(block + 1);
}

void free(void *ptr) {
    if (!ptr) return;

    
    Block *block = (Block *)ptr - 1;
    block->is_free = 1; 
}

void *calloc(unsigned long nmemb, unsigned long size) {
    unsigned long total_size = nmemb * size;
    if (total_size == 0) return NULL;

    
    void *ptr = malloc(total_size);
    if (!ptr) return NULL;

    
    memset(ptr, 0, total_size);
    return ptr;
}

void *realloc(void *ptr, unsigned long size) {
    if (!ptr) return malloc(size); 
    if (size == 0) {
        free(ptr);
        return NULL; 
    }

    
    Block *block = (Block *)ptr - 1;
    if (block->size >= size) {
        
        return ptr;
    }

    
    void *new_ptr = malloc(size);
    if (!new_ptr) return NULL;

    
    memcpy(new_ptr, ptr, block->size);

    
    free(ptr);

    return new_ptr;
}
