#include <iostream>
using std::cout;

// Problem 1: Half a Square, page 26

int main()
{
    // Really simple, prints out a half tringle shape of hashes
    for (int i = 5; i != 0; --i)
    {
        for (int j = i; j != 0; --j)
        {
            cout << '#';
        }
        cout << '\n';
    }

    return 0;
}