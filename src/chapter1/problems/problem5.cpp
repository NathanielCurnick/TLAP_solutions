#include <iostream>
using std::cout;

// Problem 5: A Sideways Triangle, page 29

int main()
{
    // really simple, prints out a sideways triangle shape with hashes
    for (int i = 7; i != 0; --i)
    {
        for (int j = abs(4 - abs(4 - i)); j != 0; --j)
        {
            cout << '#';
        }
        cout << '\n';
    }
    return 0;
}