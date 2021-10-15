#include <iostream>
using std::cout;

// Chapter 4, Problem 1, Page 91

typedef char *ArrayString;

char character_at(ArrayString s, int position)
{
    return s[position];
}

void append(ArrayString &s, char c)
{
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