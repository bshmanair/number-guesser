/*
TODO: Timer to see how long it takes to guess number
TODO: Implement hint system to provide clues
TODO: Track user's high score under each difficulty level

*/

#include <iostream>
#include <random>

int main(void)
{
    char restart = 'y';
    do
    {
        std::random_device rd; // fetch rand no. from /dev/urandom
        std::mt19937 gen(rd()); // mersenne twister algo
        std::uniform_int_distribution<> distrib(1, 100);
        int correct = distrib(gen);
        int maxChances = 0;
        int usedChances = 0;
        int guess = 0;
        int choice = 0;
        std::string difficulty;
        std::cout << "------------------------------------------------------\n"
                  << "Welcome to the Number Guessing game!\n"
                  << "I'm thinking of a number between 1 and 100.\n"
                  << "You have 5 chances to guess the correct number.\n\n"
                  << "Please select the difficulty level:\n"
                  << "1. Easy (10 chances)\n"
                  << "2. Medium (5 chances)\n"
                  << "3. Hard (3 chances)\n"
                  << "------------------------------------------------------\n";
        do
        {
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            switch (choice)
            {
            case 1:
                maxChances = 10;
                difficulty = "Easy";
                break;
            case 2:
                maxChances = 5;
                difficulty = "Medium";
                break;
            case 3:
                maxChances = 3;
                difficulty = "Hard";
                break;
            default:
                std::cout << "Invalid choice!\n";
                break;
            }
        } while (choice != 1 && choice != 2 && choice != 3);
        std::cout << "Great! You have selected the " << difficulty << " difficulty level.\n"
                  << "Let's start the game!\n\n";
        while (usedChances < maxChances)
        {
            usedChances++;
            std::cout << "Enter your guess: ";
            std::cin >> guess;
            std::cout << '\n';
            if (guess != correct)
            {
                if (correct < guess)
                {
                    std::cout << "Incorrect! The number is less than " << guess << '\n';
                }
                else if (correct > guess)
                {
                    std::cout << "Incorrect! The number is greater than " << guess << '\n';
                }
            }
            else if (correct == guess)
            {
                std::cout << "Congratulations! You guessed the correct number in " << usedChances << " attempts.\n";
                break;
            }
        }
        if (usedChances == maxChances)
        {
            std::cout << "You failed! The correct answer was " << correct << '\n';
        }

        std::cout << "Would you like to play again? (y/n): ";
        std::cin >> restart;
    } while (restart == 'y');

    std::cout << "Thanks for playing!\n";
    return 0;
}