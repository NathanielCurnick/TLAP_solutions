#include <iostream>
#include <string>
using std::cin;
using std::cout;

// Chapter 2, Exercsie 5
// Will take a 13 digit ISBN number typed in by a used and check to see if the checksum is valid
// ISBN 13 checksums work in the following manner
// Each digit (excluding the check digit) is summer, alternately multiplying by 1 or 3
// The result is mod 10, then taken away from 10. If the result is from 1-9 then the check digit is that number, if 10 the check digit is 0
// TODO expand this to account for hyphens and also include ISBN 10 numbers
int main() {
    cout << "Enter your ISBN 13 number (without the hyphens)";
    std::string input;
    cin >> input;

    int sum = 0;
    for (int i = 0; i < 12; i++){
        int num = input.at(i) - 48; // -48 converts char to int
        if (i % 2 == 0) sum += num;
        else sum += 3 * num;
    }
    int remainder = sum % 10;
    int check_digit = 10 - remainder;
    if (check_digit == 10) check_digit = 0;

    if (check_digit == input.at(12) - 48) cout << "Valid ISBN number";
    else cout << "Invalid ISBN number";

}