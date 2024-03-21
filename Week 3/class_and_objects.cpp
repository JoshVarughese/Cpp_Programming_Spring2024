#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Define the Game class
class Game
{
public:
    Game()
    {
        // For random seed
        srand(time(0));
    }

    // Defining the playGame function
    void playGame()
    {
        char playAgain;
        do
        {
            // Random number between 1 and 10
            secretNumber = rand() % 10 + 1;
            int guess;
            cout << "Guess the number (1 to 10): ";
            cin >> guess;
            if (guess == secretNumber)
            {
                cout << "Congratulations! You guessed the right number!" << endl;
            }
            else if (guess < 1 || guess > 10)
            {
                cout << "Please pick a number within the range of 1 to 10." << endl;
            }
            else
            {
                cout << "Sorry, the correct number was " << secretNumber << "." << endl;
            }
            cout << "\n";
            cout << "Do you want to play again? (y/n): ";
            cin >> playAgain;
            // Check if the input is neither 'y' nor 'n'
            while (playAgain != 'y' && playAgain != 'n' && playAgain != 'Y' && playAgain != 'N')
            {
                cout << "Invalid input! Please enter 'y' or 'n': ";
                cin >> playAgain;
            }
        } while (playAgain == 'y' || playAgain == 'Y');

        if (playAgain == 'n' || playAgain == 'N')
        {
            cout << "Thanks for playing! Come back soon!" << endl;
        }
    }

private:
    int secretNumber;
};

// Main function
int main()
{
    Game guessGame;       // Create an object of Game
    guessGame.playGame(); // Call the function to play the game
    return 0;
}