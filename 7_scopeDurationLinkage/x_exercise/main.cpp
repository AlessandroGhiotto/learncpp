#include <iostream>

// EXERCISE 1

int main0()
{
    std::cout << "Enter a positive number: ";
    int num{};
    std::cin >> num;

    if (num < 0)
    { // the block allows to put multiple statements in the same if condition
        std::cout << "Negative number entered.  Making positive.\n";
        num = -num;
    }

    std::cout << "You entered: " << num << '\n';

    return 0;
}

////////////////////////////////////////
// EXERCISE 2

// in the constants header we have the Constants namespace, in which maxClassSize is defined
// maxClassSize is inline anc constexpr
#include "constants.h"

int main1()
{
    std::cout << "How many students are in your class? ";
    int students{};
    std::cin >> students;

    if (students > Constants::maxClassSize)
        std::cout << "There are too many students in this class\n";
    else
        std::cout << "This class isn't too large\n";

    return 0;
}

//////////////////////////////////////
// EXERCISE 3

// PROBLEMS;
// 1. no way to reset the accumulation without restarting the program.
// 2. no way to have multiple accumulators running
int accumulate(int x)
{
    static int sum{}; // make sum with static duration, is not destroyed when the function call ends
    sum += x;
    return sum;
}

int main()
{
    std::cout << accumulate(4) << '\n'; // prints 4
    std::cout << accumulate(3) << '\n'; // prints 7
    std::cout << accumulate(2) << '\n'; // prints 9
    std::cout << accumulate(1) << '\n'; // prints 10

    return 0;
}
