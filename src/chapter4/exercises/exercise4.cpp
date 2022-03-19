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
    return s[0];
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
    new_s[0]++;
    delete[] s;
    s = new_s;
}

void concatenate(ArrayString &s1, ArrayString s2)
{
    int s1_old_length = length(s1);
    int s2_old_length = length(s2);
    int new_length = s1_old_length + s2_old_length - 1;

    ArrayString new_s = new char[new_length];

    for (int i = 1; i < s1_old_length; i++)
    {
        new_s[i] = s1[i];
    }

    for (int i = 0; i < s2_old_length; i++)
    {
        new_s[s1_old_length + i] = s2[i + 1];
    }

    new_s[0] = new_length;
    delete[] s1;
    s1 = new_s;
}

void concatenate_test()
{
    ArrayString a = new char[5];
    a[0] = 5;
    a[1] = 't';
    a[2] = 'e';
    a[3] = 's';
    a[4] = 't';

    ArrayString b = new char[4];
    b[0] = 4;
    b[1] = 'b';
    b[2] = 'e';
    b[3] = 'd';

    concatenate(a, b);
    cout << a << "\n";
}

void append_test()
{
    ArrayString a = new char[5];
    a[0] = 5;
    a[1] = 't';
    a[2] = 'e';
    a[3] = 's';
    a[4] = 't';
    append(a, '!');
    cout << a << "\n";
}

int main()
{
    append_test();
    concatenate_test();
}