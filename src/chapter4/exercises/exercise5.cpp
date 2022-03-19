#include <cstddef>
#include <iostream>
using std::cout;
// Chapter 4, Problem 2, Page 101

struct ListNode
{
    int student_num;
    int grade;
    ListNode *next;
};

typedef ListNode *StudentCollection;

void remove_record(StudentCollection &sc, int student_num)
{
    ListNode *loop_ptr = sc;
    ListNode *previous = NULL;
    while (loop_ptr != NULL)
    {
        if (loop_ptr->student_num == student_num)
        {
            if (previous == NULL)
            {
                sc = loop_ptr->next;
                delete[] loop_ptr;
                return; // Making assumption there is only one student with that student ID!
            }
            else
            {
                previous->next = loop_ptr->next;
                delete[] loop_ptr;
                return; // Making assumption there is only one student with that student ID!
            }
        }
        else
        {
            previous = loop_ptr;
            loop_ptr = loop_ptr->next;
        }
    }
}

void print_student_collection(StudentCollection &sc)
{
    ListNode *loop_ptr = sc;
    while (loop_ptr != NULL)
    {
        cout << "Student Number: " << loop_ptr->student_num << " Grade: " << loop_ptr->grade << "\n";
        loop_ptr = loop_ptr->next;
    }
}

int main()
{
    StudentCollection sc;

    ListNode *node1 = new ListNode;
    node1->student_num = 1001;
    node1->grade = 78;

    ListNode *node2 = new ListNode;
    node2->student_num = 1012;
    node2->grade = 93;

    ListNode *node3 = new ListNode;
    node3->student_num = 1076;
    node3->grade = 85;

    sc = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;
    node1 = node2 = node3 = NULL;

    print_student_collection(sc);
    remove_record(sc, 1012);
    print_student_collection(sc);
}