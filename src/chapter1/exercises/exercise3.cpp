#include <iostream>
using std::cout;

int main() {
    // Upper section
    for (int i = 0; i < 4; i++){
        // Upper left arm
        for (int j = 0; j < i; j++) cout << ' ';
        for (int j = 0; j < i + 1; j++) cout << '#';

        // Upper right arm
        for (int j = 0; j < (3-i) * 4; j++) cout << ' ';
        for (int j = 0; j < i + 1; j++) cout << '#';

        cout << "\n";

    }

    // Lower section

    for (int i = 0; i < 4; i++){
        // Lower left arm
        for (int j = 0; j < 3 - i; j++) cout << ' ';
        for (int j = 0; j < 4 - i; j++) cout << '#';

        // Lower right arm
        for (int j = 0; j < i * 4; j++) cout << ' ';
        for (int j = 0; j < 4 - i; j++) cout << '#';

        cout << "\n";
    }
}