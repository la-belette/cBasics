#ifndef CBASICS_CRYPTING_INTERFACE_H
#define CBASICS_CRYPTING_INTERFACE_H

#include "common.h"

typedef struct
{
    void (*encrypt)(void *data, size_t data_len, void *key, size_t key_len);
    void (*decrypt)(void *data, size_t data_len, void *key, size_t key_len);
} s_crypto_interface;

void register_module(s_crypto_interface *module);
void generic_encrypt(void *data, size_t data_len, void *key, size_t key_len);
void generic_decrypt(void *data, size_t data_len, void *key, size_t key_len);

#endif //CBASICS_CRYPTING_INTERFACE_H
