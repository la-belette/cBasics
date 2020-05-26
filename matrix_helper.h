#ifndef CBASICS_MATRIX_HELPER_H
#define CBASICS_MATRIX_HELPER_H

#include "common.h"

/*
 * matadd adds two matrix.
 * @param a: first matrix
 * @param b: second matrix to add to a
 * @param r: resulting matrix to fill with result
 * @return the resulting matrix of a + b
 */
int **matadd(const int** a,
             const int** b,
             int** r);

/*
 * matsub subtracts two matrix.
 * @param a: first matrix
 * @param b: second matrix to subtract to a
 * @param r: resulting matrix to fill with result
 * @return the resulting matrix of a - b
 */
int **matsub(const int** a,
             const int** b,
             int** r);

/*
 * printMat prints matrix mat of height * width.
 * @param mat: target matrix to print
 * @param height: first dimension of mat
 * @param width: second dimension of mat
 */
void printMat(int **mat, size_t height, size_t width);

/*
 * matalloc allocates memory for a n*n matrix filled with v.
 * @param n: matrix dimension height = width
 * @param v: constant to fill the matrix with
 * @return the n*n matrix filled with v
 */
int **matalloc(unsigned int n,
               int v);

/*
 * initMat allocates memory for a height*width matrix.
 * @param mat: pointer to the target matrix of type **int
 * @param height: target matrix first dimension
 * @param width: target matrix second dimension
 */
void initMat(int ***mat, size_t height, size_t width);

/*
 * fillMat fills a height*width matrix with increasing integer.
 * @param mat: pointer to the target matrix of type **int
 * @param height: target matrix first dimension
 * @param width: target matrix second dimension
 */
void fillMat(int ***mat, size_t height, size_t width);

/*
 * clearMat fills a height*width matrix with zeros.
 * @param mat: pointer to the target matrix of type **int
 * @param height: target matrix first dimension
 * @param width: target matrix second dimension
 */
void clearMat(int ***mat, size_t height, size_t width);

/*
 * matmul multiplies two matrix.
 * @param a: first target matrix
 * @param b: second target matrix
 * @param r: target resulting matrix
 * @return the resulting matrix of a*b
 */
int **matmul(const int** a,
             const int** b,
             int** r);

/*
 * matscalmul multiplies a matrix with an integer.
 * @param a: target matrix
 * @param b: target integer to multiply a with
 * @param r: target resulting matrix
 * @return the resulting matrix of a*b
 */
int **matscalmul(const int** a,
                 int b,
                 int** r);

/*
 * matfree frees a matrix
 * @param m the matrix to free
 * @param n the dimension of m with height = width
 */
void matfree(int **m,
             unsigned int n);

#endif //CBASICS_MATRIX_HELPER_H
