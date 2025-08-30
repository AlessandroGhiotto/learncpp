#include <iostream>
#include <limits> // for std::numeric_limits
#include "Random.h"

int getGuess(int count, int min, int max)
{
    while (true) // loop until user enters valid input
    {
        std::cout << "Guess #" << count << ": ";

        int guess{};
        std::cin >> guess;

        bool success{std::cin};
        std::cin.clear();                                                   // put us back in 'normal' operation mode (if needed)
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // remove any extra input

        // If we didn't extract anything or the extracted guess is out of bounds, try again
        if (!success || guess < min || guess > max)
            continue;

        return guess;
    }
}

bool playHiLo(int tries, int min, int max)
{
    std::cout << "Let's play a game. I'm thinking of a number between " << min << " and " << max << ". You have " << tries << " tries to guess what it is.\n";
    const int target{Random::get(min, max)};

    for (int i{1}; i <= tries; ++i)
    {
        int guess{getGuess(i, min, max)};

        if (guess < target)
            std::cout << "Your guess is too low.\n";
        else if (guess > target)
            std::cout << "Your guess is too High.\n";
        else // guess == target
        {
            std::cout << "Correct! You win!\n";
            return true;
        }
    }

    std::cout << "Sorry, you lose. The correct number was " << target << ".\n";
    return false;
}

bool playAgain()
{
    // VERSION 1
    // char answer{};
    // while (answer != 'y' && answer != 'n')
    // {
    //     std::cout << "Would you like to play again (y/n)?";
    //     std::cin >> answer;
    // }
    // if (answer == 'y')
    //     return true;
    // else
    //     return false;

    while (true)
    {
        std::cout << "Would you like to play again (y/n)?";

        char ch{};
        std::cin >> ch;

        // clear out any extraneous input
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (ch)
        {
        case 'y':
            return true;
        case 'n':
            return false;
        }
    }
}

int main()
{
    constexpr int tries{7};
    constexpr int min{1};
    constexpr int max{100};

    do
    {
        playHiLo(tries, min, max);
    } while (playAgain());

    std::cout << "Thank you for playing.\n";

    return 0;
}
