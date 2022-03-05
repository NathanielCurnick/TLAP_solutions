#include <iostream>
#include <stdlib.h>
using std::cout;

bool sorted(int *int_array, int ARRAY_SIZE)
{
    int lowest = 0;
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if (*(int_array + i) < lowest)
        {
            return false;
        }
        else
        {
            lowest = *(int_array + i);
        }
    }
    return true;
}

int main()
{
    const int ARRAY_SIZE = 10; // ARRAY_SIZE must be const or it could change, thus messing up the length of the arrays!
    int myNum[3] = {10, 20, 30};
    int sorted_array[ARRAY_SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int unsorted_array[ARRAY_SIZE] = {9, 6, 7, 3, 5, 7, 8, 2, 1, 0};

    cout << sorted(sorted_array, ARRAY_SIZE) << "\n";
    cout << sorted(unsorted_array, ARRAY_SIZE) << "\n";
}