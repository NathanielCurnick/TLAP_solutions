#include <string>
#include <iostream>
#include <stdlib.h>
using std::cout;

// TODO Segmentation fault here for some reason

struct student
{
    int grade;
    int student_id;
    std::string name;
};

// void print_students(student *student, int array_size)
// {
//     for (int i = 0; i < array_size; i++)
//     {
//         cout << student[i].student_id << ": " << student[i].name << " scored " << student[i].grade << "\n";
//     }
// }

int compareID(const void *A, const void *B)
{
    student *studentA = (student *)(A);
    student *studentB = (student *)(B);

    return (studentA->student_id - studentB->student_id);
}

int main()
{
    const int ARRAY_SIZE = 10;
    student studentArray[ARRAY_SIZE] = {
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
    cout << "Before Sort:\n";
    // print_students(student_array, ARRAY_SIZE);

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        std::cout << studentArray[i].grade << '\t'
                  << studentArray[i].student_id << '\t'
                  << studentArray[i].name << '\n';
    }

    qsort(studentArray, ARRAY_SIZE, sizeof(student), compareID);
    cout << "Sorting for student ID:\n";
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        std::cout << studentArray[i].grade << '\t'
                  << studentArray[i].student_id << '\t'
                  << studentArray[i].name << '\n';
    }
    return 0;
}