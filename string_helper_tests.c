#include "string_helper_tests.h"
#include "string_helper.h"
#include "common.h"

#include <string.h>

int test_size_char_array()
{
    int err = 0;
    char* input = "coucou";
    int expected_result = 6;
    int result = my_strlen(input);
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

int test_strupcase()
{
    int err = 0;
    char input[] = {'H', 'o', ' ', 'H', 'o', ' ', 'H', 'o', '.', '.', '.', '\0'};
    char* expected_output = "HO HO HO...";
    my_strupcase(input);
    if (0 != strcmp(expected_output, input))
    {
        printf("error in %s: %s once raised instead of %s.\n", __func__, input, expected_output);
        err = -1;
    }

    return err;
}

int test_strlowcase()
{
    int err = 0;
    char input[] = {'H', 'o', ' ', 'H', 'o', ' ', 'H', 'o', '.', '.', '.', '\0'};
    char* expected_output = "ho ho ho...";
    my_strlowcase(input);
    if (0 != strcmp(expected_output, input))
    {
        printf("error in %s: %s once lowered instead of %s.\n", __func__, input, expected_output);
        err = -1;
    }

    return err;
}


int test_nb_odd_letter()
{
    int err = 0;

    char *input = "kayak";
    int expected_result = 1;
    int result = nb_odd_letter(input, my_strlen(input));
    if (expected_result != result)
    {
        printf("error in %s: There is/are %d instead of expected %d odd letter(s) in %s\n", __func__,result,  input, expected_result);
        err = -1;
    }

    char *input2 = "turlututu";
    expected_result = 3;
    result = nb_odd_letter(input2, my_strlen(input2));
    if (expected_result != result)
    {
        printf("error in %s: There is/are %d instead of expected %d odd letter(s) in %s\n", __func__,result,  input2, expected_result);
        err = -1;
    }

    char *input3 = "toto";
    expected_result = 0;
    result = nb_odd_letter(input3, my_strlen(input3));
    if (expected_result != result)
    {
        printf("error in %s: There is/are %d instead of expected %d odd letter(s) in %s\n", __func__,result,  input3, expected_result);
        err = -1;
    }

    char *input4 = "?!./";
    expected_result = 0;
    result = nb_odd_letter(input4, my_strlen(input4));
    if (expected_result != result)
    {
        printf("error in %s: There is/are %d instead of expected %d odd letter(s) in %s\n", __func__,result,  input4, expected_result);
        err = -1;
    }

    char *input5 = "";
    expected_result = 0;
    result = nb_odd_letter(input5, my_strlen(input5));
    if (expected_result != result)
    {
        printf("error in %s: There is/are %d instead of expected %d odd letter(s) in %s\n", __func__,result,  input5, expected_result);
        err = -1;
    }

    return err;
}

int test_my_strcpy()
{
    int err = 0;

    char ref[] = "RED";
    char* copy = (char*)malloc(4*sizeof(char));
    my_strcpy(copy, ref);
    if (0 != strcmp(ref, copy))
    {
        printf("fail in %s: copy contains %s instead of expected %s.\n",
                __func__,
                copy,
                ref);
        err = -1;
    }
    return err;
}

int test_my_strncpy()
{
    int err = 0;

    char ref[] = "RED";
    char* copy = (char*)malloc(4*sizeof(char));
    my_strncpy(copy, ref, 5);
    if (0 != strcmp(ref, copy))
    {
        printf("fail in %s: copy contains %s instead of expected %s.\n",
               __func__,
               copy,
               ref);
        err = -1;
    }
    return err;
}

int test_my_strcmp()
{
    int err = 0;
    char *input1 = "Wilgardium";
    char *input2 = "Wilgardium";
    char *input3 = "Leviosa";
    char *input4 = "Wilgardiu";
    int expected_result = 'm';
    int result = my_strcmp(input1, input4);
    if (expected_result != result)
    {
        printf("fail in %s: comparison result %d instead of expected %d.\n",
               __func__,
               result,
               expected_result);
        err = -1;
    }
    expected_result = 0;
    result = my_strcmp(input1, input2);
    if (expected_result != result)
    {
        printf("fail in %s: comparison result %d instead of expected %d.\n",
               __func__,
               result,
               expected_result);
        err = -1;
    }
    expected_result = 'W' - 'L';
    result = my_strcmp(input1, input3);
    if (expected_result != result)
    {
        printf("fail in %s: comparison result %d instead of expected %d.\n",
               __func__,
               result,
               expected_result);
        err = -1;
    }
    return err;
}

int test_my_strdup()
{
    int err = 0;

    char *input = "RED";
    char *output = my_strdup(input);
    if (0 != my_strcmp(input, output))
    {
        printf("fail in %s: duplicate holds %s instead of expected %s.\n",
                __func__,
                output,
                input);
        err = -1;
    }

    return 0;
}

int test_string_helper()
{
    int err = 0;

    err += test_size_char_array();
    err += test_is_palindrome();
    err += test_reverse();
    err += test_raise_it();
    err += test_strupcase();
    err += test_strlowcase();
    err += test_my_strcpy();
    err += test_my_strncpy();
    err += test_my_strcmp();
    err += test_my_strdup();
    err += test_nb_odd_letter();

    return err;
}