#include "memory_manager_tests.h"
#include "memory_manager.h"
#include "string_helper.h"
#include "utils.h"
#include "common.h"

#include <string.h>

int test_memswap()
{
    int err = 0;

    char * juju = "juj";
    uint32_t ageJuju = 29;
    char* boby = "boby";
    uint32_t ageBoby = 92;

    char* expected_juju = "boby";
    char* expected_boby = "juj";
    memswap(&juju, &boby, size_char_array(juju));
    if ((0 != strcmp(juju, expected_juju)) || (0 != strcmp(boby, expected_boby)))
    {
        printf("fail in %s: swap result: #1 %s - #2 %s instead of expected #1 %s - #2 %s\n", __func__, juju, boby, expected_juju, expected_boby);
        err = -1;
    }

    int expected_agejuju = ageBoby;
    int expected_ageboby = ageJuju;
    memswap(&ageJuju, &ageBoby, sizeof(ageJuju));
    if ((ageJuju != expected_agejuju) || (ageBoby != expected_ageboby))
    {
        printf("fail in %s: swap result: juju %d - boby %d instead of juju %d - boby %d\n", __func__, ageJuju, ageBoby, expected_agejuju, expected_ageboby);
        err = -1;
    }

    int inputA[] = {0, 1, 2, 3, 4, 5, 6};
    int inputB[] = {6, 5, 4, 3, 2};
    int expected_outputA[] = {6, 5, 4, 3, 4, 5, 6};
    int expected_outputB[] = {0, 1, 2, 3, 2};

    memswap(inputA, inputB, 3*sizeof(int));
    if ((0 != memcmp(inputA, expected_outputA, 7))
        || (0 != memcmp(inputB, expected_outputB, 5)))
    {
        printf("fail in %s: #1 %s - #2 %s instead of expected #1 %s - #2 %s\n",
                __func__,
                inputA,
                inputB,
                expected_outputA,
                expected_outputB);
        err = -1;
    }

    return err;
}

int test_remalloc()
{
    int err = 0;

    char *array = "Job done!";
    char *expected_smallCopy = "Job don";
    char* smallerCopy = remalloc((void*)array, size_char_array(array), 7*sizeof(char));
    if (0 != strcmp(smallerCopy, expected_smallCopy))
    {
        printf("fail in %s: smaller copy holds: %s instead of expected %s\n",
                smallerCopy,
                expected_smallCopy);
        err = -1;
    }
    free(smallerCopy);

    char *expected_largeCopy = "Job done!";
    char* largerCopy = remalloc((void*)array, size_char_array(array)+1, 20*sizeof(char));
    if (0 != strcmp(largerCopy, expected_largeCopy))
    {
        printf("fail in %s: larger copy holds: %s instead of expected %s\n",
                largerCopy,
                expected_largeCopy);
        err = -1;
    }
    free(largerCopy);

    return err;
}

int test_my_realloc()
{
    int err = 0;

    size_t ref_size = 7;
    int *ref = (int*)malloc(ref_size* sizeof(int));
    for (int i = 0; i < ref_size; i++)
    {
        ref[i] = 2*i;
    }

    int expected_largeArray[] = {0, 2, 4, 6, 8, 10, 12, 0, 0, 0};
    int *largerArray = (int*)my_realloc((void*)ref, 10*sizeof(int), ref_size*sizeof(int));
    if (0 != memcmp(largerArray, expected_largeArray, 10))
    {
        printf("fail in %s: larger array holds: ", __func__);
        print_int_array(largerArray, 10);
        printf("instead of expected:\n");
        print_int_array(expected_largeArray, 10);
        err = -1;
    }

    int expected_smallArray[] = {0, 2, 4, 6, 8};
    int *smallerArray = (int*)my_realloc((void*)largerArray, 5*sizeof(int), 10* sizeof(int));
    if (0 != memcmp(smallerArray, expected_smallArray, 10))
    {
        printf("fail in %s: smaller array holds: ", __func__);
        print_int_array(smallerArray, 10);
        printf(" instead of expected ");
        print_int_array(expected_smallArray, 10);
        err = -1;
    }

    free(smallerArray);
    return err;
}

