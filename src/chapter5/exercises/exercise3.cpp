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
    char character_at(int position);
    int get_length();
    int get_length(ArrayString as);

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

char VariableString::character_at(int position)
{
    return _characters[position];
}

void append_test()
{
    ArrayString a = new char[5];
    a[0] = 't';
    a[1] = 'e';
    a[2] = 's';
    a[3] = 't';
    a[4] = 0;

    VariableString vs = VariableString(a);
    vs.append('!');

    assert(vs.character_at(4) == '!');
    cout << "Append successful\n";
}

void concatenate_test()
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

    VariableString vs = VariableString(a);
    vs.concatenate(b);

    assert(vs.character_at(4) == 'b');
    cout << "Concatenate successful\n";
}

int main()
{
    append_test();
    concatenate_test();
}