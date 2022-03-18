#include <iostream>
using std::cout;

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

ArrayString substring(const ArrayString &s, int start, int len)
{
    if (len > length(s))
        len = length(s);

    if (start + len > length(s))
    {
        start = 0;
        len = length(s);
    };

    ArrayString new_string = new char[len + 1];

    for (int i = 0; i < len; i++)
    {
        new_string[i] = character_at(s, i + start);
    }

    new_string[len] = 0;

    return new_string;
}

void substring_test()
{
    ArrayString s = new char[6];
    s[0] = 'H';
    s[1] = 'e';
    s[2] = 'l';
    s[3] = 'l';
    s[4] = 'o';
    s[5] = '!';
    s[6] = 0;

    cout << s << "\n";

    ArrayString a = substring(s, 1, 4);

    cout << a << "\n";
}

int main()
{
    substring_test();
}