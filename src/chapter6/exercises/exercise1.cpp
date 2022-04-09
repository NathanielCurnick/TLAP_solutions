#include <cstddef>
#include <iostream>
using std::cout;

int iter_solution(int data[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        if (data[i] > 0)
            sum += data[i];
    }

    return sum;
}

int recursive_solution(int data[], int size)
{
    if (size == 0)
        return 0;
    int last_number = data[size - 1];
    int all_but_last_sum = recursive_solution(data, size - 1);
    if (last_number > 0)
    {
        return last_number + all_but_last_sum;
    }
    else
    {
        return all_but_last_sum;
    }
}

int main()
{
    int data[10] = {-1, -2, -3, -4, -5, 1, 2, 3, 4, 5};

    cout << "Iterative solution: " << iter_solution(data, 10) << "\n";
    cout << "Recursive solution: " << recursive_solution(data, 10) << "\n";
}