#include <iostream>
#include <cctype>
#include <iterator>

using std::cin;
using std::cout;
using std::string;

const char cipher_array[26]{'Z', 'Y', 'X', 'W', 'V', 'U', 'T', 'S', 'R', 'Q', 'P', 'O', 'N', 'M', 'L', 'K', 'J', 'I', 'H', 'G', 'F', 'E', 'D', 'C', 'B', 'A'};

int main()
{
    cout << "Enter text to be encrypted \n";

    string input;

    getline(cin, input); // cin can not handle spaces

    for (int i = 0; i < input.length(); i++)
    {
        char temp = input.at(i);
        if (isspace(temp))
        {
            cout << " ";
        }
        else if (isalpha(temp))
        {
            temp = toupper(temp);
            cout << cipher_array[temp - 'A'];
        }
        else
        {
            cout << temp;
        }
    }
}
