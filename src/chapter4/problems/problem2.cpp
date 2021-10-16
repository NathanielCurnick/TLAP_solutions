#include <cstddef>

// Chapter 4, Problem 2, Page 101

struct ListNode
{
    int student_num;
    int grade;
    ListNode *next;
};

typedef ListNode *StudentCollection;

void add_record(StudentCollection &sc, int student_number, int grade)
{
    ListNode *new_node = new ListNode;
    new_node->student_num = student_number;
    new_node->grade = grade;
    new_node->next = sc;
    sc = new_node;
}

double average_record(StudentCollection sc)
{
    int count = 0;
    double sum = 0;
    ListNode *loop_ptr = sc;
    while (loop_ptr != NULL)
    {
        sum += loop_ptr->grade;
        count++;
        loop_ptr = loop_ptr->next;
    }
    double average = sum / count;
    return average;
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
}