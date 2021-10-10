// Problem 8: Luhn Checksum Validation, Fixed Length, Page 36

#include <iostream>
#include "double_digit.h"
using std::cin;
using std::cout;

int main()
{
    char digit;
    int checksum = 0;
    cout << "Enter a six digit number";
    for (int position = 1; position <= 6; position++)
    {
        cin >> digit;
        if (position % 2 == 0)
            checksum += digit - '0';
        else
            checksum += double_digit_value(digit - '0');
    }
    cout << "Checksum is " << checksum << ". \n";
    if (checksum % 10 == 0)
    {
        cout << "Checksum is divisble by 10. Valid. \n";
    }
    else
    {
        cout << "Checksum is not divisible by 10. Invalid. \n";
    }
}