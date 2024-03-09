#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0)); 

    int secretNumber = rand() % 100 + 1; // Generate a random number between 1 and 100
    int guess;
    int attempts = 0;

    cout << "The Number Guessing Game!\n";
    cout << "Pick a Number Between 1 - 100 \n";
    cout << "\n"; // Seperation between the title/instruction and the "Enter your guess" input

    while (true) {
        cout << "Enter your guess: ";
        cin >> guess;

        attempts++; // To track the number of attempts. 

        if (guess == secretNumber) {
            cout << "Congratulations! You guessed the number in " << attempts << " attempts.\n";
            break;
        } else if (guess < secretNumber) {
            cout << "Too low! Try again.\n";
        } else {
            cout << "Too high! Try again.\n";
        }

        cout << "\n"; // So the attempts can have some seperation 
    }

    return 0;
}
