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

void remove_chars(ArrayString &as, int index, int number)
{
    CharNode *loop_ptr = as;
    int counter = 0;

    while (loop_ptr->next != NULL && counter < index - 1)
    {
        loop_ptr = loop_ptr->next;
        counter++;
    }

    CharNode *first_cut = loop_ptr;

    counter = 0;

    while (loop_ptr->next != NULL && counter < number)
    {
        CharNode *temp = loop_ptr;
        loop_ptr = loop_ptr->next;
        delete[] temp;
        counter++;
    }

    first_cut->next = loop_ptr->next;
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

void test_remove_chars()
{
    ArrayString as;

    CharNode *node1 = new CharNode;
    node1->letter = 'H';

    CharNode *node2 = new CharNode;
    node2->letter = 'E';

    CharNode *node3 = new CharNode;
    node3->letter = 'L';

    CharNode *node4 = new CharNode;
    node4->letter = 'L';

    CharNode *node5 = new CharNode;
    node5->letter = 'O';

    as = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = NULL;
    node1 = node2 = node3 = node4 = node5 = NULL;

    remove_chars(as, 1, 3);

    assert(character_at(as, 1) == 'O'); // Assert is a powerful way to do tests!
    // It isn't always possible to do assert tests, but you should try to when possible
    cout << "Remove successful!\n";
}

int main()
{
    test_remove_chars();
}