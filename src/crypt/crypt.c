#include <crypt.h>

unsigned int crypt_hash_fnv1a(const char *key) {
    
    unsigned int hash = 2166136261U;
    while (*key) {
        hash ^= (unsigned char)*key++;
        hash *= 16777619U;
    }
    return hash;
}

void crypt_xor(char *data, size_t data_len, const char *key, size_t key_len) {
    if (key_len == 0) return;
    for (size_t i = 0; i < data_len; i++) {
        
        
        data[i] ^= key[i % key_len];
    }
}
