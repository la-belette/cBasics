#include "string_helper_tests.h"
#include "string_helper.h"
#include "common.h"

int test_size_char_array()
{
    printf("coucou has a length of %d.\n", size_char_array("coucou"));
    return 0;
}

int test_is_palindrome()
{
    printf("Is kayak a plindrome? %d\n", is_palindrome("kayak"));
    printf("Is \"la mariee ira mal\" a palindrome? %d\n", is_palindrome("la mariee ira mal"));
    printf("Is toto a palindrome permutation? %d\n", is_palindrome_permutation("toto"));
    printf("Is tatie a palindrome permutation? %d\n", is_palindrome_permutation("tatie"));
    return 0;
}

int test_reverse()
{
    char *str = "Hihihi!";
    char *string = reverse(str);
    printf("%s reversed becomes %s.\n", str, string);
    free(string);
    return 0;
}

int test_raise_it()
{

    char string[] = {'H', 'o', ' ', 'H', 'o', ' ', 'H', 'o', '.', '.', '.', '\0'};
    printf("%s", string);
    int verif = raise_it(string);
    printf(" already contained %d capital letter(s) & becomes %s once raised.\n", verif, string);

    return 0;
}

int test_nb_odd_letter()
{
    printf("There is/are %d odd letter(s) in kayak\n", nb_odd_letter("kayak", 5));
    printf("There is/are %d odd letter(s) in turlututu\n", nb_odd_letter("turlututu", 9));
    printf("There is/are %d odd letter(s) in toto\n", nb_odd_letter("toto", 4));
    printf("There is/are %d odd letter(s) in ?!./\n", nb_odd_letter("?!./", 4));
    printf("There is/are %d odd letter(s) in _\n", nb_odd_letter("", 0));
    return 0;
}

int test_string_helper()
{
    int result = 0;
    if (0 != test_size_char_array())
        result = -1;

    if (0 != test_is_palindrome())
        result = -1;

    if (0 != test_reverse())
        result = -1;

    if (0 != test_raise_it())
        result = -1;

    if (0 != test_nb_odd_letter())
        result  = -1;

    return result;
}