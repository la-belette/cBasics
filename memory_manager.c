#include "memory_manager.h"

#include "common.h"

void swap(int *a,
          int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void memswap(void *a,
             void *b,
             int size)
{
    uint8_t * temp = malloc(size);
    uint8_t* A = a;
    uint8_t* B = b;
    for (int i = 0; i < size; i++)
    {
        temp[i] =  A[i];
        A[i] = B[i];
        B[i] = temp[i];
    }
    free(temp);
}

void *remalloc(void* p,
               unsigned int s,
               unsigned int ns)
{
    uint8_t *ref = p;
    uint8_t *newPointer = malloc(ns);
    size_t copySize = s < ns ? s : ns;
    for (int byteNb = 0; byteNb < copySize; byteNb++)
    {
        newPointer[byteNb] = ref[byteNb];
    }
    return newPointer;
}

void *my_realloc(void *ptr, size_t new_size, size_t old_size)
{
    int8_t *ref = ptr;

    int8_t *new_pointer = (uint8_t *)malloc(new_size);
    if(NULL == new_pointer)
        return NULL;

    size_t transfer_size = old_size < new_size ? old_size : new_size;
    for (int i = 0; i < transfer_size; i++)
    {
        *(new_pointer+i) = *(ref+i);
    }

    free(ptr);

    return new_pointer;
}

void *my_memset(void *s, int c, size_t n)
{
    uint8_t *pointer = s;
    for (int byte = 0; byte < n; byte++)
    {
        pointer[byte] = c;
    }
    return s;
}
