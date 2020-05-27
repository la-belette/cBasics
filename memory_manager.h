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
 * @param ptr: pointer to current block of byte
 * @param newsize: new size of block of bytes
 * @return pointer to new block of byte
 */
void *my_realloc(void *ptr, size_t new_size, size_t old_size);

#endif //CBASICS_MEMORY_MANAGER_H
