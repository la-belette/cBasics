#include "array_helper.h"
#include "memory_manager.h"

void array_print(int *array, size_t size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", array[i]);
    }
    printf("\n");
}

int *array_init(size_t size)
{
    if (size <= 0)
        return NULL;
    int *array = malloc(size*sizeof(int));
    return array;
}

void array_release(int *array)
{
    if (array != NULL)
    {
        free (array);
    }
}

void array_copy(int *src, int *dest, size_t size)
{
    if ((NULL != src) && (NULL != dest) && (0 != size))
    {
        for (int i = 0; i < size; i++)
        {
            dest[i] = src[i];
        }
    }
}

int *array_dup(int *array, size_t size)
{
    if (NULL == array)
    {
        return NULL;
    }
    int *duplicate = malloc(size*sizeof(int));
    for (int i = 0; i < size; i++)
    {
        duplicate[i] = array[i];
    }
    return duplicate;
}

int *array_cat(int *array1, int *array2, size_t offset, size_t size)
{
    if((NULL == array1) || (NULL == array2))
    {
        return NULL;
    }
    int *result = malloc((offset+size)*sizeof(int));
    for (int i = 0; i < offset; i++)
    {
        result[i] = array1[i];
    }
    for (int i = 0; i < size; i++)
    {
        result[offset+i] = array2;
    }
    return  result;
}

int array_nth(int *array, size_t nth)
{
    return array[nth - 1];
}

int array_find(int *array, size_t size, int n)
{
    if ((NULL == array) || (0 == size))
    {
        return -1;
    }
    for (int i = 0; i < size; i++)
    {
        if (n == array[i])
            return i;
    }
    return -1;
}

void array_sort(int *array, size_t size)
{
    if((NULL != *array)  && (size > 0))
    {
        /*
        if (size == 2)
        {
            int a = array[0];
            int b = array[1];
            if (array[0] > array[1])
            {
                swap(array, array + 1);
            }
        }
        else
        {
            int half_size = size / 2;
            int a = array[half_size];
            int b = array[half_size + 1];
            int c = array[half_size + 2];
            if (0 != size % 2)
            {
                if (array[half_size - 1] > array[half_size])
                {
                    swap(array + half_size - 1, array + half_size);
                }
                if (array[half_size] > array[half_size + 1])
                {
                    swap(array + half_size, array + half_size + 1);
                }
            }
            array_sort(array, half_size);
            array_sort(array + half_size, half_size);
        }
        */
        for (int i = 0; i < size-1; i++)
        {
            for (int j = 0; j < size - 1 - i; j++)
            {
                if (array[j] > array[j + 1])
                {
                    swap(array + j, array + j + 1);
                }
            }
        }
    }
}

void array_fibo(int *array, size_t size, size_t n)
{
    if ((NULL != array) && (n > 0))
    {
        int length = size < n ? size : n;
        array[0] = 0;
        if (1 <= length)
            array[1] = 1;
        if(2 <= length)
        {
            for (int i = 2; i < length; i++)
            {
                array[i] = array[i - 1] + array[i - 2];
            }
        }
    }
}
