#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <string.h>

#define MAX_DIFF_CHAR 26
#define MAT_HEIGHT 3
#define MAT_WIDTH 2
#define MAT_COMMON MAT_WIDTH

int sizeOfCharTable(char* table)
{
    int size = 0;
    while(table[size] != '\0')
    {
        size++;
    }
    return size;
}

void swap(int *a,
          int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int mystrlen(const char *s)
{
    char *c = s;
    int size = 0;
    while(*c != '\0')
    {
        c++;
        size++;
    }
    return size;
}

int isPalindrome(const char *s)
{
    char *a = s;
    char *b = s + mystrlen(s);
    while((a != b) && (a < b))
    {
        if ((*a < 'A')
        || ((*a > 'Z') && (*a < 'a'))
        || (*a > 'z'))
        {
            a++;
            continue;
        }
        if ((*b < 'A')
        || ((*b > 'Z') && (*b < 'a'))
        || (*b > 'z'))
        {
            b--;
            continue;
        }
        if((*a != *b)
        && (*a != (*b - 'a' + 'A'))
        && ((*a - 'a' + 'A') != *b))
            return -1;
        a++;
        b--;
    }
    return 0;
}

int isPalindromePermutation(const char *s)
{
    char *c;
    int stringSize = mystrlen(s);

    int array[MAX_DIFF_CHAR] = {0};
    for (int i = 0; i < stringSize; i++)
    {
        char c = *(s+i);
        if ((c > 'A') && (c < 'Z'))
        {
            array[c-'A']++;
        }
        else if ((c > 'a') && (c < 'z'))
        {
            array[c -'a']++;
        }
    }

    int oddLettersCount = 0;
    for (int i = 0; i < MAX_DIFF_CHAR; i++)
    {
        if((array[i]%2) == 1)
        {
            oddLettersCount++;
        }
    }

    if (oddLettersCount>1)
        return -1;
    else
        return 0;
}

char *reverse(char *s)
{
    char *result = (char*)malloc(30* sizeof(char));
    int size = mystrlen(s);
    for (int i = 0; i < size; i++)
    {
        result[i] = *(s + size - i - 1);
    }
    result[size] = '\0';
    return result;
}

int raiseit(char *s)
{
    size_t charLength = mystrlen(s);
    char c = 0;
    int majCount = 0;
    for (int i = 0; i < charLength; i ++)
    {
        c = *(s + i);
        if ((c <= 'z') && (c >= 'a'))
            *(s + i) -= 'a' - 'A';
        else if ((c <= 'Z') && (c >= 'A'))
            majCount ++;
    }
    return majCount;
}

char* getWeekDay (char* currentDay, int delay)
{
    static char* weekDays[] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
    int numberOfWeekDays = 7;

    for (int i = 0; i < numberOfWeekDays; i++)
    {
        if (0 == strcmp(currentDay, weekDays[i]))
        {
            return  weekDays[(delay + i) % numberOfWeekDays];
        }
    }
    return "Not a correct day";
}

int numberOfOddLetter (char* string, int length)
{
    int charMem[MAX_DIFF_CHAR] = {0};
    int c = 0;

    for (int i = 0; i < length; i ++)
    {
        if((string[i] < 'z') && (string[i] > 'a'))
        {
            c = string[i] - 'a';
        }
        else if ((string[i] < 'Z') && (string[i] > 'A'))
        {
            c = string[i] - 'A';
        } else
        {
            continue;
        }
        charMem[c]++;
    }

    int oddLetters = 0;

    for (int i = 0; i < MAX_DIFF_CHAR; i++)
    {
        if (charMem[i] % 2 != 0)
            oddLetters ++;
    }

    return oddLetters;
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

int **matadd(const int** a,
             const int** b,
             int** r)
{
    for(int i = 0; i < MAT_HEIGHT; i++)
    {
        for (int j = 0; j < MAT_WIDTH; j++)
        {
            r[i][j] = a[i][j] + b[i][j];
        }
    }
    return r;
}

int **matsub(const int** a,
             const int** b,
             int** r)
{
    for(int i = 0; i < MAT_HEIGHT; i++)
    {
        for (int j = 0; j < MAT_WIDTH; j++)
        {
            r[i][j] = a[i][j] - b[i][j];
        }
    }
    return r;
}

void printMat(int **mat, size_t height, size_t width)
{
    for (int i = 0; i < height; i ++)
    {
        for (int j = 0; j < width; j ++)
        {
            int temp = mat[i][j];
            printf("%d\t", temp);
        }
        printf("\n");
    }
}

int **matalloc(unsigned int n,
               int v)
{
    int **mat;
    mat = malloc(n*sizeof(*mat));
    for (int row = 0; row < n ; row ++)
    {
        mat[row] = malloc(n*sizeof(int));
        for (int column = 0; column < n; column++)
        {
            mat[row][column] = v;
        }
    }

    return mat;
}

void initMat(int ***mat, size_t height, size_t width)
{
    *mat = malloc(height * sizeof(**mat));

    for (int row = 0; row < height; row++)
    {
        (*mat)[row] = malloc(width * sizeof(***mat));
    }
}

void fillMat(int ***mat, size_t height, size_t width)
{
    int incr = 0;
    for (int i = 0; i < height; i ++)
    {
        for (int j = 0; j < width; j ++)
        {
            (*mat)[i][j] = incr++;
        }
    }
}

void printArray(int *array, size_t size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", array[i]);
    }
    printf("\n");
}

void clearMat(int ***mat, size_t height, size_t width)
{
    for (int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            (*mat)[i][j] = 0;
        }
    }
}

