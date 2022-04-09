#include <cstddef>
#include <iostream>
using std::cout;

bool iterative_solution(int data[], int size)
{
    bool res = true;
    for (int i = 0; i < size; i++)
    {
        if (data[i] == 1)
            res = !res;
    }

    return res;
}

bool recursive_solution(int data[], int size)
{
    if (size == 0)
        return true;

    int last_number = data[size - 1];
    bool all_but_last_parity = recursive_solution(data, size - 1);

    if (last_number == 1)
        return !all_but_last_parity;

    return all_but_last_parity;
}

int main()
{
    int data[10] = {1, 0, 1, 1, 1, 1, 1, 0, 0, 0};

    cout << "Iterative solution: " << iterative_solution(data, 10) << "\n";
    cout << "Recursive_solution: " << recursive_solution(data, 10) << "\n";
}