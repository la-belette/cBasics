#include "string_helper.h"
#include "common.h"

#define MAX_DIFF_CHAR 26

int size_char_array(const char *array)
{
    int size = 0;
    while(array[size] != '\0')
    {
        size++;
    }
    return size;
}

int is_palindrome(const char *s)
{
    char *a = s;
    char *b = s + size_char_array(s);
    while((a != b) && (a < b))
    {
        if ((*a < 'A')
            || ((*a > 'Z') && (*a < 'a'))
            || (*a > 'z'))
        {
            a++;
            continue;
        }
        if ((*b < 'A')
            || ((*b > 'Z') && (*b < 'a'))
            || (*b > 'z'))
        {
            b--;
            continue;
        }
        if((*a != *b)
           && (*a != (*b - 'a' + 'A'))
           && ((*a - 'a' + 'A') != *b))
            return -1;
        a++;
        b--;
    }
    return 0;
}

int is_palindrome_permutation(const char *s)
{
    char c;
    int stringSize = size_char_array(s);

    int array[MAX_DIFF_CHAR] = {0};
    for (int i = 0; i < stringSize; i++)
    {
        c = *(s+i);
        if ((c > 'A') && (c < 'Z'))
        {
            array[c-'A']++;
        }
        else if ((c > 'a') && (c < 'z'))
        {
            array[c -'a']++;
        }
    }

    int oddLettersCount = 0;
    for (int i = 0; i < MAX_DIFF_CHAR; i++)
    {
        if((array[i]%2) == 1)
        {
            oddLettersCount++;
        }
    }

    if (oddLettersCount>1)
        return -1;
    else
        return 0;
}

char *reverse(char *s)
{
    char *result = (char*)malloc(30* sizeof(char));
    int size = size_char_array(s);
    for (int i = 0; i < size; i++)
    {
        result[i] = *(s + size - i - 1);
    }
    result[size] = '\0';
    return result;
}

int raise_it(char *s)
{
    size_t charLength = size_char_array(s);
    /*
    char *ref = (char*)malloc(charLength);
    ref = my_memcpy(ref, s, charLength);
     */
    int majCount = 0;
    char capital_offset = 'a' - 'A';
    for (int i = 0; i < charLength; i ++)
    {
        if ((s[i] <= 'z') && (s[i] >= 'a'))
        {
            s[i] -= capital_offset;
        }
        else if ((s[i] <= 'Z') && (s[i] >= 'A'))
            majCount ++;
    }
    return majCount;
}

int nb_odd_letter(const char *string, int length)
{
    int charMem[MAX_DIFF_CHAR] = {0};
    int c = 0;

    for (int i = 0; i < length; i ++)
    {
        if((string[i] < 'z') && (string[i] > 'a'))
        {
            c = string[i] - 'a';
        }
        else if ((string[i] < 'Z') && (string[i] > 'A'))
        {
            c = string[i] - 'A';
        } else
        {
            continue;
        }
        charMem[c]++;
    }

    int oddLetters = 0;

    for (int i = 0; i < MAX_DIFF_CHAR; i++)
    {
        if (charMem[i] % 2 != 0)
            oddLetters ++;
    }

    return oddLetters;
}
