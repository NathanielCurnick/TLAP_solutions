#include <iostream>
using std::cout;
using std::string;

int compareFunc(const void *void_a, const void *void_b)
{
    int *int_a = (int *)(void_a);
    int *int_b = (int *)(void_b);
    return *int_a - *int_b;
}

void print_agents(int *agents, int num_agents, int num_months)
{
    for (int i = 0; i < num_agents; i++)
    {

        for (int j = 0; j < num_months; j++)
        {
            cout << agents[i * j + j] << ", ";
        }
        cout << "\n";
    }
}

int main()
{
    const int NUM_AGENTS = 3;
    const int NUM_MONTHS = 12;

    int sales[NUM_AGENTS][NUM_MONTHS] = {
        {1856, 498, 30924, 87478, 328, 2653, 387, 3754, 387587, 2873, 276, 32},
        {5865, 5456, 3983, 6464, 9957, 4785, 3875, 3838, 4959, 1122, 7766, 2534},
        {23, 55, 67, 99, 265, 376, 232, 223, 4546, 564, 4544, 3434}};

    print_agents(*sales, NUM_AGENTS, NUM_MONTHS);
}
