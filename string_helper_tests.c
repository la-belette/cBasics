#include "string_helper_tests.h"
#include "string_helper.h"
#include "common.h"

#include <string.h>

int test_size_char_array()
{
    int err = 0;
    char* input = "coucou";
    int expected_result = 6;
    int result = size_char_array(input);
    if (expected_result != result)
    {
        printf("error in %s: %s has a length of %d instead of expected %d.\n", __func__, input, result, expected_result);
        err = -1;
    }

    return err;
}

int test_is_palindrome()
{
    int err = 0;
    char* input = "kayak";
    int expected_result = 0;
    int result = is_palindrome(input);
    if (expected_result != result)
    {
        printf("error in %s: Is %s a palindrome? returns %d instead of expected %d.\n", __func__, input, result, expected_result);
        err = -1;
    }

    char *input2 = "Murder for a jar of red rum";
    result = is_palindrome(input2);
    if (expected_result != result)
    {
        printf("error in %s: Is %s a palindrome? returns %d instead of expected %d.\n", __func__, input2, result, expected_result);
        err = -1;
    }

    char *input3 = "test";
    expected_result = -1;
    result = is_palindrome(input3);
    if (expected_result != result)
    {
        printf("error in %s: Is %s a palindrome? returns %d instead of expected %d.\n", __func__, input3, result, expected_result);
        err = -1;
    }

    return err;
}

int test_is_palindrome_permutation()
{
    int err = 0;
    char* input = "toto";
    int expected_result = 0;
    int result = is_palindrome_permutation(input);
    if (expected_result != result)
    {
        printf("error in %s: Is %s a palindrome permutation? returns %d instead of expected %d.\n", __func__, input, result, expected_result);
        err = -1;
    }

    char *input2 = "tatie";
    expected_result = -1;
    result = is_palindrome_permutation(input);
    if (expected_result != result)
    {
        printf("error in %s: Is %s a palindrome permutation? returns %d instead of expected %d.\n", __func__, input2, result, expected_result);
        err = -1;
    }

    return err;
}

int test_reverse()
{
    int err = 0;
    char* input = "Hihihi";
    char* expected_result = "ihihiH";
    char *result = reverse(input);
    if (0 != strcmp(expected_result, result))
    {
        printf("error in %s: %s reversed becomes %s instead of %s.\n", __func__, input, result, expected_result);
        err = -1;
    }
    free(result);

    return err;
}

int test_raise_it()
{
    int err = 0;
    char input[] = {'H', 'o', ' ', 'H', 'o', ' ', 'H', 'o', '.', '.', '.', '\0'};
    char* expected_output = "HO HO HO...";
    int expected_result = 3;
    int result = raise_it(input);
    if ((expected_result != result) || (0 != strcmp(expected_output, input)))
    {
        printf("error in %s: %s already contained %d capital letter(s) & becomes %s once raised instead of %d capital letter(s) and becoming %s.\n", __func__, input, result, expected_output, expected_result);
        err = -1;
    }

    return err;
}

int test_nb_odd_letter()
{
    int err = 0;

    char *input = "kayak";
    int expected_result = 1;
    int result = nb_odd_letter(input, size_char_array(input));
    if (expected_result != result)
    {
        printf("error in %s: There is/are %d instead of expected %d odd letter(s) in %s\n", __func__,result,  input, expected_result);
        err = -1;
    }

    char *input2 = "turlututu";
    expected_result = 3;
    result = nb_odd_letter(input2, size_char_array(input2));
    if (expected_result != result)
    {
        printf("error in %s: There is/are %d instead of expected %d odd letter(s) in %s\n", __func__,result,  input2, expected_result);
        err = -1;
    }

    char *input3 = "toto";
    expected_result = 0;
    result = nb_odd_letter(input3, size_char_array(input3));
    if (expected_result != result)
    {
        printf("error in %s: There is/are %d instead of expected %d odd letter(s) in %s\n", __func__,result,  input3, expected_result);
        err = -1;
    }

    char *input4 = "?!./";
    expected_result = 0;
    result = nb_odd_letter(input4, size_char_array(input4));
    if (expected_result != result)
    {
        printf("error in %s: There is/are %d instead of expected %d odd letter(s) in %s\n", __func__,result,  input4, expected_result);
        err = -1;
    }

    char *input5 = "";
    expected_result = 0;
    result = nb_odd_letter(input5, size_char_array(input5));
    if (expected_result != result)
    {
        printf("error in %s: There is/are %d instead of expected %d odd letter(s) in %s\n", __func__,result,  input5, expected_result);
        err = -1;
    }

    return err;
}

int test_string_helper()
{
    int err = 0;

    err += test_size_char_array();
    err += test_is_palindrome();
    err += test_reverse();
    err += test_raise_it();
    err += test_nb_odd_letter();

    return err;
}