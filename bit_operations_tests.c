#include "bit_operations_tests.h"
#include "bit_operation_helper.h"
#include "common.h"
#include "memory_manager.h"

int test_rol()
{
    int err = 0;

    uint8_t target = 0b1;
    uint8_t shift = 6;
    uint8_t expected_result = 0b1000000;
    uint8_t result = rol(target, shift);
    if (result != expected_result)
    {
        printf("fail in %s: %d bits shift of %d result is %d instead of expected %d.\n",
                __func__,
                shift,
                target,
                result,
                expected_result);
        err = -1;
    }

    target = 0b1011010;
    shift = 1;
    expected_result = 0b0110101;
    result = rol(target, shift);
    if (result != expected_result)
    {
        printf("fail in %s: %d bits shift of %d result is %d instead of expected %d.\n",
               __func__,
               shift,
               target,
               result,
               expected_result);
        err = -1;
    }

    target = 0b11111111;
    shift = 8;
    result = rol(target, shift);
    if (result != target)
    {
        printf("fail in %s: %d bits shift of %d result is %d instead of expected %d.\n",
               __func__,
               shift,
               target,
               result,
               expected_result);
        err = -1;
    }
    return 0;
}

int test_ror()
{
    int err = 0;

    uint8_t target = 0b1000000;
    uint8_t shift = 6;
    uint8_t expected_result = 0b1;
    uint8_t result = ror(target, shift);
    if (result != expected_result)
    {
        printf("fail in %s: %d bits shift of %d result is %d instead of expected %d.\n",
               __func__,
               shift,
               target,
               result,
               expected_result);
        err = -1;
    }

    target = 0b10110100;
    shift = 1;
    expected_result = 0b1011010;
    result = ror(target, shift);
    if (result != expected_result)
    {
        printf("fail in %s: %d bits shift of %d result is %d instead of expected %d.\n",
               __func__,
               shift,
               target,
               result,
               expected_result);
        err = -1;
    }

    target = 0b11111111;
    shift = 8;
    result = ror(target, shift);
    if (result != target)
    {
        printf("fail in %s: %d bits shift of %d result is %d instead of expected %d.\n",
               __func__,
               shift,
               target,
               result,
               expected_result);
        err = -1;
    }
    return 0;
}

void char_array_print(char *array, size_t size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", array[i]);
    }
    printf("\n");
}

int test_xor_crypt()
{
    int err = 0;

    char *target = malloc(7* sizeof(char));
    target[0] = 'E';
    target[1] = 'x';
    target[2] = 'a';
    target[3] = 'm';
    target[4] = 'p';
    target[5] = 'l';
    target[6] = 'e';
    char *key = "Key";
    char expected_output[] = {14, 29, 24, 38, 21, 21, 46};
    my_xor_crypt(target, 7, key, 3);
    if (0 != memcmp(target, expected_output, 7))
    {
        printf("fail in %s: xor cryp result is\n", __func__);
        char_array_print(target, 7);
        printf("instead of expected\n");
        char_array_print (expected_output, 7);
        err = -1;
    }

    return err;
}

int test_rol_crypt()
{
    int err = 0;

    char *target = malloc(7* sizeof(char));
    target[0] = 'E';
    target[1] = 'x';
    target[2] = 'a';
    target[3] = 'm';
    target[4] = 'p';
    target[5] = 'l';
    target[6] = 'e';
    char *key = "Key";
    char expected_output[] = {14, 29, 24, 38, 21, 21, 46}; // TODO
    my_rol_crypt(target, 7, key, 3);
    if (0 != memcmp(target, expected_output, 7))
    {
        printf("fail in %s: xor cryp result is\n", __func__);
        char_array_print(target, 7);
        printf("instead of expected\n");
        char_array_print (expected_output, 7);
        err = -1;
    }

    return err;
}

int test_ror_crypt()
{
    int err = 0;

    char *target = malloc(7* sizeof(char));
    target[0] = 'E';
    target[1] = 'x';
    target[2] = 'a';
    target[3] = 'm';
    target[4] = 'p';
    target[5] = 'l';
    target[6] = 'e';
    char *key = "Key";
    char expected_output[] = {14, 29, 24, 38, 21, 21, 46}; //TODO
    my_ror_crypt(target, 7, key, 3);
    if (0 != memcmp(target, expected_output, 7))
    {
        printf("fail in %s: xor cryp result is\n", __func__);
        char_array_print(target, 7);
        printf("instead of expected\n");
        char_array_print (expected_output, 7);
        err = -1;
    }

    return err;
}

int test_bit_operations()
{
    int err = 0;

    err += test_rol();
    err += test_ror();
    err += test_xor_crypt();

    return err;
}