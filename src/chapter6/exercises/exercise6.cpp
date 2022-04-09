#include <cstddef>
#include <iostream>
using std::cout;

struct Data
{
    int data;
    Data *next;
};

typedef Data *ListData;

bool determine_parity(ListData ld)
{
    if (ld == NULL)
        return true;

    bool parity_of_one = ld->data;
    bool parity_of_all_but_last = determine_parity(ld->next);

    if (parity_of_one)
    {
        return !parity_of_all_but_last;
    }

    return parity_of_all_but_last;
}

int main()
{
    ListData ld;

    Data *node1 = new Data;
    node1->data = 1;

    Data *node2 = new Data;
    node2->data = 1;

    Data *node3 = new Data;
    node3->data = 0;

    Data *node4 = new Data;
    node4->data = 0;

    Data *node5 = new Data;
    node5->data = 1;

    ld = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = NULL;

    node1 = node2 = node3 = node4 = node5 = NULL;

    cout << "Parity of list: " << determine_parity(ld) << "\n";
}