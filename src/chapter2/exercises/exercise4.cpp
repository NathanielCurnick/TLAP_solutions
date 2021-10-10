#include <iostream>
using std::cout;

// Chapter 2, Exercise 4, custom shape
// This program should produce the following shape
/* 
###  ###
##    ##
#      #
#      #
##    ##
###  ###
*/ 
// Try making your own
int main() {
    // Top section
    for (int i = 0; i < 3; i++) {
        // Upper left section
        for (int j = 0; j < 4; j++){
            if (j+i < 3) cout << '#';
            else cout << ' ';
        }
        // Upper right section
        for (int j = 0; j < 4; j++){
            if (j-i <= 0) cout << ' ';
            else cout << '#';
        }
        cout << '\n';
    }
    // Bottom section
    for (int i = 3; i > 0; i--) {
        // Upper left section
        for (int j = 0; j < 4; j++){
            if (i+j > 3) cout << ' ';
            else cout << '#';
        }
        // Upper right section
        for (int j = 0; j < 4; j++){
            if (j-i < 0) cout << ' ';
            else cout << '#';
        }
        cout << '\n';
    }
}