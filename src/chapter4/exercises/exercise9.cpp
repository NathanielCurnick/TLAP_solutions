#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using std::cout;
using std::string;
using std::to_string;
struct IntNode
{
    int num;
    IntNode *next;
};

typedef IntNode *IntList;

IntList convert_int_to_intnode(int x)
{
    string str = to_string(x);
    IntList in;
    IntNode *loop_ptr = in;
    for (int i = 0; i < str.length(); i++)
    {
        if (i == 0)
        {
            IntNode *new_node = new IntNode;
            new_node->next = NULL;
            new_node->num = str[i] - '0';
            loop_ptr = new_node;
            in = loop_ptr;
        }
        else
        {
            IntNode *new_node = new IntNode;
            new_node->next = NULL;
            new_node->num = str[i] - '0';
            loop_ptr->next = new_node;
            loop_ptr = loop_ptr->next;
        }
    }
    return in;
}

void print_intlist(IntList &in)
{
    IntNode *loop_ptr = in;

    while (loop_ptr != NULL)
    {
        cout << loop_ptr->num;
        loop_ptr = loop_ptr->next;
    }
    cout << "\n";
}

int main()
{
    int x = 149;
    IntList in = convert_int_to_intnode(x);
    print_intlist(in);
}