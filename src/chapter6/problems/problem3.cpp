#include <cstddef>

struct ListNode
{
    int data;
    ListNode *next;
};

typedef ListNode *ListPointer;

int count_neg(ListPointer head)
{
    if (head == NULL)
        return 0;
    int list_count = count_neg(head->next);
    if (head->data < 0)
        list_count++;
    return list_count;
}

int main()
{
    // TODO
}