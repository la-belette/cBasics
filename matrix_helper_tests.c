#include "matrix_helper_tests.h"
#include "matrix_helper.h"

int test_matadd()
{
    int err = 0;

    int **matA;
    int **matB;
    int **matC;

    initMat(&matA, MAT_HEIGHT, MAT_WIDTH);
    initMat(&matB, MAT_HEIGHT, MAT_WIDTH);
    initMat(&matC, MAT_HEIGHT, MAT_WIDTH);

    for (int i = 0; i < MAT_HEIGHT; i++) {
        for (int j = 0; j < MAT_WIDTH; j++) {
            matA[i][j] = 1;
            matB[i][j] = i + j;
        }
    }
    
    matC = matadd(matA, matB, matC);
    printf("matA:\n");
    printMat(matA, MAT_HEIGHT, MAT_WIDTH);
    printf("matB:\n");
    printMat(matB, MAT_HEIGHT, MAT_WIDTH);
    printf("matC = matA + matB:\n");
    printMat(matC, MAT_HEIGHT, MAT_WIDTH);

    matfree(matA, MAT_HEIGHT);
    matfree(matB, MAT_HEIGHT);
    matfree(matC, MAT_HEIGHT);
    return err;
}

int test_matsub()
{
    int err = 0;

    int **matA;
    int **matB;
    int **matC;

    initMat(&matA, MAT_HEIGHT, MAT_WIDTH);
    initMat(&matB, MAT_HEIGHT, MAT_WIDTH);
    initMat(&matC, MAT_HEIGHT, MAT_WIDTH);

    for (int i = 0; i < MAT_HEIGHT; i++) {
        for (int j = 0; j < MAT_WIDTH; j++) {
            matA[i][j] = 1;
            matB[i][j] = i + j;
        }
    }

    matC = matsub(matB, matA, matC);
    printf("matC = matB - matA:\n");
    printMat(matC, MAT_HEIGHT, MAT_WIDTH);

    matfree(matA, MAT_HEIGHT);
    matfree(matB, MAT_HEIGHT);
    matfree(matC, MAT_HEIGHT);

    return err;
}

int test_matmul()
{
    int err = 0;

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

    matfree(matD, MAT_HEIGHT);
    matfree(matE, MAT_COMMON);
    matfree(matR, MAT_HEIGHT);
    return err;
}

int test_matscalmul()
{
    int err = 0;

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

    matR = matscalmul(matD, 2, matR);
    printf("matD * 2:\n");
    printMat(matR, MAT_HEIGHT, MAT_COMMON);

    matfree(matD, MAT_HEIGHT);
    matfree(matE, MAT_COMMON);
    matfree(matR, MAT_HEIGHT);
    return err;
}

int test_matalloc()
{
    int err = 0;

    int **matT = matalloc(MAT_COMMON, 6);
    printf("Test allocating square matrix filled with constant:\n");
    printMat(matT, MAT_COMMON, MAT_COMMON);

    matfree(matT, MAT_COMMON);
    return err;
}

int test_matrix_helper()
{
    int err = 0;

    if (0 != test_matadd())
        err = -1;

    if (0 != test_matsub())
        err = -1;

    if (0 != test_matmul())
        err = -1;

    if (0 != test_matscalmul())
        err = -1;

    if (0 != test_matalloc())
        err = -1;

    return err;
}