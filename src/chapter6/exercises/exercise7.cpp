#include <cstddef>
#include <iostream>
using std::cout;

struct Data
{
    int data;
    Data *next;
};

typedef Data *ListData;

int count_target(ListData ld, int target)
{
    if (ld == NULL)
        return 0;

    int last_num = ld->data;
    int all_but_last_count = count_target(ld->next, target);

    if (last_num == target)
        return all_but_last_count + 1;

    return all_but_last_count;
}

int main()
{
    ListData ld;

    Data *node1 = new Data;
    node1->data = 1;

    Data *node2 = new Data;
    node2->data = 2;

    Data *node3 = new Data;
    node3->data = 2;

    Data *node4 = new Data;
    node4->data = 3;

    Data *node5 = new Data;
    node5->data = 4;

    ld = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = NULL;

    node1 = node2 = node3 = node4 = node5 = NULL;

    cout << "Sum of all positive: " << count_target(ld, 2) << "\n";
}