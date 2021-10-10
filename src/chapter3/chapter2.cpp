#include <iostream>
#include <string>
#include <stdio.h>
#include <typeinfo>
#include <vector>
#include <stdexcept>
using std::cin;
using std::cout;
using namespace std;

int compare_two_numbers(const void * voidA, const void * voidB) {
    int * intA = (int *)(voidA);
    int * intB = (int *)(voidB);
    return * intA - * intB;
}

int get_mode() {
    int ARRAY_SIZE = 5;
    // int measurements[ARRAY_SIZE] = {2, 5, 3, 1, 3, 7, 3, 9, 8, 2};
    int measurements[ARRAY_SIZE] = {1, 1, 1, 1, 1};
    qsort(measurements, ARRAY_SIZE, sizeof(int), compare_two_numbers);
    
    int most_frequency = 0;
    int current_frequency = 0;
    int best_mode_guess = 0;
    int current_number = 0;

    for (int i = 0; i < ARRAY_SIZE; ++i) {
        if (i == 0) {
            current_number = measurements[i];
            current_frequency = 1;
            best_mode_guess = measurements[i];
            continue;
        } else {
            if (measurements[i] == current_number) {
                current_frequency += 1;
            } else {
                if (current_frequency > most_frequency) {
                    best_mode_guess = current_number;
                    most_frequency = current_frequency;
                } else {
                    current_number = measurements[i];
                    current_frequency = 1;
                }
            }
        }
    }
    cout << "The mode is ";
    cout << best_mode_guess;
    return 0;
}

int main(){
    get_mode();
    return 0;
}