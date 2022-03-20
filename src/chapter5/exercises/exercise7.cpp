#include <cstddef>
#include <iostream>
using std::cout;

class StudentCollection
{
public:
    StudentCollection();
    ~StudentCollection();

    void add_student(int student_num, int grade);
    double avergae_record();

    StudentCollection &operator=(const StudentCollection &rhs);
    StudentCollection(const StudentCollection &original);

private:
    struct ListNode
    {
        int student_num;
        int grade;
        ListNode *next;
    };

    ListNode *_sc;
    void delete_list(ListNode *list_ptr);
    ListNode *copied_list(const ListNode *original);
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

StudentCollection::ListNode *StudentCollection::copied_list(const ListNode *original)
{
    if (original == NULL)
    {
        return nullptr;
    }
    ListNode *new_list = new ListNode;
    new_list->student_num = original->student_num;
    new_list->grade = original->grade;
    ListNode *old_loop_ptr = original->next;
    ListNode *new_loop_ptr = new_list;

    while (old_loop_ptr != NULL)
    {
        new_loop_ptr->next = new ListNode;
        new_loop_ptr = new_loop_ptr->next;
        new_loop_ptr->student_num = old_loop_ptr->student_num;
        new_loop_ptr->grade = old_loop_ptr->grade;
        old_loop_ptr = old_loop_ptr->next;
    }
    new_loop_ptr->next = NULL;
    return new_list;
}

double StudentCollection::avergae_record()
{
    int count = 0;
    double sum = 0;
    ListNode *loop_ptr = _sc;
    while (loop_ptr != NULL)
    {
        sum += loop_ptr->grade;
        count++;
        loop_ptr = loop_ptr->next;
    }
    double average = sum / count;
    return average;
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