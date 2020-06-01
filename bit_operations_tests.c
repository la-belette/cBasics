#include "bit_operations_tests.h"
#include "bit_operation_helper.h"
#include "common.h"

int test_rol()
{
    int err = 0;

    uint8_t target = 0b1;
    uint8_t shift = 6;
    uint8_t expected_result = 0b1000000;
    uint8_t result = rol(target, shift);
    if (result != expected_result)
    {
        printf("fail in %s: %d bits shift of %d result is %d instead of expected %d",
                __func__,
                shift,
                target,
                result,
                expected_result);
        err = -1;
    }

    target = 0b1011010;
    shift = 1;
    expected_result = 0b10110100;
    result = rol(target, shift);
    if (result != expected_result)
    {
        printf("fail in %s: %d bits shift of %d result is %d instead of expected %d",
               __func__,
               shift,
               target,
               result,
               expected_result);
        err = -1;
    }

    target = 0b11111111;
    shift = 8;
    expected_result = 0;
    result = rol(target, shift);
    if (result != expected_result)
    {
        printf("fail in %s: %d bits shift of %d result is %d instead of expected %d",
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
        printf("fail in %s: %d bits shift of %d result is %d instead of expected %d",
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
        printf("fail in %s: %d bits shift of %d result is %d instead of expected %d",
               __func__,
               shift,
               target,
               result,
               expected_result);
        err = -1;
    }

    target = 0b11111111;
    shift = 8;
    expected_result = 0;
    result = ror(target, shift);
    if (result != expected_result)
    {
        printf("fail in %s: %d bits shift of %d result is %d instead of expected %d",
               __func__,
               shift,
               target,
               result,
               expected_result);
        err = -1;
    }
    return 0;
}

int test_bit_operations()
{
    int err = 0;

    err += test_rol();
    err += test_ror();

    return err;
}