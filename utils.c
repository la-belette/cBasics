#include "utils.h"

#include <string.h>

void print_int_array(int *array, size_t size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", array[i]);
    }
    printf("\n");
}
