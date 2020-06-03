#ifndef CBASICS_BIT_OPERATION_HELPER_H
#define CBASICS_BIT_OPERATION_HELPER_H

#include "common.h"

/*
 * rol rotates value roll bit(s) to the left.
 * @param value: target value to shift
 * @param roll: size of shift in bits
 * @return value rotated roll bits to the left
 */
unsigned char rol(unsigned char value, unsigned int roll);

/*
 * ror rotates value roll bit(s) to the right.
 * @param value: target value to shift
 * @param roll: size of shift in bits
 * @return value rotated roll bits to the right
 */
unsigned char ror(unsigned char value, unsigned int roll);

/*
 * my_xor_cryt cryts data with key and bitwise xor operation
 * @param data: the target data to crypt
 * @param data_len the size of data to crypt in bytes
 * @param key the crypting key
 * @param key_len the key size in bytes
 */
void my_xor_crypt(void* data, size_t data_len, void* key, size_t key_len);

/*
 * my_rol_cryt cryts data with key and key elements as size of left rotation operation
 * @param data: the target data to crypt
 * @param data_len the size of data to crypt in bytes
 * @param key the crypting key
 * @param key_len the key size in bytes
 */
void my_rol_crypt(void* data, size_t data_len, void* key, size_t key_len);

/*
 * my_ror_cryt cryts data with key and key elements as size of right rotation operation
 * @param data: the target data to crypt
 * @param data_len the size of data to crypt in bytes
 * @param key the crypting key
 * @param key_len the key size in bytes
 */
void my_ror_crypt(void* data, size_t data_len, void* key, size_t key_len);

#endif //CBASICS_BIT_OPERATION_HELPER_H
