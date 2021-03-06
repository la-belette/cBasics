#include <stdbool.h>
#include "string_helper.h"

#define MAX_DIFF_CHAR 26

int my_strlen(const char *s)
{
    int size = 0;
    while(s[size] != '\0')
    {
        size++;
    }
    return size;
}

int is_palindrome(const char *s)
{
    char *a = s;
    char *b = s + my_strlen(s);
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
    int stringSize = my_strlen(s);

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
    int size = my_strlen(s);
    for (int i = 0; i < size; i++)
    {
        result[i] = *(s + size - i - 1);
    }
    result[size] = '\0';
    return result;
}

char *nreverse(char *s, size_t n)
{
    char *result = (char*)malloc(30* sizeof(char));
    for (int i = 0; i < n; i++)
    {
        result[i] = *(s + n - i - 1);
    }
    result[n] = '\0';
    return result;
}

int raise_it(char *s)
{
    size_t charLength = my_strlen(s);
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

void my_strupcase(char *s)
{
    size_t charLength = my_strlen(s);
    char capital_offset = 'a' - 'A';
    for (int i = 0; i < charLength; i ++)
    {
        if ((s[i] <= 'z') && (s[i] >= 'a'))
        {
            s[i] -= capital_offset;
        }
    }
}

void my_strlowcase(char *s)
{
    size_t charLength = my_strlen(s);
    char capital_offset = 'a' - 'A';
    for (int i = 0; i < charLength; i ++)
    {
        if ((s[i] <= 'Z') && (s[i] >= 'A'))
        {
            s[i] += capital_offset;
        }
    }
}

char* my_strcpy(char *dest, const char *src)
{
    char character = 0;
    while (src[character] != '\0')
    {
        dest[character] = src[character];
        character++;
    }
    dest[character] = src[character];
    return dest;
}

int my_strcmp(const char *s1, const char* s2)
{
    char character = 0;
    int diff = 0;
    while((s1[character] != '\0') && (s2[character] != '\0'))
    {
        diff = s1[character]- s2[character];
        if (0 != diff)
        {
            return diff;
        }
        character++;
    }
    diff = s1[character]- s2[character];
    return diff;
}

int my_strncmp(const char *s1, const char* s2, size_t n)
{
    char character = 0;
    int diff = 0;
    while((s1[character] != '\0') && (s2[character] != '\0') && (character < n))
    {
        diff = s1[character]- s2[character];
        if (0 != diff)
        {
            return diff;
        }
        character++;
    }
    if (character < n)
    {
        diff = s1[character]- s2[character];
        return diff;
    }
    else
        return 0;
}

char *my_strdup(const char *s)
{
    int size = my_strlen(s);
    char *duplicate = (char *)malloc(size* sizeof(char));
    for (int character = 0; character < size; character++)
    {
        duplicate[character] = s[character];
    }
    duplicate[size] = '\0';
    return duplicate;
}

char* my_strncpy(char *dest, const char *src, size_t n)
{
    char character = 0;
    while ((src[character] != '\0') && (character < n))
    {
        dest[character] = src[character];
        character++;
    }
    dest[character] = src[character];
    return dest;
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

int my_atoi(const char *nptr)
{
    int index = 0;
    bool negative = false;
    int result = 0;
    while (nptr[index] == ' ')
    {
        index++;
    }
    if (nptr[index] == '-')
    {
        negative = true;
        index++;
    }
    else if (nptr[index] == '+')
        index++;
    else if ((nptr[index] < '0') || (nptr[index] > '9'))
    {
        return -1;
    }

    while ((nptr[index] >= '0') && (nptr[index] <= '9'))
    {
        result = result*10 + (nptr[index] - '0');
        index++;
    }
    if (negative)
        result = -result;

    return result;
}

int get_index(const char character, const char *array)
{
    int size = my_strlen(array);
    for (int element = 0; element < size; element++)
    {
        if (character == array[element])
            return element;
    }
    return -1;
}

int my_atoi_base(const char *nptr, const char *base)
{
    int index = 0;
    bool negative = false;
    int result = 0;
    int base_index = 0;

    int base_size = my_strlen(base);
    int n_size = my_strlen(nptr);

    while (nptr[index] == ' ')
    {
        index++;
    }

    if (nptr[index] == '-')
    {
        negative = true;
        index++;
    }
    else if (nptr[index] == '+')
        index++;

    while (index < n_size)
    {
        base_index = get_index(nptr[index], base);
        if(base_index < 0)
            return 0;
        result = result*base_size + base_index;
        index++;
    }
    if (negative)
        result = -result;

    return result;
}

int euclid_division(int dividend, int divisor, int* rest)
{
    int result = dividend / divisor;
    *rest = dividend - (result*divisor);
    return result;
}

char *my_itoa(int n, char *s)
{
    bool negative = false;
    int index = 0;
    int ref = n;
    if (ref < 0)
    {
        negative = true;
        ref = -ref;
    }

    while (ref >= 9)
    {
        s[index] = ref%10 + '0';
        ref /= 10;
        index++;
    }
    s[index] = ref + '0';
    if(negative)
    {
        index++;
        s[index] = '-';
    }
    index++;
    s = nreverse(s, index);
    s[index] = 0;
    return s;
}

char *my_itoa_base(int n, char *s, const char* base)
{
    bool negative = false;
    int index = 0;
    int ref = n;
    int base_size = my_strlen(base);
    if (ref < 0)
    {
        negative = true;
        ref = -n;
    }

    while (ref >= base_size)
    {
        s[index] = base[ref%base_size];
        index++;
        ref /= base_size;
    }
    s[index] = base[ref];

    if(negative)
    {
        index++;
        s[index] = '-';
    }
    index++;
    s = nreverse(s, index);
    s[index] = 0;

    return s;
}
