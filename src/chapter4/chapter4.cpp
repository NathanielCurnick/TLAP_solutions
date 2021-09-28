#include <iostream>
#include <string>
#include <stdio.h>
#include <typeinfo>
#include <vector>
#include <stdexcept>
using std::cin;
using std::cout;
using namespace std;

typedef char * array_string;

struct ListNode {
    int student_num;
    int grade;
    ListNode * next;

};

typedef ListNode * student_collection;




char character_at(array_string s, int position) {
    return s[position];
}

int length(array_string s) {
    int count = 0;
    while (s[count] != 0) {
        ++count;
    }
    return count;
}
void append(array_string &s, char c) {
    int old_length = length(s);
    array_string new_s = new char[old_length + 2];
    for (int i = 0; i < old_length; i++) {
        new_s[i] = s[i];
    }
    new_s[old_length] = c;
    new_s[old_length + 1] = 0;
    delete[] s;
    s = new_s;
}

void concatenate(array_string &s1, array_string s2) {
    int s1_old_length = length(s1);
    int s2_length = length(s2);
    int s1_new_length = s1_old_length + s2_length;
    array_string new_s = new char[s1_new_length + 1];

    for (int i = 0; i < s1_old_length; ++i) {
        new_s[i] = s1[i];
    }

    for (int i = 0; i < s2_length; ++i) {
        new_s[s1_old_length + i] = s2[i];
    }

    new_s[s1_new_length] = 0;
    delete[] s1;
    s1 = new_s;
}

double average_record(student_collection sc) {
    int count = 0;
    double sum = 0;
    ListNode * loop_pointer = sc;
    while (loop_pointer != NULL) {
        sum += loop_pointer->grade;
        ++count;
        loop_pointer = loop_pointer->next;
    }
    double average = sum / count;
    return average;
}

void add_record(student_collection &sc, int student_name, int grade) {
    ListNode * new_node = new ListNode;
    new_node->student_num = student_name;
    new_node->grade = grade;
    new_node->next = sc;
    sc = new_node;

}

int main() {


}