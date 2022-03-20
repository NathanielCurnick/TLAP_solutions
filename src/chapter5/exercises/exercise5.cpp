#include <iostream>
#include <assert.h>
using std::cout;

typedef char *ArrayString;

class VariableString
{
public:
    VariableString();
    VariableString(ArrayString as);
    ~VariableString();

    void set_characters(ArrayString as);
    ArrayString get_characters();

    void concatenate(ArrayString as);
    void append(char c);
    int get_length();
    int get_length(ArrayString as);

    char &operator[](int position);

    void remove(int start, int n);

private:
    ArrayString _characters;
};

void VariableString::set_characters(ArrayString as)
{
    _characters = as;
}

ArrayString VariableString::get_characters()
{
    return _characters;
}

VariableString::VariableString()
{
    _characters = NULL;
}

VariableString::VariableString(ArrayString as)
{
    _characters = as;
}

VariableString::~VariableString()
{
    if (_characters != nullptr)
    {
        delete[] _characters;
    }
}

int VariableString::get_length()
{
    int count = 0;
    while (_characters[count] != 0)
    {
        count++;
    }
    return count;
}

int VariableString::get_length(ArrayString as)
{
    int count = 0;
    while (as[count] != 0)
    {
        count++;
    }
    return count;
}

void VariableString::concatenate(ArrayString as)
{
    if (_characters == NULL)
    {
        return;
    }

    int self_length = get_length();
    int other_length = get_length(as);

    int new_length = self_length + other_length;

    ArrayString new_s = new char[new_length + 1];

    for (int i = 0; i < self_length; i++)
    {
        new_s[i] = _characters[i];
    }

    for (int i = 0; i < other_length; i++)
    {
        new_s[self_length + i] = as[i];
    }

    new_s[new_length] = 0;
    delete[] _characters;
    _characters = new_s;
}

void VariableString::append(char c)
{
    int old_length = get_length();
    ArrayString new_s = new char[old_length + 2];
    for (int i = 0; i < old_length; i++)
    {
        new_s[i] = _characters[i];
    }
    new_s[old_length] = c;
    new_s[old_length + 1] = 0;
    delete[] _characters;
    _characters = new_s;
}

void VariableString::remove(int start, int n)
{
    int length = get_length();
    if (length < n)
    {
        cout << "Number of characters to remove exceeds available characters\n";
        return;
    }

    if (start < 0 || start > length)
    {
        cout << "Start index out of bounds\n";
        return;
    }

    if (n < 0)
    {
        cout << "Attempt to remove negative number of characters\n";
        return;
    }

    if (start + n > length)
    {
        cout << "Attempt to remove more than string length\n";
        return;
    }

    int new_length = length - n;

    ArrayString new_string = new char[new_length + 1];

    for (int i = 0; i < start; i++)
    {
        new_string[i] = _characters[i];
    }

    if (start + n <= new_length)
    {
        for (int i = start + n; i < length; i++)
        {
            new_string[i - n] = _characters[i];
        }
    }

    delete[] _characters;
    _characters = new_string;
}

char &VariableString::operator[](int position)
{
    return _characters[position];
}