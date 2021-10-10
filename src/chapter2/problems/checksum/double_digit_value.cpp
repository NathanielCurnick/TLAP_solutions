#include "double_digit.h"

int double_digit_value(int digit)
{
    int double_digit = digit * 2;
    int sum;
    if (double_digit > 10)
        sum = 1 + double_digit % 10;
    else
        sum = double_digit;
    return sum;
}