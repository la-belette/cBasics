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