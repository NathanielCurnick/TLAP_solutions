#include "problem1.h"

class StudentCollection
{
private:
    struct StudentNode
    {
        StudentRecord student_data;
        StudentNode *next;
    };

public:
    StudentCollection();
    void add_record(StudentRecord new_student);
    StudentRecord record_with_number(int id_num);
    void remove_record(int id_num);
    ~StudentCollection();

private:
    typedef StudentNode *StudentList;
    StudentList _list_head;
    void delete_list(StudentList &list_ptr);
};

StudentCollection::StudentCollection()
{
    _list_head = NULL;
}

void StudentCollection::add_record(StudentRecord new_student)
{
    StudentNode *new_node = new StudentNode;
    new_node->student_data = new_student;
    new_node->next - _list_head;
    _list_head = new_node;
}

StudentRecord StudentCollection::record_with_number(int id_num)
{
    StudentNode *loop_ptr = _list_head;

    while (loop_ptr->student_data.student_id() != id_num)
    {
        loop_ptr = loop_ptr->next;
    }
    return loop_ptr->student_data;
}

void StudentCollection::remove_record(int id_num)
{
    StudentNode *loop_ptr = _list_head;
    StudentNode *trailing = NULL;
    while (loop_ptr != NULL && loop_ptr->student_data.student_id() != id_num)
    {
        trailing = loop_ptr;
        loop_ptr = loop_ptr->next;
    }
    if (loop_ptr == NULL)
        return;
    if (trailing == NULL)
    {
        _list_head = _list_head->next;
    }
    else
    {
        trailing->next = loop_ptr->next;
    }
    delete loop_ptr;
}

void StudentCollection::delete_list(StudentList &list_ptr)
{
    while (list_ptr != NULL)
    {
        StudentNode *temp = list_ptr;
        list_ptr = list_ptr->next;
        delete temp;
    }
}

StudentCollection::~StudentCollection()
{
    delete_list(_list_head);
}

int main() {}