#ifndef CBASICS_BIT_OPERATION_HELPER_H
#define CBASICS_BIT_OPERATION_HELPER_H

/*
 * rol shifts value roll bit(s) to the left.
 * @param value: target value to shift
 * @param roll: size of shift in bits
 * @return value shifted roll bits to the left
 */
unsigned char rol(unsigned char value, unsigned int roll);

/*
 * ror shifts value roll bit(s) to the right.
 * @param value: target value to shift
 * @param roll: size of shift in bits
 * @return value shifted roll bits to the right
 */
unsigned char ror(unsigned char value, unsigned int roll);

#endif //CBASICS_BIT_OPERATION_HELPER_H
