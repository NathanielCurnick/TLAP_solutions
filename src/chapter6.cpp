#include <iostream>
#include <string>
#include <stdio.h>
#include <typeinfo>
#include <vector>
#include <stdexcept>
using std::cin;
using std::cout;
using namespace std;

struct ListNode {
    int data;
    ListNode *next;
};

typedef ListNode * list_ptr;

int factorial(int n) {
    if (n == 1) return 1;
    else return n * factorial(n - 1);
}

int iter_array_sum(int integers[], int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += integers[i];
    }
    return sum;
}

int delegate_array_sum(int integers[], int size) {
    if (size == 0) return 0;
    int last_number = integers[size - 1];
    int all_but_last_sum = delegate_array_sum(integers, size - 1);
    return last_number + all_but_last_sum;
}




int main(){
    int integers[5] = {1, 2, 3, 4,5};
    int result = delegate_array_sum(integers, 5);
    cout << result;
    return 0;
}