#include "array_helper_tests.h"
#include "array_helper.h"
#include "memory_manager.h"

int test_array_init()
{
    int err = 0;

    int *array5 = array_init(5);
    if (NULL == array5)
    {
        printf("fail in %S: array allocation returns null.\n", __func__);
        err = -1;
    }

    int *nullarray = array_init(0);
    if (NULL != nullarray)
    {
        printf("fail in %S: null size array allocation returns pointer.\n", __func__);
        err = -1;
    }

    return err;
}

int test_release_array()
{
    int err = 0;

    int *array = array_init(10);
    if (NULL != array)
    {
        array_release(array);
    }

    array_release(NULL);

    return err;
}

int test_array_print()
{
    int err = 0;
    int size = 20;
    int *array = array_init(size);
    for (int i = 0; i < size; i++)
    {
        array[i] = size - i;
    }
    array_print(array, size);
    //TODO automize test verification
    return err;
}

int test_array_copy()
{
    int err = 0;
    int *arrayA = array_init(10);
    int *arrayB = array_init(8);

    for (int i = 0; i < 10; i++)
    {
        arrayA[i] = i;
        if (i < 8)
            arrayB[i] = 10 - i;
    }
    int expected_array[] = {0, 1, 2, 3, 4, 5, 6, 3};
    array_copy(arrayA, arrayB, 6);
    if (0 != memcmp(arrayB, expected_array, 8))
    {
        printf("fail in %s: partially copied array\n", __func__);
        array_print(arrayB, 8);
        printf("instead of expected\n");
        array_print(expected_array, 8);
        err = -1;
    }

    array_copy(NULL, arrayB, 122);
    if (0 != memcmp(arrayB, expected_array, 8))
    {
        printf("fail in %s: partially copied array\n", __func__);
        array_print(arrayB, 8);
        printf("instead of expected\n");
        array_print(expected_array, 8);
        err = -1;
    }

    return err;
}

int test_array_dup()
{
    int err = 0;

    int ref[] = {0, 1, 2, 3, 4, 5};
    int *result = array_dup(ref, 6);
    if (0 != memcmp(ref, result, 6))
    {
        printf("fail in %s: duplicate holds\n", __func__);
        array_print(result, 6);
        printf("instead of expected\n");
        array_print(ref, 6);
        printf("\n");
        err = -1;
    }
    int *result2 = array_dup(NULL, 6);
    if (NULL != result2)
    {
        printf("fail in %s: duplicate of null pointer is non null pointer\n", __func__);
        err = -1;
    }

    return err;
}

int test_arraycat()
{
    int err = 0;

    int arrayA[] = {10, 9, 8, 7, 3};
    int arrayB[] = {0, 2, 4 , 6, 12};
    int expected_result[] = {10, 9, 8, 0, 2, 4, 6, 12};
    int offset = 3;
    int length = 5;
    int *result = array_cat(arrayA, arrayB, offset, length);
    if (0 != memcmp(expected_result, result, offset+length))
    {
        printf("fail in %s: \n", __func__);
        array_print(arrayA, 5);
        printf("concatenated with\n");
        array_print(arrayB, 5);
        printf("from %d for %d returns\n", offset, length);
        array_print(result, offset+length);
        printf("instead of expected\n");
        array_print(expected_result, offset+length);
        err = -1;
    }
    int *nullarray = array_cat(arrayA, NULL, 10, 2);
    if (NULL != nullarray)
    {
        printf("fail in %s: null array concatenation returns non null pointer.\n", __func__);
        err = -1;
    }

    return err;
}

int test_array_nth()
{
    int err = 0;

    int arrayA[] = {10, 9, 8, 7, 3};
    int element = array_nth(arrayA, 3);
    if (arrayA[2] != element)
    {
        printf("fail in %s, element returned is %d instead of expected %d.\n",
                __func__,
                element,
                arrayA[2]);
        err = -1;
    }
    element = array_nth(arrayA, 5);
    if (arrayA[4] != element)
    {
        printf("fail in %s, element returned is %d instead of expected %d.\n",
               __func__,
               element,
               arrayA[4]);
        err = -1;
    }

    return err;
}

