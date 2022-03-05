#include <string>
#include <iostream>
#include <stdlib.h>

using std::cout;
struct student
{
    int grade;
    int student_id;
    std::string name;
};

int compare_grade(const void *A, const void *B)
{
    student *student_a = (student *)(A);
    student *student_b = (student *)(B);

    return (student_a->grade - student_b->grade);
}

void print_students(student *student, int array_size)
{
    for (int i = 0; i < array_size; i++)
    {
        cout << student[i].student_id << ": " << student[i].name << " scored " << student[i].grade << "\n";
    }
}

int main()
{
    const int ARRAY_SIZE = 10;
    student studentArray[ARRAY_SIZE]{
        {87, 10001, "Fred"},
        {28, 10002, "Tom"},
        {100, 10003, "Alistair"},
        {78, 10004, "Sasha"},
        {84, 10005, "Erin"},
        {98, 10006, "Belinda"},
        {75, 10007, "Leslie"},
        {70, 10008, "Candy"},
        {81, 10009, "Aretha"},
        {68, 10010, "Veronica"}};

    qsort(studentArray, ARRAY_SIZE, sizeof(student), compare_grade);
    cout << studentArray << "\n";
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        cout << studentArray[i].student_id << ": " << studentArray[i].name << " scored " << studentArray[i].grade << "\n";
    }
}