// Problem 10, Positive or Negative, Page 39

#include <iostream>
using std::cin;
using std::cout;

int main()
{
    int number;
    int positive_count = 0;
    int negative_count = 0;
    for (int i = 1; i <= 10; i++)
    {
        cin >> number;
        if (number > 0)
            positive_count++;
        if (number < 0)
            negative_count++;
    }
    char response;
    cout << "Do you want the (p)ositive or (n)egative count?";
    cin >> response;
    if (response == 'p')
        cout << "Positive count is " << positive_count << "\n";
    if (response == 'n')
        cout << "Negative count is " << negative_count << "\n";
}