int test_array_find()
{
    int err = 0;

    int array[] = {20, 15, 8, 14, 8, 0, -321};
    int expected_result = 1;
    int result = array_find(array, 7, 15);
    if (result != expected_result)
    {
        printf("fail in %s: index returned %d instead of expected %d.\n",
                __func__,
                result,
                expected_result);
        err = -1;
    }
    expected_result = 6;
    result = array_find(array, 7, -321);
    if (result != expected_result)
    {
        printf("fail in %s: index returned %d instead of expected %d.\n",
               __func__,
               result,
               expected_result);
        err = -1;
    }
    expected_result = 2;
    result = array_find(array, 7, 8);
    if (result != expected_result)
    {
        printf("fail in %s: index returned %d instead of expected %d.\n",
               __func__,
               result,
               expected_result);
        err = -1;
    }

    expected_result = -1;
    result = array_find(array, 7, -10);
    if (result != expected_result)
    {
        printf("fail in %s: index returned %d instead of expected %d.\n",
               __func__,
               result,
               expected_result);
        err = -1;
    }
    result = array_find(array, 6, -321);
    if (result != expected_result)
    {
        printf("fail in %s: index returned %d instead of expected %d.\n",
               __func__,
               result,
               expected_result);
        err = -1;
    }
    result = array_find(array, 0, 8);
    if (result != expected_result)
    {
        printf("fail in %s: index returned %d instead of expected %d.\n",
               __func__,
               result,
               expected_result);
        err = -1;
    }
    result = array_find(NULL, 7, -10);
    if (result != expected_result)
    {
        printf("fail in %s: index returned %d instead of expected %d.\n",
               __func__,
               result,
               expected_result);
        err = -1;
    }

    return err;
}

int test_array_sort()
{
    int err = 0;
    int *array = array_init(8);
    array[0] = 10;
    array[1] = 8;
    array[2] = 9;
    array[3] = 2;
    array[4] = 5;
    array[5] = 3;
    array[6] = 75;
    array[7] = -1;

    int expected_result[] = {-1, 2, 3, 5, 8, 9, 10, 75};
    array_sort(array, 8);
    if (0 != memcmp(array, expected_result, 8))
    {
        printf("fail in %s: sorted array holds\n", __func__);
        array_print(array, 8);
        printf("instead of expected\n");
        array_print(expected_result, 8);
        err = -1;
    }

    return err;
}

int test_array_fibo()
{
    int err = 0;

    int *array = array_init(20);
    int expected_result[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34};
    array_fibo(array, 20, 9);
    if (0 != memcmp(array, expected_result, 10))
    {
        printf("fail in %s, %d first elements of fibo to rank %d returns\n",
                __func__,
                20,
                10);
        array_print(array, 10);
        printf("instead of expected\n");
        array_print(expected_result, 10);
        err = -1;
    }
    int *fibo20 = array_init(30);
    array_fibo(fibo20, 30, 20);
    array_print(fibo20, 20);

    return err;
}

int doubling(int target)
{
    return target*2;
}

int test_vector_map()
{
    int err = 0;
    int tab_size = 10;
    int *tab = malloc(tab_size*sizeof(int));

    for (int i = 0; i < tab_size; i ++)
    {
        tab[i] = i;
    }

    int ref[10] = {0, 2, 4, 6, 8, 10, 12, 14, 16 ,18};

    vector_map(&doubling, tab, tab_size);

    err = memcmp(tab, ref, tab_size* sizeof(int));
    if (0 != err)
    {
        printf("fail in %s:\n",
               __func__);
        array_print(tab, tab_size);
        printf("instead of expected\n");
        array_print(ref, tab_size);
        err = -1;
    }

    free(tab);
    return err;
}

int test_array()
{
     int err = 0;

     err += test_array_init();
     err += test_release_array();
     err += test_array_print();
     err += test_array_dup();
     err += test_arraycat();
     err += test_array_nth();
     err += test_array_find();
     err += test_array_sort();
     err += test_array_fibo();
     err += test_vector_map();

     return err;
}
