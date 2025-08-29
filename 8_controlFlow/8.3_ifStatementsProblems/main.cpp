#include <iostream>
#define PASS

void foo(int x, int y)
{
    // in this way we can mimic the behaviour of "pass" in python
    if (x > y)
        PASS;
    else
        PASS;
    // this is identical to just if (x>y);else;
    // the PASS is just for the reader, usually we have some functionality to add later in this places
}

int main()
{
    std::cout << "Enter a number: ";
    int x{};
    std::cin >> x;

#if 0
    // OPTION 1
    if (x >= 0) // outer if-statement
        // it is bad coding style to nest if statements this way
        if (x <= 20) // inner if-statement
            std::cout << x << " is between 0 and 20\n";

    // DANGLING ELSE
    // which if statement does this else belong to?
    else
        std::cout << x << " is negative\n";

    // OPTION 2
    if (x >= 0) // outer if statement
    {
        if (x <= 20) // inner if statement
            std::cout << x << " is between 0 and 20\n";
        else // attached to inner if statement
            std::cout << x << " is negative\n";
    }
#endif

    // OPTION 3
    // nested if statements usually can be written better using "if-else" or logical operators
    if (x < 0)
        std::cout << x << " is negative\n";
    else if (x <= 20) // only executes if x >= 0
        std::cout << x << " is between 0 and 20\n";
    else // only executes if x > 20
        std::cout << x << " is greater than 20\n";

    return 0;
}

int main1()
{
    foo(4, 7);

    return 0;
}
