#include <iostream>
#include <cctype>
#include <iterator>

using std::cin;
using std::cout;
using std::string;

const char cipher_array[26]{'Z', 'Y', 'X', 'W', 'V', 'U', 'T', 'S', 'R', 'Q', 'P', 'O', 'N', 'M', 'L', 'K', 'J', 'I', 'H', 'G', 'F', 'E', 'D', 'C', 'B', 'A'};

string encode(string &message)
{
    string outpput;
    for (int i = 0; i < message.length(); i++)
    {
        char temp = message.at(i);
        if (isspace(temp))
        {
            outpput.push_back(' ');
        }
        else if (isalpha(temp))
        {
            temp = toupper(temp);
            outpput.push_back(cipher_array[temp - 'A']);
        }
        else
        {
            outpput.push_back(temp);
        }
    }

    return outpput;
}

int main()
{
    cout << "Enter text to be encrypted \n";

    string input;

    getline(cin, input); // cin can not handle spaces

    string encoded = encode(input);
    string decoded = encode(encoded);

    cout << "Original input is: " << input << "\n";
    cout << "Encoded is: " << encoded << "\n";
    cout << "Decoded is: " << decoded << "\n";
}
