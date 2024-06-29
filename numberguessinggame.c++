#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Generate a random number between 1 and 50
    int secretNumber = rand() % 50 + 1;

    std::cout << "Welcome to the number guessing game!" << std::endl;
    std::cout << "I'm thinking a number between 1 and 50." << std::endl;

    int userGuess;
    while (true) {
        // Ask the user to guess the number
        std::cout << "Guess a number: ";
        std::cin >> userGuess;

        // Check if the user's guess is correct
        if (userGuess == secretNumber) {
            std::cout << "Congratulations! You guessed the correct number!" << std::endl;
            break;
        }

        // Provide feedback on whether the guess is too high or too low
        else if (userGuess > secretNumber) {
            std::cout << "Your guess is too high. Try again!" << std::endl;
        } else {
            std::cout << "Your guess is too low. Try again!" << std::endl;
        }
    }
    return 0;
}
