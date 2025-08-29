#include <iostream>
#include "Random.h"

bool playHiLo(int tries, int min, int max)
{
    std::cout << "Let's play a game. I'm thinking of a number between " << min << " and " << max << ". You have " << tries << " tries to guess what it is.\n";
    const int target{Random::get(min, max)};

    for (int i{1}; i <= tries; ++i)
    {
        std::cout << "Guess #" << i << ": ";

        int guess{};
        std::cin >> guess;

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
