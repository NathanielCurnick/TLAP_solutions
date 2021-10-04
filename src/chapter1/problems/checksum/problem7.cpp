// Problem 7: Convert Character Digit to Integer, Page 35

#include <iostream>
using std::cin;
using std::cout;

int main()
{
    char digit;
    cout << "Enter a one-digit number: ";
    cin >> digit;
    int sum = digit - '0';
    cout << "Is the sum of the digits " << sum << "? \n";
}