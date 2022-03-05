#include <map>
#include <iostream>
using std::cout;
using std::map;
int main()
{
    map<int, int> count;
    const int nums[] = {1, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++)
    {
        count[nums[i]]++;
    }

    int mode = 0;
    int appearances = 0;
    for (auto &element : count)
    {
        if (element.second > appearances)
        {
            mode = element.first;
            appearances = element.second;
        }
    }
    cout << "The mode is " << mode;
}