#include <iostream>
using std::cout;
// Chapter 2, Exercise 2, print a hash of diamonds
// Notice how this is the same as Exercise 1, but a flipped triangle first, so we can double the for loop and make it count down rather than up

int main()
{
    for (int i = 4; i >= 0; --i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if (j < 4)
            {
                if ((j - i) < 0)
                {
                    cout << " ";
                }
                else
                {
                    cout << "#";
                }
            }
            else if (j >= 4)
            {
                if ((j + i) < 8)
                {
                    cout << "#";
                }
                else
                {
                    cout << " ";
                }
            }
        }
        cout << "\n";
    }
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if (j < 4)
            {
                if ((j - i) < 0)
                {
                    cout << " ";
                }
                else
                {
                    cout << "#";
                }
            }
            else if (j >= 4)
            {
                if ((j + i) < 8)
                {
                    cout << "#";
                }
                else
                {
                    cout << " ";
                }
            }
        }
        cout << "\n";
    }
    return 0;
}