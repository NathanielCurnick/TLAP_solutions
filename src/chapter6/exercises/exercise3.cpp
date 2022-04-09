#include <cstddef>
#include <iostream>
using std::cout;

int iterative_solution(int data[], int size, int target)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (data[i] == target)
            count++;
    }

    return count;
}

int recursive_solution(int data[], int size, int target)
{
    if (size == 0)
        return 0;

    int last_numer = data[size - 1];
    int all_but_last_count = recursive_solution(data, size - 1, target);

    if (last_numer == target)
    {
        return all_but_last_count + 1;
    }

    return all_but_last_count;
}

int main()
{
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 9};

    cout << "Iterative solution: " << iterative_solution(nums, 10, 9) << "\n";
    cout << "Recursive solution: " << recursive_solution(nums, 10, 9) << "\n";
}