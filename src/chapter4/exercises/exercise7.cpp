#include <cstddef>
#include <iostream>
#include <assert.h>
using std::cout;

struct CharNode
{
    char letter;
    CharNode *next;
};

typedef CharNode *ArrayString;

void append(ArrayString &as, char c)
{
    CharNode *new_node = new CharNode;

    new_node->letter = c;
    new_node->next = NULL;

    CharNode *loop_ptr = as;

    while (loop_ptr != NULL)
    {
        if (loop_ptr->next == NULL)
        {
            loop_ptr->next = new_node;
            return;
        }
        loop_ptr = loop_ptr->next;
    }
}

char character_at(ArrayString &as, int place)
{
    CharNode *loop_ptr = as;
    for (int i = 0; i < place; i++)
    {
        if (loop_ptr == NULL)
        {
            return 0;
        }
        loop_ptr = loop_ptr->next;
    }
    return loop_ptr->letter;
}

void concatenate(ArrayString &as1, ArrayString &as2)
{
    CharNode *loop_ptr1 = as1;

    while (true)
    {
        if (loop_ptr1->next == NULL)
        {
            break;
        }
        loop_ptr1 = loop_ptr1->next;
    }

    CharNode *loop_ptr2 = as2;

    while (loop_ptr2 != NULL)
    {
        CharNode *new_node = new CharNode;
        new_node->letter = loop_ptr2->letter;
        new_node->next = NULL;

        loop_ptr1->next = new_node;
        loop_ptr1 = loop_ptr1->next;
        loop_ptr2 = loop_ptr2->next;
    }

    delete[] as2;
}

void test_concatenate()
{
    ArrayString as;

    CharNode *node1 = new CharNode;
    node1->letter = 'T';

    CharNode *node2 = new CharNode;
    node2->letter = 'E';

    CharNode *node3 = new CharNode;
    node3->letter = 'S';

    CharNode *node4 = new CharNode;
    node4->letter = 'T';

    as = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = NULL;
    node1 = node2 = node3 = node4 = NULL;

    ArrayString as1;

    CharNode *node5 = new CharNode;
    node5->letter = 'B';

    CharNode *node6 = new CharNode;
    node6->letter = 'E';

    CharNode *node7 = new CharNode;
    node7->letter = 'D';

    as1 = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = NULL;
    node5 = node6 = node7 = NULL;

    concatenate(as, as1);

    assert(character_at(as, 4) == 'B');
    cout << "Concatenate successful\n";
}

int main()
{
    test_concatenate();
}