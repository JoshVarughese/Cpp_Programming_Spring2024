#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Base CLASS for the game
class Game
{
public:
    // Pure virtual function in order to start the game
    virtual void start() = 0;
};

// Derived CLASS for the game
class NumberGuessingGame : public Game
{ // INHERITANCE: NumberGuessingGame inherits from Game
private:
    int secretNumber;
    int attempts;

public:
    NumberGuessingGame()
    {
        srand(time(0));
        secretNumber = rand() % 100 + 1; // Generate a random number between 1 and 100
        attempts = 0;
    }

    // Start the game
    void start() override
    {
        cout << "Welcome to the Number Guessing Game!" << endl;
        cout << "Try to guess the secret number between 1 and 100." << endl;
        playGame();
    }

    // Method to play the game
    void playGame()
    {
        int guess;
        do
        {
            cout << "Enter your guess: ";
            cin >> guess;
            attempts++;
            if (guess == secretNumber)
            {
                cout << "Congratulations! You guessed the number in " << attempts << " attempts." << endl;
                break;
            }
            else if (guess < secretNumber)
            {
                cout << "Too low. Try again." << endl;
            }
            else
            {
                cout << "Too high. Try again." << endl;
            }
            cout << endl; // For spacing purposes
        } while (true);
    }
};

// Main function
int main()
{
    NumberGuessingGame game; // OBJECT: Create an object of NumberGuessingGame class
    game.start();            // Calling the start method to begin the game
    return 0;
}
