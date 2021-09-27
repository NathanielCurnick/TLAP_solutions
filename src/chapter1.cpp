#include <iostream>
#include <string>
#include <stdio.h>
#include <typeinfo>
#include <vector>
#include <stdexcept>
using std::cin;
using std::cout;
using namespace std;

int half_triangle_hash(){
    // Really simple, prints out a half tringle shape of hashes
    for (int i = 5; i != 0; --i) {
        for (int j = i; j != 0; --j) {
            cout << '#';
        }
        cout << '\n';
    }

return 0;
}

int sideways_triangle_hash(){
    // really simple, prints out a sideways triangle shape with hashes 
    for (int i = 7; i != 0; --i) {
        for (int j = abs(4 - abs(4 - i)); j != 0; --j) {
            cout << '#';
        }
        cout << '\n';
    }
    return 0;
}

int upside_down_pyramid() {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 8; ++j) {
            /* 
            0 -> 8
            1 -> 6
            2 -> 4
            3 -> 2

            8 - (2 * i)

            then we need to make it symmertrical

            let's say True = #
            False = space
                   01234567
            8/0 -> TTTTTTTT
            6/1 -> FTTTTTTF
            4/2 -> FFTTTTFF
            2/3 -> FFFTTFFF
            
            */
            if (j < 4) {
                if ((j - i) < 0) {
                    cout << " ";
                } else {
                    cout << "#";
                }
            } else if (j >= 4) {
                if ((j + i) < 8) {
                    cout << "#";
                } else {
                    cout << " ";
                }
            }
        }
        cout << "\n";
    }
    return 0;
}

int luhn_checksum() {
    // finds the Luhn checksum number of an entered character 
    string input;
    cout << "Enter a number";
    cin >> input;
    int sum = 0;
    for (int i = 0; i < input.length(); ++i) {
        int char_num = input.at(i) - 48; // minus 48 converts char -> int
        if ((i + 1) % 2 == 0) {
            
            // cout << char_num << endl;

            int doubled_char = char_num * 2;
            // cout << doubled_char << endl;
            string doubled_char_s = to_string(doubled_char);
            for (int j = 0; j < doubled_char_s.length(); ++j) {
                int temp = doubled_char_s.at(j) - 48;
                // cout << temp << endl;
                sum += temp;
            }
        }
        else {
            sum += char_num;
        }
    }

    int num_to_add = 10 - (sum % 10);
    cout << "num to add" << endl;
    cout << num_to_add;
    // cout << "sum";
    // cout << sum;

    return 0;
}

string convert_to_string(vector<char> &a, int size) {
    string s = "";
    for (int i = 0; i < size; ++i) {
        s = s + a[i];
        // cout << a[i];
    }
    return s;
}

string return_character(int input, int mode) {
    string output;
    switch (mode) {
    case 0:
        output = input + 'A' - 1;
        break;
    
    case 1:
        output = input + 'a' - 1;
        break;

    case 2:
        switch (input)
        {
        case 1: output = '!'; break;
        case 2: output = '?'; break;
        case 3: output = ','; break;
        case 4: output = '.'; break;
        case 5: output = ' '; break;
        case 6: output = ';'; break;
        case 7: output = '"'; break;
        case 8: output = '\''; break;
        
        default:
            throw invalid_argument("punctuation out of bounds");
        }
        break;

    default:
        throw invalid_argument("decode mode out of bounds");
    }

    return output;
}

int decode() {
    vector<int> encoded_message {18, 12312, 171, 763, 98423, 1208, 216, 11, 500, 18, 241, 0, 32, 20620, 27, 10};
    int decode_mode = 0; // decode of 0 is upper, decode of 1 is lower, 2 is punctuation
    string result = "";
    cout << encoded_message.size() << endl;
    for (int i = 0; i < encoded_message.size(); i++) {
        // cout << encoded_message[i] << endl;
        int remainder = 0;
        switch (decode_mode){
        case 0:
            remainder = encoded_message[i] % 27;
            if (remainder == 0) {
                decode_mode = 1;
                break;
            }else {
                result = result + return_character(remainder, decode_mode);
                break;
            }
            
        case 1:
            remainder = encoded_message[i] % 27;
            if (remainder == 0) {
                decode_mode = 2;
                break;
            }else {
                result = result + return_character(remainder, decode_mode);
                break;
            }

        case 2:
            remainder = encoded_message[i] % 9;
            if (remainder == 0) {
                decode_mode = 0;
                break;
            }else {
                result = result + return_character(remainder, decode_mode);
                break;
            }
        
        default:
            throw invalid_argument("decode mode out of bounds");
        }
    }
    // cout << result;
    cout << result << endl;
    
    return 0;
}

int main() {
    upside_down_pyramid();

    return 0;
}
