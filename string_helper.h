#ifndef CBASICS_STRING_HELPER_H
#define CBASICS_STRING_HELPER_H

/*
 * sizeOfCharArray gives the number of character(s) in a character
 * array excluding \0.
 * @param array: target char array to get the size from
 * @return number of characters in array excluding \0.
 */
int sizeOfCharArray(const char* table);

/*
 * plop
 */
int mystrlen(const char *s);

/*
 * isPalindrome checks if the given character array is a palindrome.
 * @param s: target character array to check
 * @return 0 if s is a palindrome, -1 otherwise.
 */
int isPalindrome(const char *s);

/*
 * isPalindromePermutation checks if the given character array is a
 * permutation of a palindrome.
 * @param s: target character array to check
 * @return 0 if s is a palindrome permutation, -1 otherwise.
 */
int isPalindromePermutation(const char *s);

/*
 * reverses a character array starting with original last character
 * as first resulting one.
 * @param s: target character array to reverse
 * @return the reversed character array
 */
char *reverse(char *s);

/*
 * raiseit raises the letters of given character array to capital.
 * @param s: target character array to raise
 * @return the number of letter(s) originally capital letters
 */
int raiseit(char *s);

/*
 * numberOfOddLetter gives the number of odd letters in a given
 * character array.
 * @param string: target character array to check
 * @param length: length of character array to check
 * @return the number of letters in odd number in given string length
 */
int numberOfOddLetter (const char* string, int length);

#endif //CBASICS_STRING_HELPER_H
