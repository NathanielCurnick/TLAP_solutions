#include <iostream>
using std::cout;

// This function should create an upside down pyramid of hashes

// TODO I can probably simplify this somewhat

int main()
{
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