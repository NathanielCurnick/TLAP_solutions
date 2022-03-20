#include <cstddef>
#include <iostream>
using std::cout;

class StudentCollection
{
public:
    StudentCollection();
    ~StudentCollection();

    void add_student(int student_num, int grade);

    StudentCollection records_in_range(int low, int high);

private:
    struct ListNode
    {
        int student_num;
        int grade;
        ListNode *next;
    };

    ListNode *_sc;
    void delete_list(ListNode *list_ptr);
};

StudentCollection::StudentCollection()
{
    _sc = nullptr;
}

void StudentCollection::add_student(int student_num, int grade)
{
    ListNode *new_node = new ListNode;
    new_node->student_num = student_num;
    new_node->grade = grade;

    if (_sc == nullptr)
    {
        new_node->next = NULL;
        _sc = new_node;
    }
    else
    {
        new_node->next = _sc;
        _sc = new_node;
    }
}

StudentCollection::~StudentCollection()
{
    delete_list(_sc);
}

void StudentCollection::delete_list(ListNode *list_ptr)
{
    while (list_ptr->next != NULL)
    {
        ListNode *temp = list_ptr;
        list_ptr = list_ptr->next;
        delete temp;
    }
}

StudentCollection StudentCollection::records_in_range(int low, int high)
{
    StudentCollection new_sc = StudentCollection();

    ListNode *loop_ptr = _sc;
    while (loop_ptr != NULL)
    {
        if (loop_ptr->grade >= low && loop_ptr->grade <= high)
        {
            new_sc.add_student(loop_ptr->student_num, loop_ptr->grade);
        }
    }

    return new_sc;
}