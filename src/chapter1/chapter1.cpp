#include <iostream>

#include <stdio.h>
#include <typeinfo>
#include <vector>
#include <stdexcept>
using std::cin;
using std::cout;
using namespace std;

string convert_to_string(vector<char> &a, int size)
{
    string s = "";
    for (int i = 0; i < size; ++i)
    {
        s = s + a[i];
        // cout << a[i];
    }
    return s;
}

string return_character(int input, int mode)
{
    string output;
    switch (mode)
    {
    case 0:
        output = input + 'A' - 1;
        break;

    case 1:
        output = input + 'a' - 1;
        break;

    case 2:
        switch (input)
        {
        case 1:
            output = '!';
            break;
        case 2:
            output = '?';
            break;
        case 3:
            output = ',';
            break;
        case 4:
            output = '.';
            break;
        case 5:
            output = ' ';
            break;
        case 6:
            output = ';';
            break;
        case 7:
            output = '"';
            break;
        case 8:
            output = '\'';
            break;

        default:
            throw invalid_argument("punctuation out of bounds");
        }
        break;

    default:
        throw invalid_argument("decode mode out of bounds");
    }

    return output;
}

int decode()
{
    vector<int> encoded_message{18, 12312, 171, 763, 98423, 1208, 216, 11, 500, 18, 241, 0, 32, 20620, 27, 10};
    int decode_mode = 0; // decode of 0 is upper, decode of 1 is lower, 2 is punctuation
    string result = "";
    cout << encoded_message.size() << endl;
    for (int i = 0; i < encoded_message.size(); i++)
    {
        // cout << encoded_message[i] << endl;
        int remainder = 0;
        switch (decode_mode)
        {
        case 0:
            remainder = encoded_message[i] % 27;
            if (remainder == 0)
            {
                decode_mode = 1;
                break;
            }
            else
            {
                result = result + return_character(remainder, decode_mode);
                break;
            }

        case 1:
            remainder = encoded_message[i] % 27;
            if (remainder == 0)
            {
                decode_mode = 2;
                break;
            }
            else
            {
                result = result + return_character(remainder, decode_mode);
                break;
            }

        case 2:
            remainder = encoded_message[i] % 9;
            if (remainder == 0)
            {
                decode_mode = 0;
                break;
            }
            else
            {
                result = result + return_character(remainder, decode_mode);
                break;
            }

        default:
            throw invalid_argument("decode mode out of bounds");
        }
    }
    // cout << result;
    cout << result << endl;

    return 0;
}
