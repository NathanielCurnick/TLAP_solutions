#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
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

int list_to_int(IntList &in)
{
    string s1 = "";

    IntNode *loop_ptr = in;

    while (loop_ptr != NULL)
    {
        string temp = to_string(loop_ptr->num);
        s1.append(temp);
        loop_ptr = loop_ptr->next;
    }

    int num = stoi(s1);
    return num;
}

int sum(IntList &in1, IntList &in2)
{
    int num1 = list_to_int(in1);
    int num2 = list_to_int(in2);

    return num1 + num2;
}

int main()
{
    int x1 = 149;
    IntList in1 = convert_int_to_intnode(x1);
    int x2 = 151;
    IntList in2 = convert_int_to_intnode(x2);
    int res = sum(in1, in2);
    assert(res == 300);
    cout << "Sum successful\n";
}