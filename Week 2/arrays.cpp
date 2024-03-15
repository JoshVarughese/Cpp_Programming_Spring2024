#include <iostream>
using namespace std;

int main() {
    const int ROWS = 3; 
    const int COLS = 2; 
    int multiArray[ROWS][COLS];

    // User Input
    cout << "Enter " << ROWS*COLS << " integers:" << endl;
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            cin >> multiArray[i][j];
        }
    }

    // The output for the array 
    cout << "" << endl; // to give the input and output space
    cout << "The contents of the array are:" << endl;
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            cout << multiArray[i][j] << ' ';
        }
       cout << endl; // New line at the end of each row
    }

    return 0;
}