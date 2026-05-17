#ifndef UCLITE_CRYPT_H
#define UCLITE_CRYPT_H

#include <stddef.h>

unsigned int crypt_hash_fnv1a(const char *key);

void crypt_xor(char *data, size_t data_len, const char *key, size_t key_len);

#endif
