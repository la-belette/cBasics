#ifndef CBASICS_MEMORY_MANAGER_H
#define CBASICS_MEMORY_MANAGER_H

#include "common.h"

/*
 * swap swaps content between two integer pointers.
 * @param a: first pointer to swap with b
 * @param b: second pointer to swap with a
 */
void swap(int *a,
          int *b);

/*
 * memswap swaps size bytes between pointers a and b
 * @param a: first reference to target content to swap
 * @param b: second reference to target content to swap
 */
void memswap(void *a,
             void *b,
             int size);

/*
 * remalloc copies s bytes of p content into a new pointer of size ns
 * @param p: reference for copy
 * @param s: byte size of p content to copy
 * @param ns: byte size of result copy
 * @return a new pointer to ns byte content beginning with s bytes of
 * p content.
 */
void *remalloc(void* p,
               unsigned int s,
               unsigned int ns);

/*
 * realloc resizes allocated memory without losing old data.
 * @param ptr: pointer to current block of byte must have been allocated with malloc
 * @param newsize: new size of block of bytes
 * @return pointer to new block of byte
 */
void *my_realloc(void *ptr, size_t new_size, size_t old_size);

/*
 * my_memset fills the first n bytes of the memory area pointed to by
 * s with the constant c.
 * @param s: pointer to memory area to fill with c
 * @param c: byte constant to fill n first bytes with
 * @param n: nb of bytes pointed to by s to fill with c
 * @return pointer to s
 */
void *my_memset(void *s, int c, size_t n);

/*
 * memcpy copies n bytes from memcpy area src to memory area dest.
 * The memory areas must not overlap.
 * @param dest: pointer to memory area to copy to
 * @param src: pointer to reference memory area
 * @param n: number of bytes to copy from src to dest
 * @return return a pointer to dest
 */
void *my_memcpy(void* dest, const void *src, size_t n);

/*
 * memcmp compares n bytes from memory area a with memory area b.
 * @param a: pointer to memory area to compare with b
 * @param b: pointer to memory area to compare with a
 * @param n: number of bytes to compare between a and b
 * @return return 0 if equal, else -1
 */
int memcmp(const void* a, const void *b, size_t n);

#endif //CBASICS_MEMORY_MANAGER_H
