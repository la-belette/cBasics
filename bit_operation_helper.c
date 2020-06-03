#include "bit_operation_helper.h"

unsigned char rol(unsigned char value, unsigned int roll)
{
    uint8_t rotation_size = roll%8;
    uint8_t new_lower_bits = value >> (8-rotation_size);
    return (value << rotation_size) + new_lower_bits;
}

unsigned char ror(unsigned char value, unsigned int roll)
{
    uint8_t rotation_size = roll%8;
    uint8_t new_higher_bits = value << (8-rotation_size);
    return (value >> rotation_size) + new_higher_bits;
}

void my_xor_crypt(void *data, size_t data_len, void *key, size_t key_len)
{
    uint8_t *data_ref = data;
    uint8_t *key_ref = key;
    uint8_t data_element;
    uint8_t key_element;

    for (int byte = 0; byte < data_len; byte++)
    {
        data_element = data_ref[byte];
        key_element = key_ref[byte%key_len];
        data_ref[byte] = data_element^key_element;
    }
}

void my_rol_crypt(void* data, size_t data_len, void* key, size_t key_len)
{
    uint8_t *data_ref = data;
    uint8_t *key_ref = key;
    uint8_t data_element;
    uint8_t key_element;
    for (int byte = 0; byte < data_len; byte++)
    {
        data_element = data_ref[byte];
        key_element = key_ref[byte%key_len];
        data_ref[byte] = rol(data_element, key_element);
    }
}

void my_ror_crypt(void* data, size_t data_len, void* key, size_t key_len)
{
    uint8_t *data_ref = data;
    uint8_t *key_ref = key;
    uint8_t data_element;
    uint8_t key_element;
    for (int byte = 0; byte < data_len; byte++)
    {
        data_element = data_ref[byte];
        key_element = key_ref[byte%key_len];
        data_ref[byte] = ror(data_element, key_element);
    }
}