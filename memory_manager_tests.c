#include "memory_manager_tests.h"
#include "memory_manager.h"
#include "string_helper.h"

void printArray(int *array, size_t size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", array[i]);
    }
    printf("\n");
}

int test_memswap()
{
    char * juju = "juj";
    uint32_t ageJuju = 29;
    char* boby = "boby";
    uint32_t ageBoby = 92;

    printf("intial state: #1 %s - #2 %s\n", juju, boby);
    memswap(&juju, &boby, size_char_array(juju));
    printf("swap result: #1 %s - #2 %s\n", juju, boby);

    printf("initial state: juju %d - boby %d\n", ageJuju, ageBoby);
    memswap(&ageJuju, &ageBoby, sizeof(ageJuju));
    printf("swap result: juju %d - boby %d\n", ageJuju, ageBoby);

/*
    printf("initial state name: %s, age: %d\n", juju, ageJuju);
    memswap(&juju, &ageJuju, size_char_array(juju));
    uint32_t juju2 = (uint32_t)juju;
    char* age2 = &ageJuju;
    printf("swap result name: %s, age: %d\n", age2, juju2);
*/
    int arrayA[] = {0, 1, 2, 3, 4, 5, 6};
    int arrayB[] = {6, 5, 4, 3, 2};

    printf("initial state:\n");
    printArray(arrayA, 7);
    printArray(arrayB, 5);

    memswap(arrayA, arrayB, 3*sizeof(int));

    printf("partial swap result:\n");
    printArray(arrayA, 7);
    printArray(arrayB, 5);
    return 0;
}

int test_remalloc()
{
    char* array = "Job done!";
    printf("reference array holds: %s\n", array);
    char* smallerCopy = remalloc((void*)array, size_char_array(array), 7*sizeof(char));
    printf("smaller copy holds: %s\n", smallerCopy);
    free(smallerCopy);

    char* largerCopy = remalloc((void*)array, size_char_array(array)+1, 20*sizeof(char));
    printf("larger copy holds: %s\n", largerCopy);
    free(largerCopy);

    return 0;
}

int test_my_realloc()
{
    size_t ref_size = 7;
    int *ref = (uint8_t*)malloc(ref_size* sizeof(int));
    for (int i = 0; i < ref_size; i++)
    {
        ref[i] = 2*i;
    }
    printf("ref:\n");
    printArray(ref,7);

    int* largerArray = (int*)my_realloc((void*)ref, 10*sizeof(int), ref_size*sizeof(int));
    printf("larger alloc:\n");
    printArray(largerArray, 10);

    int* smallerArray = (int*)my_realloc((void*)largerArray, 5*sizeof(int), 10* sizeof(int));
    printf("smaller alloc:\n");
    printArray(smallerArray, 5);

    free(smallerArray);
    return 0;
}

int test_my_memset()
{
    size_t ref_size = 7;
    int *ref = (uint8_t*)malloc(ref_size* sizeof(int));
    for (int i = 0; i < ref_size; i++)
    {
        ref[i] = 2*i;
    }

    ref = my_memset(ref, 1, ref_size* sizeof(int));
    printf("smaller array with all bytes at 1:\n");
    printArray(ref, ref_size);

    int* smallerArray = (int*)malloc(5*sizeof(int));

    smallerArray = my_memset(smallerArray, 0, 3* sizeof(int));
    printf("smaller array with 3 first elements cleared:\n");
    printArray(smallerArray, 5);

    int*arrayCopy = (int*)malloc(5*sizeof(int));
    arrayCopy = my_memcpy((void*)arrayCopy, smallerArray, 5*sizeof(int));
    printf("copy of smaller array\n");
    printArray(arrayCopy, 5);

    int*arraySmallerCopy = (int*)malloc(4*sizeof(int));
    arraySmallerCopy = my_memcpy((void*)arraySmallerCopy, smallerArray, 4*sizeof(int));
    printf("smaller copy of smaller array\n");
    printArray(arraySmallerCopy, 4);

    free(smallerArray);
    free(arrayCopy);
    free(arraySmallerCopy);
    return 0;
}

int test_swap()
{
    int a = 2;
    int b = 3;

    printf("initial state: %d, %d\n",a, b);
    swap(&a, &b);
    printf("after swap state: %d, %d\n",a, b);

    return 0;
}

int test_memory_management()
{
    int result = 0;

    if (0 != test_swap())
        result = -1;

    if (0 != test_memswap())
        result = -1;

    if (0 != test_remalloc())
        result = -1;

    if (0 != test_my_realloc())
        result = -1;

    if(0 != test_my_memset())
        result = -1;

    return result;
}