int **matmul(const int** a,
             const int** b,
             int** r)
{
    clearMat(&r, MAT_HEIGHT, MAT_WIDTH);

    for (int i = 0; i < MAT_HEIGHT; i++)
    {
        for (int j = 0; j < MAT_WIDTH; j++)
        {
            for (int k = 0; k < MAT_COMMON; k++)
            {
                r[i][j] += a[i][k]*b[k][j];
            }
        }
    }

    return r;
}

int **matscalmul(const int** a,
                 int b,
                 int** r)
{
    for (int i = 0; i < MAT_HEIGHT; i++)
    {
        for (int j = 0; j < MAT_WIDTH; j++)
        {
            r[i][j] = b*a[i][j];
        }
    }
    return r;
}

void matfree(int **m,
             unsigned int n)
{
    for (int row = 0; row < n; row++)
    {
        free(m[row]);
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

int main(void)
{
    /*
    int i = 0;
    func(&i);
    printf("%i\n", i);
    */

//    int a = 2;
//    int b = 3;
//    int c = 4;
//    test(&a, b, c);
//    printf("%d\n", a);
//
//    printf("%d, %d\n",a, b);
//    swap(&a, &b);
//    printf("%d, %d\n",a, b);
/*
    char *plop = "coucou";
    printf("%d",mystrlen("coucou"));

    printf("%d\n", isPalindrome("kayak"));
    printf("%d\n", isPalindrome("la mariee ira MAL"));
    printf("%s\n", isPalindromePermutation("toto"));
    printf("%d\n", isPalindromePermutation("tatie"));


    char *str = "Hihihi!";
    printf("%s\n", str);
    char *string = reverse(str);
    printf("%s\n",string);
    printf("%s\n", "c'est bon?");
    int verif = raiseit(string);
    printf("%s already contained %d capital letter(s)\n", string, verif);

    printf("The day 7 days after Monday is: %s\n",getWeekDay("Mon", 7));
    printf("The day 3 days after Wednesday is: %s\n",getWeekDay("Wed", 3));
    printf("The day 0 days after Monday is: %s\n",getWeekDay("Mon", 0));
    printf("The day 21 days after Sunday is: %s\n",getWeekDay("Sun", 7));
    printf("The day 284 days after _ is: %s\n",getWeekDay("", 284));

    printf("there are %d odd letters in kayak\n", numberOfOddLetter("kayak", 5));
    printf("there are %d odd letters in turlututu\n", numberOfOddLetter("turlututu", 9));
    printf("there are %d odd letters in toto\n", numberOfOddLetter("toto", 4));
    printf("there are %d odd letters in ?!./\n", numberOfOddLetter("?!./", 4));
    printf("there are %d odd letters in _\n", numberOfOddLetter("", 0));
    char * juju = "juj";
    uint32_t age = 29;

    char* test = "lala";
    printf("#1 name: %s, age: %d\n", juju, age);
    memswap(&juju, &age, 4);

    uint32_t juju2 = (uint32_t)juju;
    char* age2 = &age;
    printf("#3 name: %s, age: %d\n", age2, juju2);

    int tabA[] = {0, 1, 2, 3, 4, 5, 6};
    int tabB[] = {6, 5, 4, 3, 2};

    printf("initial state:\n");
    printArray(tabA, 7);
    printArray(tabB, 5);

    memswap(tabA, tabB, 16);

    printf("final state:\n");
    printArray(tabA, 7);
    printArray(tabB, 5);


    int **matA;
    int **matB;

    initMat(matA);
    initMat(matB);

    for (int i = 0; i < MAT_HEIGHT; i ++)
    {
        for (int j = 0; j < MAT_WIDTH; j ++)
        {
            matA[i][j] = 1; // i + j;
            matB[i][j] = i + j;
        }
    }

    //fillMat(&matA);
    //fillMat(&matB);

    printMat(matA);
    printMat(matB);

    int **matC = malloc(MAT_HEIGHT * MAT_WIDTH * sizeof(int));
    matadd(matA, matB, matC);
    printMat(matC);*/


    int **matA;
    initMat(&matA, MAT_HEIGHT, MAT_COMMON);
    fillMat(&matA, MAT_HEIGHT, MAT_COMMON);
    printf("matA:\n");
    printMat(matA, MAT_HEIGHT, MAT_COMMON);

    int **matB;
    initMat(&matB, MAT_COMMON, MAT_WIDTH);
    fillMat(&matB, MAT_COMMON, MAT_WIDTH);
    printf("matB:\n");
    printMat(matB, MAT_COMMON, MAT_WIDTH);

    int **matR;
    initMat(&matR, MAT_HEIGHT, MAT_WIDTH);
    /*
    matR = matadd(matA, matB, matR);
    printMat(matR, MAT_HEIGHT, MAT_WIDTH);

    matR = matsub(matB, matA, matR);
     */
    matR = matmul(matA, matB, matR);
    printf("matR:\n");
    printMat(matR, MAT_HEIGHT, MAT_WIDTH);

    matR = matscalmul(matA, 2, matR);
    printf("matAx2:\n");
    printMat(matR, MAT_HEIGHT, MAT_WIDTH);

    int **matT = matalloc(4, 6);
    printf("Test allocating squarre matrix filled with constant:\n");
    printMat(matT, 4, 4);

    matfree(matT, 4);

    char* str = "Job done!";
    char* copy = remalloc((void*)str, 10, 20);
    printf("copy holds: %s\n", copy);
    char* copycopy = remalloc((void*)str, 10, 8);
    printf("copycopy holds: %s\n", copycopy);

    return (0);
}