int test_my_memset()
{
    int err = 0;

    size_t ref_size = 7;
    int *ref = (int*)malloc(ref_size* sizeof(int));
    for (int i = 0; i < ref_size; i++)
    {
        ref[i] = 2*i;
    }

    uint8_t ones[28];
    for (int byte = 0; byte < 28; byte++)
    {
        ones[byte] = 1;
    }
    ref = my_memset(ref, 1, ref_size* sizeof(int));
    if (0 != memcmp(ref, ones, 28))
    {
        printf("fail in %s: ones is\n", __func__);
        print_int_array(ref, ref_size);
        printf("instead of expected\n");
        print_int_array(ones, 7);
        err = -1;
    }

    int* smallerArray = (int*)calloc(5, sizeof(int));
    int oneref = 0;
    for (int byte = 0; byte < sizeof(int); byte++)
    {
        oneref += 01<<(8*byte);
    }
    int smallref[] = {oneref, oneref, oneref, 0, 0};
    smallerArray = my_memset(smallerArray, 1, 3* sizeof(int));
    if (0 != memcmp(smallerArray, smallref, 20))
    {
        printf("fail in %s: zeros\n", __func__);
        print_int_array(smallerArray, 5);
        printf("instead of expected\n");
        print_int_array(smallref, 5);
        err = -1;
    }

    free(smallerArray);
    return err;
}

int test_my_memcpy()
{
    int err = 0;

    size_t ref_size = 7;
    int *ref = (int*)malloc(ref_size* sizeof(int));
    for (int i = 0; i < ref_size; i++)
    {
        ref[i] = 2*i;
    }

    int*arrayCopy = (int*)malloc(ref_size*sizeof(int));
    arrayCopy = my_memcpy((void*)arrayCopy, ref, ref_size*sizeof(int));
    if (0 != memcmp(arrayCopy, ref, ref_size* sizeof(int)))
    {
        printf("fail in %s: copy\n", __func__);
        print_int_array(arrayCopy, ref_size);
        printf("instead of expected\n");
        print_int_array(ref, ref_size);
        err = -1;
    }

    int*arraySmallerCopy = (int*)malloc(4*sizeof(int));
    int smallref[] = {0, 2, 4, 6, 8};
    arraySmallerCopy = my_memcpy((void*)arraySmallerCopy, ref, 5*sizeof(int));
    if (0 != memcmp(arrayCopy, smallref, 20))
    {
        printf("fail in %s: smaller copy\n", __func__);
        print_int_array(arrayCopy, 5);
        printf("instead of expected\n");
        print_int_array(smallref, 5);
        err = -1;
    }

    free(arrayCopy);
    free(arraySmallerCopy);
    return err;
}

int test_swap()
{
    int err = 0;

    int a = 2;
    int b = 3;
    int expected_a = b;
    int expected_b = a;
    swap(&a, &b);
    if ((a != expected_a) || (b != expected_b))
    {
        printf("fail in %s: after swap state a: %d - b: %d instead of expected a: %s - b: %s\n",
                __func__,
                a,
                b,
                expected_a,
                expected_b);
        err = -1;
    }

    return err;
}

int test_my_memmove()
{
    int err = 0;

    size_t array_size = 7;
    int *array = (int *)malloc(array_size*sizeof(int));
    for (int element = 0; element < array_size; element++)
    {
        array[element] = element;
    }
    int ref[] = {3, 4, 5, 6, 4, 5, 6};
    array = my_memmove(array, array+3, 4* sizeof(int));
    if (0 != memcmp(array, ref, array_size* sizeof(int)))
    {
        printf("fail in %s:\n", __func__);
        print_int_array(array, array_size);
        printf("instead of expected \n");
        print_int_array(ref, array_size);
        err = -1;
    }
    return err;
}

int test_memory_management()
{
    int err = 0;

    err += test_swap();
    err += test_memswap();
    err += test_remalloc();
    err += test_my_realloc();
    err += test_my_memset();
    err += test_my_memcpy();
    err += test_my_memmove();

    return err;
}