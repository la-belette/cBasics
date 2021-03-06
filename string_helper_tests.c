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

int test_my_strncmp()
{
    int err = 0;
    char *input1 = "Wilgardium";
    char *input2 = "Wilgardiu";
    int expected_result = 'm';
    int result = my_strncmp(input1, input2, 10);
    if (expected_result != result)
    {
        printf("fail in %s: comparison result %d instead of expected %d.\n",
               __func__,
               result,
               expected_result);
        err = -1;
    }
    expected_result = 0;
    result = my_strncmp(input1, input2, 9);
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

int test_my_atoi()
{
    int err = 0;
    char *input = "-12 3";
    int expected_result = -12;
    int result = my_atoi(input);
    if (expected_result != result)
    {
        printf("fail in %s: integer conversion returns %d instead of expected %d.\n",
                __func__,
                result,
                expected_result);
        err = -1;
    }
    char *input2 = "   9578.";
    expected_result = 9578;
    result = my_atoi(input2);
    if (expected_result != result)
    {
        printf("fail in %s: integer conversion returns %d instead of expected %d.\n",
               __func__,
               result,
               expected_result);
        err = -1;
    }
    char *input3 = "+6,5";
    expected_result = 6;
    result = my_atoi(input3);
    if (expected_result != result)
    {
        printf("fail in %s: integer conversion returns %d instead of expected %d.\n",
               __func__,
               result,
               expected_result);
        err = -1;
    }
    return err;
}

int test_my_atoi_base()
{
    int err = 0;
    char *input = "ff";
    char *hexa_base = "0123456789abcdef";
    int expected_result = 255;
    int result = my_atoi_base(input, hexa_base);
    if (expected_result != result)
    {
        printf("fail in %s: integer conversion of %s in base %s returns %d instead of expected %d.\n",
               __func__,
               input,
               hexa_base,
               result,
               expected_result);
        err = -1;
    }
    char *input2 = "   -ff";
    expected_result = -255;
    result = my_atoi_base(input2, hexa_base);
    if (expected_result != result)
    {
        printf("fail in %s: integer conversion of %s in base %s returns %d instead of expected %d.\n",
               __func__,
               input2,
               hexa_base,
               result,
               expected_result);
        err = -1;
    }
    char *input3 = "77";
    char *octal_base = "01234567";
    expected_result = 63;
    result = my_atoi_base(input3, octal_base);
    if (expected_result != result)
    {
        printf("fail in %s: integer conversion of %s in base %s returns %d instead of expected %d.\n",
               __func__,
               input3,
               octal_base,
               result,
               expected_result);
        err = -1;
    }
    char *input4 = "+WQWW";
    char *random_base = "QW";
    expected_result = 11;
    result = my_atoi_base(input4, random_base);
    if (expected_result != result)
    {
        printf("fail in %s: integer conversion of %s in base %s returns %d instead of expected %d.\n",
               __func__,
               input4,
               random_base,
               result,
               expected_result);
        err = -1;
    }
    char *input5 = "021!";
    char *four_base = "0123";
    expected_result = 0;
    result = my_atoi_base(input5, four_base);
    if (expected_result != result)
    {
        printf("fail in %s: integer conversion of %s in base %s returns %d instead of expected %d.\n",
               __func__,
               input5,
               four_base,
               result,
               expected_result);
        err = -1;
    }
    return err;
}

int test_my_itoa()
{
    int err = 0;

    int MAX_INT_SIZE = 10;
    int input = -2578;
    char *expected_result = "-2578";
    char *result = calloc(10, sizeof(char));
    result = my_itoa(input, result);
    if (0 != my_strcmp(result, expected_result))
    {
        printf ("fail in %s: number converted is %s instead of expected %s.\n",
                __func__,
                result,
                expected_result);
        err = -1;
    }
    input = 3;
    char *expected_result2 = "3";
    result = my_itoa(input, result);
    if (0 != my_strcmp(result, expected_result2))
    {
        printf ("fail in %s: number converted is %s instead of expected %s.\n",
                __func__,
                result,
                expected_result2);
        err = -1;
    }

    return err;
}

int test_my_itoa_base()
{
    int err = 0;
    char *expected_result = "ff";
    char *hexa_base = "0123456789abcdef";
    int input = 255;
    char *result = malloc(100);
    result = my_itoa_base(input, result, hexa_base);
    if (0 != test_my_strcmp(expected_result, result))
    {
        printf("fail in %s: ascii conversion of %d in base %s returns %s instead of expected %s.\n",
               __func__,
               input,
               hexa_base,
               result,
               expected_result);
        err = -1;
    }
    char *expected_result2 = "-ff";
    input = -255;
    result = my_itoa_base(input, result, hexa_base);
    if (0 != my_strcmp(expected_result2, result))
    {
        printf("fail in %s: ascii conversion of %d in base %s returns %s instead of expected %s.\n",
               __func__,
               input,
               hexa_base,
               result,
               expected_result2);
        err = -1;
    }
    char *expected_result3 = "77";
    char *octal_base = "01234567";
    input = 63;
    result = my_itoa_base(input, result, octal_base);
    if (0 != my_strcmp(expected_result3, result))
    {
        printf("fail in %s: ascii conversion of %d in base %s returns %s instead of expected %s.\n",
               __func__,
               input,
               octal_base,
               result,
               expected_result3);
        err = -1;
    }
    char *expected_result4 = "WQWW";
    char *random_base = "QW";
    input = 11;
    result = my_itoa_base(input, result, random_base);
    if (0 != my_strcmp(expected_result4, result))
    {
        printf("fail in %s: ascii conversion of %d in base %s returns %s instead of expected %s.\n",
               __func__,
               input,
               random_base,
               result,
               expected_result4);
        err = -1;
    }
    char *expected_result5 = "201";
    char *four_base = "0123";
    input = 33;
    result = my_itoa_base(input, result, four_base);
    if (0 != strcmp(expected_result5, result))
    {
        printf("fail in %s: ascii conversion of %d in base %s returns %s instead of expected %s.\n",
               __func__,
               input,
               four_base,
               result,
               expected_result5);
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
    err += test_strupcase();
    err += test_strlowcase();
    err += test_my_strcpy();
    err += test_my_strncpy();
    err += test_my_strcmp();
    err += test_my_strncmp();
    err += test_my_strdup();
    err += test_nb_odd_letter();
    err += test_my_atoi();
    err += test_my_atoi_base();
    err += test_my_itoa();
    err += test_my_itoa_base();

    return err;
}