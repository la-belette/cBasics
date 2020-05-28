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

    int8_t *new_pointer = (uint8_t *)calloc(1, new_size);
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

void *my_memcpy(void* dest, const void *src, size_t n)
{
    uint8_t *final = dest;
    uint8_t *origin = src;
    for (int byte = 0; byte < n; byte++)
    {
        final[byte] = origin[byte];
    }
    return dest;
}

int memcmp(const void* a, const void *b, size_t n)
{
    int result = 0;

    if((a == NULL) || (b == NULL))
        return -1;

    uint8_t *refa = a;
    uint8_t *refb = b;
    for (int byte = 0; byte < n; byte++)
    {
        if(refa[byte] != refb[byte])
            result = -1;
    }
    return result;
}

void *my_memmove(void *dest, const void *src, size_t n)
{
    uint8_t *temp = (uint8_t*)malloc(n);
    temp = my_memcpy(temp, src, n);
    dest = my_memcpy(dest, temp, n);
    free(temp);
    return dest;
}

void my_memdump(const void *s, size_t n)
{
    uint8_t *ref = s;
    for (int line = 0; line < n/16; line++)
    {
        int offset = line*16;
        for (int byte = 0; byte < 7; byte ++)
        {
            printf("%2x ", ref[offset+byte]);
        }
        printf(" ");
        for (int byte = 8; byte < 15; byte ++)
        {
            printf("%2x ", ref[offset+byte]);
        }
        printf(" |");
        for (int byte = 0; byte < 15; byte ++)
        {
            if (((ref[offset+byte] >= 'A')
              && (ref[offset+byte] <= 'Z'))
             || ((ref[offset+byte] >= 'a')
              && (ref[offset+byte] <= 'z')))
                printf("%c", ref[offset+byte]);
            else
                printf(".");
        }
        printf("|$\n");
    }
}
