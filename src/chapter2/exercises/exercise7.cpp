#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::string;

// Chapter 2, Exercise 7
// TODO add ability to input and output in binary and decimal

string reverse_string(string &a){
    string output = "";
    for (int i = a.length() - 1; i >= 0; i--){
        output = output + a.at(i);
    }
    return output;
}

int main() {
    cout << "Enter the number (in base 10) to convert to hex (base 16)";
    int input;
    cin >> input;
    std::string output_reversed = "";
    bool looping = true;
    while (looping) {
        int remainder = (input % 16);
        char add;
        switch (remainder) {
            case 10:
                add = 'A';
                break;
            case 11:
                add = 'B';
                break;
            case 12:
                add = 'C';
                break;
            case 13:
                add = 'D';
                break;
            case 14:
                add = 'E';
                break;
            case 15:
                add = 'F';
                break;
            default:
                add = remainder + '0';            
        }

        output_reversed = output_reversed + add;
        input = input / 16;
        
        if (input == 0) {
            looping = false;
        }
    }

    string output = reverse_string(output_reversed);
    cout << output;
}