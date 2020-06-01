#include "bit_operation_helper.h"

unsigned char rol(unsigned char value, unsigned int roll)
{
    return value << roll;
}

unsigned char ror(unsigned char value, unsigned int roll)
{
    return value >> roll;
}