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

void test_character_at()
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

    char letter = character_at(as, 1);

    assert(letter == 'E'); // Assert is a powerful way to do tests!
    // It isn't always possible to do assert tests, but you should try to when possible
    cout << "Character at successful!\n";
}

void test_append()
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

    char character = '!';

    append(as, character);

    assert(character_at(as, 5) == '!');
    cout << "Appending successful\n";
}

int main()
{
    test_character_at();
    test_append();
}