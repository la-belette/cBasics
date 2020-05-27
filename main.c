#include "common.h"
#include "string_helper.h"
#include "matrix_helper.h"
#include "memory_manager.h"
#include "calendar_helper.h"

#define STRING_TEST
#define MATRIX_TEST
#define MEMORY_MGT_TEST
#define CALENDAR_TEST
#define SWAP_TEST

void printArray(int *array, size_t size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", array[i]);
    }
    printf("\n");
}

int main(void)
{
#ifdef SWAP_TEST
    printf("\n*******************************************************\n");
    printf("                      SWAP TEST                        \n");
    printf("*******************************************************\n\n");

    int a = 2;
    int b = 3;

    printf("initial state: %d, %d\n",a, b);
    swap(&a, &b);
    printf("after swap state: %d, %d\n",a, b);
#endif

#ifdef STRING_TEST
    printf("\n*******************************************************\n");
    printf("                     STRING TEST                       \n");
    printf("*******************************************************\n\n");

    printf("coucou has a length of %d.\n", sizeOfCharArray("coucou"));

    printf("Is kayak a plindrome? %d\n", isPalindrome("kayak"));
    printf("Is \"la mariee ira mal\" a palindrome? %d\n", isPalindrome("la mariee ira mal"));
    printf("Is toto a palindrome permutation? %d\n", isPalindromePermutation("toto"));
    printf("Is tatie a palindrome permutation? %d\n", isPalindromePermutation("tatie"));


    char *str = "Hihihi!";
    char *string = reverse(str);
    printf("%s reversed becomes %s.\n", str, string);

    int verif = raiseit(string);
    printf("%s already contained %d capital letter(s) & becomes %s once reversed & raised.\n", str, verif, string);
#endif

#ifdef CALENDAR_TEST
    printf("\n*******************************************************\n");
    printf("                    CALENDAR TEST                      \n");
    printf("*******************************************************\n\n");

    printf("7 days after Monday is: %s\n",getWeekDay("Mon", 7));
    printf("3 days after Wednesday is: %s\n",getWeekDay("Wed", 3));
    printf("0 days after Monday is: %s\n",getWeekDay("Mon", 0));
    printf("21 days after Sunday is: %s\n",getWeekDay("Sun", 7));
    printf("284 days after _ is: %s\n",getWeekDay("", 284));

    printf("There is/are %d odd letter(s) in kayak\n", numberOfOddLetter("kayak", 5));
    printf("There is/are %d odd letter(s) in turlututu\n", numberOfOddLetter("turlututu", 9));
    printf("There is/are %d odd letter(s) in toto\n", numberOfOddLetter("toto", 4));
    printf("There is/are %d odd letter(s) in ?!./\n", numberOfOddLetter("?!./", 4));
    printf("There is/are %d odd letter(s) in _\n", numberOfOddLetter("", 0));
#endif

#ifdef MEMORY_MGT_TEST
    printf("\n*******************************************************\n");
    printf("                MEMORY MANAGEMENT TEST                 \n");
    printf("*******************************************************\n\n");

    char * juju = "juj";
    uint32_t ageJuju = 29;
    char* boby = "boby";
    uint32_t ageBoby = 92;

    printf("intial state: #1 %s - #2 %s\n", juju, boby);
    memswap(&juju, &boby, sizeOfCharArray(juju));
    printf("swap result: #1 %s - #2 %s\n", juju, boby);

    printf("initial state: juju %d - boby %d\n", ageJuju, ageBoby);
    memswap(&ageJuju, &ageBoby, sizeof(ageJuju));
    printf("swap result: juju %d - boby %d\n", ageJuju, ageBoby);

    /*
    printf("initial state name: %s, age: %d\n", juju, ageJuju);
    memswap(&juju, &ageJuju, sizeOfCharArray(juju));
    uint32_t juju2 = (uint32_t)juju;
    char* age2 = &ageJuju;
    printf("swap result name: %s, age: %d\n", age2, juju2);
    */

    int arrayA[] = {0, 1, 2, 3, 4, 5, 6};
    int arrayB[] = {6, 5, 4, 3, 2};

    printf("initial state:\n");
    printArray(arrayA, 7);
    printArray(arrayB, 5);

    memswap(arrayA, arrayB, 3);

    printf("partial swap result:\n");
    printArray(arrayA, 7);
    printArray(arrayB, 5);

    char* array = "Job done!";
    char* copy = remalloc((void*)array, 10, 20);
    printf("copy holds: %s\n", copy);
    char* copycopy = remalloc((void*)array, 10, 8);
    printf("copycopy holds: %s\n", copycopy);

    printf("initial state arrayA:\n");
    printArray(arrayA,7);
    void* newArray = my_realloc((void*)arrayA, 5*sizeof(int), 7*sizeof(int));
    printf("smaller alloc:\n");
    printArray((int*)newArray, 7);
    void* newArray2 = my_realloc((void*)arrayA, 10*sizeof(int), 7*sizeof(int));
    printf("larger alloc:\n");
    printArray((int*)newArray2, 10);


#endif

#ifdef MATRIX_TEST
    printf("\n*******************************************************\n");
    printf("                     MATRIX TEST                       \n");
    printf("*******************************************************\n\n");

    int **matA;
    int **matB;
    int **matC;

    initMat(&matA, MAT_HEIGHT, MAT_WIDTH);
    initMat(&matB, MAT_HEIGHT, MAT_WIDTH);
    initMat(&matC, MAT_HEIGHT, MAT_WIDTH);

    for (int i = 0; i < MAT_HEIGHT; i ++)
    {
        for (int j = 0; j < MAT_WIDTH; j ++)
        {
            matA[i][j] = 1;
            matB[i][j] = i + j;
        }
    }

    printf("matA:\n");
    printMat(matA, MAT_HEIGHT, MAT_WIDTH);
    printf("matB:\n");
    printMat(matB, MAT_HEIGHT, MAT_WIDTH);

    matC = matadd(matA, matB, matC);
    printf("matC = matA + matB:\n");
    printMat(matC, MAT_HEIGHT, MAT_WIDTH);

    matC = matsub(matB, matA, matC);
    printf("matC = matB - matA:\n");
    printMat(matC, MAT_HEIGHT, MAT_WIDTH);

    int **matD;
    initMat(&matD, MAT_HEIGHT, MAT_COMMON);
    fillMat(&matD, MAT_HEIGHT, MAT_COMMON);
    printf("matD:\n");
    printMat(matD, MAT_HEIGHT, MAT_COMMON);

    int **matE;
    initMat(&matE, MAT_COMMON, MAT_WIDTH);
    fillMat(&matE, MAT_COMMON, MAT_WIDTH);
    printf("matE:\n");
    printMat(matE, MAT_COMMON, MAT_WIDTH);

    int **matR;
    initMat(&matR, MAT_HEIGHT, MAT_WIDTH);

    matR = matmul(matD, matE, matR);
    printf("matR = matD * matE:\n");
    printMat(matR, MAT_HEIGHT, MAT_WIDTH);

    matR = matscalmul(matD, 2, matR);
    printf("matD * 2:\n");
    printMat(matR, MAT_HEIGHT, MAT_COMMON);

    int **matT = matalloc(MAT_COMMON, 6);
    printf("Test allocating square matrix filled with constant:\n");
    printMat(matT, MAT_COMMON, MAT_COMMON);

    matfree(matT, 4);
#endif

    return (0);
}
