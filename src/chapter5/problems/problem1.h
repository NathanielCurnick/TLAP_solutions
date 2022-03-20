// I have made this a header file for reuse in problem two

#include <string>
#include <iostream>
using std::cout;
using std::string;
class StudentRecord
{
public:
    StudentRecord();
    StudentRecord(int new_grade, int new_id, string new_name);
    int grade();
    void set_grade(int new_grade);
    int student_id();
    void set_student_id(int new_id);
    string name();
    void set_name(string new_name);
    string letter_grade();
    bool is_valid_grade(int grade);

private:
    int _grade;
    int _student_id;
    string _name;
};

int StudentRecord::grade()
{
    return _grade;
}

void StudentRecord::set_grade(int new_grade)
{
    if (is_valid_grade(new_grade))
    {
        _grade = new_grade;
    }
}

int StudentRecord::student_id()
{
    return _student_id;
}

void StudentRecord::set_student_id(int new_id)
{
    _student_id = new_id;
}

string StudentRecord::name()
{
    return _name;
}

void StudentRecord::set_name(string new_name)
{
    _name = new_name;
}

StudentRecord::StudentRecord(int new_grade, int new_id, string new_name)
{
    set_grade(new_grade);
    set_student_id(new_id);
    set_name(new_name);
}

StudentRecord::StudentRecord()
{
    set_grade(0);
    set_student_id(-1);
    set_name("");
}

string StudentRecord::letter_grade()
{
    if (!is_valid_grade(_grade))
        return "ERROR";
    const int NUMBER_CATEGORIES = 11;
    const string GRADE_LETTER[] = {"F", "D", "D+", "C-", "C", "C+", "B-", "B", "B+", "A-", "A"};
    const int LOWEST_GRADE_SCORE[] = {0, 60, 67, 70, 73, 77, 80, 83, 87, 90, 93};
    int category = 0;

    while (category < NUMBER_CATEGORIES && LOWEST_GRADE_SCORE[category] <= _grade)
    {
        category++;
    }
    return GRADE_LETTER[category - 1];
}

bool StudentRecord::is_valid_grade(int grade)
{
    if (grade >= 0 && grade <= 100)
    {
        return true;
    }
    return false;
}
