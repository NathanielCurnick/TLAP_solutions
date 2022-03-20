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

    StudentCollection &operator=(const StudentCollection &rhs);
    StudentCollection(const StudentCollection &original);

private:
    typedef StudentNode *StudentList;
    StudentList _list_head;
    void delete_list(StudentList &list_ptr);
    StudentList copied_list(const StudentList original);
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

StudentCollection::StudentList StudentCollection::copied_list(const StudentList original)
{
    if (original == NULL)
    {
        return NULL;
    }
    StudentList new_list = new StudentNode;
    new_list->student_data = original->student_data;
    StudentNode *old_loop_ptr = original->next;
    StudentNode *new_loop_ptr = new_list;
    while (old_loop_ptr != NULL)
    {
        new_loop_ptr->next = new StudentNode;
        new_loop_ptr = new_loop_ptr->next;
        new_loop_ptr->student_data = old_loop_ptr->student_data;
        old_loop_ptr = old_loop_ptr->next;
    }
    new_loop_ptr->next = NULL;
    return new_list;
}

StudentCollection &StudentCollection::operator=(const StudentCollection &rhs)
{
    if (this != &rhs)
    {
        delete_list(_list_head);
        _list_head = copied_list(rhs._list_head);
    }
    return *this;
}

StudentCollection::StudentCollection(const StudentCollection &original)
{
    _list_head = copied_list(original._list_head);
}

int main() {}