#include <iostream>
#include <string>
using std::cin;
using std::cout;
using namespace ::std;
// Problem 6: Luhn Checksum Validation, Page 31

int main()
{
    // finds the Luhn checksum number of an entered character
    string input;
    cout << "Enter a number";
    cin >> input;
    int sum = 0;
    for (int i = 0; i < input.length(); ++i)
    {
        int char_num = input.at(i) - 48; // minus 48 converts char -> int
        if ((i + 1) % 2 == 0)
        {

            // cout << char_num << endl;

            int doubled_char = char_num * 2;
            // cout << doubled_char << endl;
            string doubled_char_s = to_string(doubled_char);
            for (int j = 0; j < doubled_char_s.length(); ++j)
            {
                int temp = doubled_char_s.at(j) - 48;
                // cout << temp << endl;
                sum += temp;
            }
        }
        else
        {
            sum += char_num;
        }
    }

    int num_to_add = 10 - (sum % 10);
    cout << "num to add" << endl;
    cout << num_to_add;
    // cout << "sum";
    // cout << sum;

    return 0;
}