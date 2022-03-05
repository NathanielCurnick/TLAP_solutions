#include <iostream>
#include <cctype>
#include <algorithm>
#include <ctime>

using std::cin;
using std::cout;
using std::string;
const int CIPHER_SIZE = 26;
string encode(string &message, char cipher_array[])
{
    string output;
    for (int i = 0; i < message.length(); i++)
    {
        char temp = message.at(i);
        if (isspace(temp))
        {
            output.push_back(' ');
        }
        else if (isalpha(temp))
        {
            temp = toupper(temp);
            output.push_back(cipher_array[temp - 'A']);
        }
        else
        {
            output.push_back(temp);
        }
    }

    return output;
}

string decode(string &message, char cipher_array[])
{

    string output;
    for (int i = 0; i < message.length(); i++)
    {
        char temp = message.at(i);
        if (isspace(temp))
        {
            output.push_back(' ');
        }
        else if (isalpha(temp))
        {
            temp = toupper(temp);
            for (int j = 0; j < CIPHER_SIZE; j++)
            {
                if (temp == cipher_array[j])
                {
                    output.push_back(toupper(static_cast<char>('A' + j)));
                    continue;
                }
            }
        }
        else
        {
            output.push_back(temp);
        }
    }

    return output;
}

int main()
{

    srand(static_cast<int>(time(0)));

    char cipher_array[CIPHER_SIZE]{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                                   'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
                                   'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
                                   'Y', 'Z'};

    std::random_shuffle(&cipher_array[0], &cipher_array[CIPHER_SIZE]);

    cout << "Enter text to be encrypted \n";

    string input;

    getline(cin, input); // cin can not handle spaces
    cout << cipher_array << "\n";
    string encoded = encode(input, cipher_array);
    cout << cipher_array << "\n";
    string decoded = decode(encoded, cipher_array);

    cout << "Original input is: " << input << "\n";
    cout << "Encoded is: " << encoded << "\n";
    cout << "Decoded is: " << decoded << "\n";
}
