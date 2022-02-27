#include <iostream>
using std::cout;

// Chapter 4, Problem 1, Page 91

typedef char *ArrayString;

char character_at(ArrayString s, int position)
{
    return s[position];
}

int length(ArrayString s)
{
    int count = 0;
    while (s[count] != 0)
    {
        count++;
    }
    return count;
}

void append(ArrayString &s, char c)
{
    int old_length = length(s);
    ArrayString new_s = new char[old_length + 2];
    for (int i = 0; i < old_length; i++)
    {
        new_s[i] = s[i];
    }
    new_s[old_length] = c;
    new_s[old_length + 1] = 0;
    delete[] s;
    s = new_s;
}

void concatenate(ArrayString &s1, ArrayString s2)
{
    int s1_old_length = length(s1);
    int s2_old_length = length(s2);
    int new_length = s1_old_length + s2_old_length;

    ArrayString new_s = new char[new_length + 1];

    for (int i = 0; i < s1_old_length; i++)
    {
        new_s[i] = s1[i];
    }

    for (int i = 0; i < s2_old_length; i++)
    {
        new_s[s1_old_length + i] = s2[i];
    }

    new_s[new_length] = 0;
    delete[] s1;
    s1 = new_s;
}

void concatenate_tester()
{
    ArrayString a = new char[5];
    a[0] = 't';
    a[1] = 'e';
    a[2] = 's';
    a[3] = 't';
    a[4] = 0;

    ArrayString b = new char[4];
    b[0] = 'b';
    b[1] = 'e';
    b[2] = 'd';
    b[3] = 0;

    concatenate(a, b);
}

void append_test()
{
    ArrayString a = new char[5];
    a[0] = 't';
    a[1] = 'e';
    a[2] = 's';
    a[3] = 't';
    a[4] = 0;
    append(a, '!');
    cout << a << "\n";
}