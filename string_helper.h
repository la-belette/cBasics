#ifndef CBASICS_STRING_HELPER_H
#define CBASICS_STRING_HELPER_H

#include "common.h"

/*
 * my_strlen gives the number of character(s) in a character
 * array excluding \0.
 * @param array: target char array to get the size from
 * @return number of characters in array excluding \0.
 */
int my_strlen(const char *s);

/*
 * is_palindrome checks if the given character array is a palindrome.
 * @param s: target character array to check
 * @return 0 if s is a palindrome, -1 otherwise.
 */
int is_palindrome(const char *s);

/*
 * is_palindrome_permutation checks if the given character array is a
 * permutation of a palindrome.
 * @param s: target character array to check
 * @return 0 if s is a palindrome permutation, -1 otherwise.
 */
int is_palindrome_permutation(const char *s);

/*
 * reverses a character array starting with original last character
 * as first resulting one.
 * @param s: target character array to reverse
 * @return the reversed character array
 */
char *reverse(char *s);

/*
 * raise_it raises the letters of given character array to capital.
 * @param s: target character array to raise
 * @return the number of letter(s) originally capital letters
 */
int raise_it(char *s);

/*
 * my_strupcase raises the letters if given character array
 * @param s: character array to raise
 */
void my_strupcase(char *s);

/*
 * my_strlowcase lowers the letters if given character array
 * @param s: character array to raise
 */
void my_strlowcase(char *s);

/*
 * nb_odd_letter gives the number of odd letters in a given
 * character array.
 * @param string: target character array to check
 * @param length: length of character array to check
 * @return the number of letters in odd number in given string length
 */
int nb_odd_letter(const char *string, int length);

/*
 * my_strcpy copies the string pointed to by src to the buffer
 * pointed to by dest. src and dest must not overlap. dest must be
 * large enough to receive the copy.
 * @param src: string to copy
 * @param dest: buffer to copy to
 * @return a pointer to dest
 */
char* my_strcpy(char *dest, const char *src);

/*
 * my_strncpy copies the n first bytes of the string pointed to by
 * src to the buffer pointed to by dest. src and dest must not
 * overlap. dest must be large enough to receive the copy.
 * @param src: string to copy
 * @param dest: buffer to copy to
 * @param n: maximum size of copy in bytes
 * @return a pointer to dest
 */
char* my_strncpy(char *dest, const char *src, size_t n);

/*
 * my_strcmp compares strings s1 and s2.
 * @param s1: string to compare with s2
 * @param s2: string to compare with s1
 * @return 0 if s1 contains the same string as s2,
 * -1 if s1 is < s2,
 * 1 id s1 > s2
 */
int my_strcmp(const char *s1, const char* s2);

/*
 * my_strncmp compares n first bytes of strings s1 and s2.
 * @param s1: string to compare with s2
 * @param s2: string to compare with s1
 * @param n: maximum size of string to compare
 * @return 0 if s1 contains the same string as s2,
 * -1 if s1 is < s2,
 * 1 id s1 > s2
 */
int my_strncmp(const char *s1, const char* s2, size_t n);

/*
 * my_strdup gives a duplicate of s.
 * @param s: the reference string to duplicate
 * @return a pointer to the duplicate
 */
char *my_strdup(const char *s);

/*
 * my_atoi converts a string to an integer
 * @param nptr: pointer to string to convert
 * @return the integer value of nptr
 */
int my_atoi(const char *nptr);

/*
 * my_itoa converts an integer into a character array.
 * @param n: integer to convert
 * @param s: pointer to buffer for converted integer
 * @return a pointer to s
 */
char *my_itoa(int n, char *s);

#endif //CBASICS_STRING_HELPER_H
