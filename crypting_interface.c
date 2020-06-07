#include "crypting_interface.h"

s_crypto_interface *crypto_module = NULL;

void register_module(s_crypto_interface *module)
{
    crypto_module = module;
}

void generic_encrypt(void *data, size_t data_len, void *key, size_t key_len)
{
    if (crypto_module == NULL)
        fprintf(stderr, "Cannot encrypt data, because no module is registered\n");
    else
        crypto_module->encrypt(data, data_len, key, key_len);
}

void generic_decrypt(void *data, size_t data_len, void *key, size_t key_len)
{
    if (crypto_module == NULL)
        fprintf(stderr, "Cannot decrypt data, because no module is registered\n");
    else
        crypto_module->decrypt(data, data_len, key, key_len);
}
