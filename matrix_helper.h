#ifndef CBASICS_MATRIX_HELPER_H
#define CBASICS_MATRIX_HELPER_H

#include <limits.h>

int **matadd(const int** a,
             const int** b,
             int** r);

int **matsub(const int** a,
             const int** b,
             int** r);

void printMat(int **mat, size_t height, size_t width);

int **matalloc(unsigned int n,
               int v);

void initMat(int ***mat, size_t height, size_t width);

void fillMat(int ***mat, size_t height, size_t width);

void clearMat(int ***mat, size_t height, size_t width);

int **matmul(const int** a,
             const int** b,
             int** r);

int **matscalmul(const int** a,
                 int b,
                 int** r);

void matfree(int **m,
             unsigned int n);

#endif //CBASICS_MATRIX_HELPER_H
