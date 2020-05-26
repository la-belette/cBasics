#include "matrix_helper.h"
#include "common.h"

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
