#include <cstddef>
#include <iostream>
using std::cout;

struct Data
{
    int data;
    Data *next;
};

typedef Data *ListData;

int add_positive_numbers(ListData ld)
{
    if (ld == NULL)
        return 0;

    int last_num = ld->data;
    int sum_all_but_last = add_positive_numbers(ld->next);

    if (last_num > 0)
        return last_num + sum_all_but_last;

    return sum_all_but_last;
}

int main()
{
    ListData ld;

    Data *node1 = new Data;
    node1->data = 1;

    Data *node2 = new Data;
    node2->data = 2;

    Data *node3 = new Data;
    node3->data = -1;

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

    cout << "Sum of all positive: " << add_positive_numbers(ld) << "\n";
}