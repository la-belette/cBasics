#ifndef CBASICS_ARRAY_HELPER_H
#define CBASICS_ARRAY_HELPER_H

#include "common.h"

/*
 * array_print prints the size first elements of the integer array array.
 * @param array is a pointer to the first elements of the array to print
 * @param size is the number of element(s) to print
 */
void array_print(int *array, size_t size);

/*
 * array_init creates a size integer array.
 * If size is 0 or memory allocation failed return 0
 * @param size: size of array
 * @return pointer to integer array
 */
int *array_init(size_t size);

/*
 * array_release frees the array
 * @param array: pointer to the array to free
 */
void array_release(int *array);

/*
 * array_copy copies the size first elements of src into dest.
 * @param src: pointer to source array
 * @param dest: pointer to destination array
 * @param size: size of array to copy in elements
 */
void array_copy(int *src, int *dest, size_t size);

/*
 * array_dup duplicates size first elements of array.
 * @param array: source array
 * @param size: size of array to duplicate in elements
 * @return a pointer to the duplicate
 */
int *array_dup(int *array, size_t size);

/*
 * array_cat concatenates array2 from offset of array1
 * @param array1: pointer to first source array
 * @param array2: pointer to second source array
 * @param offset: element from array1 to concatenate from
 * @param size: size of array2 to concatenate to array1 in elements
 * @return pointer to array concatenated
 */
int *array_cat(int *array1, int *array2, size_t offset, size_t size);

/*
 * array_nth gives the nth element of array.
 * @param array: reference array to get element from
 * @param nth: number of element to retrieve
 * @return nth element of array
 */
int array_nth(int *array, size_t nth);

/*
 * array_find gives the index of the first occurrence of n in array if
 * it exists in size first elements of array.
 * @param array: pointer to first element of target array
 * @param size: size of array to search in, in elemnts
 * @param n: target element to find
 * @return index of first occurrence of n in array or -1 if it isn't
 * in size first elements of array
 */
int array_find(int *array, size_t size, int n);

/*
 * array_sort sorts size first elements of array in increasing order.
 * @param array: target array
 * @param size: size of array to sort, in elements
 */
void array_sort(int *array, size_t size);

/*
 * array_fibo fills array with size first elements of fibonacci suite
 * of rank n.
 * @param array: destination array
 * @param size: size of fibonacci suite to fill
 * @param n: target rank of fibonacci
 */
void array_fibo(int *array, size_t size, size_t n);

#endif //CBASICS_ARRAY_HELPER_H
