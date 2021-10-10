#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::string;

// Chapter 2, Exercsie 6

string reverse_string(string &a){
    string output = "";
    for (int i = a.length() - 1; i >= 0; i--){
        output = output + a.at(i);
    }
    return output;
}

int main() {
    cout << "Enter the number (in base 10) to convert to binary (base 2)";
    int input;
    cin >> input;
    std::string output_reversed = "";
    bool looping = true;
    while (looping) {
        char add = (input % 2) + '0';
        output_reversed = output_reversed + add;
        input = input / 2;
        
        if (input == 0) {
            looping = false;
        }
    }

    string output = reverse_string(output_reversed);
    cout << output;
}