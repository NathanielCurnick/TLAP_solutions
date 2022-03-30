#include <iostream>
using std::cout;

int array_sum_recursive(int integers[], int size)
{
    if (size == 0)
        return 0;
    int last_number = integers[size - 1];
    int all_but_last_sum = array_sum_recursive(integers, size - 1);
    return last_number + all_but_last_sum;
}

int main()
{
    int size = 10;
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << array_sum_recursive(array, size);
}