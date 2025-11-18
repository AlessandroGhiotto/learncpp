#include <iostream>
#include <cstdint> // for fixed-width integers

void myFirstLoop()
{
    for (int i{1}; i <= 10; ++i)
        std::cout << i << ' ';
#if 0
    // it is euivalente to the following while loop
    { // the block here ensures block scope for i
        int i{1}; // our init-statement
        while (i <= 10) // our condition
        {
            std::cout << i << ' '; // our statement
            ++i; // our end-expression
        }
    }
#endif

    std::cout << '\n';
}

// returns the value base ^ exponent -- watch out for overflow!
std::int64_t pow(int base, int exponent)
{
    std::int64_t total{1};

    for (int i{0}; i < exponent; ++i)
        total *= base;

    return total;
}

void mySecondLoop()
{
    for (int i{9}; i >= 0; --i)
        std::cout << i << ' ';
    std::cout << '\n';
}

void myThirdLoop()
{
    for (int i{0}; i <= 10; i += 2)
        std::cout << i << ' ';
    std::cout << '\n';
}

void nestedLoop()
{
    for (char c{'a'}; c <= 'e'; ++c) // outer loop on letters
    {
        std::cout << c; // print our letter first

        for (int i{0}; i < 3; ++i) // inner loop on all numbers
            std::cout << i;

        std::cout << '\n';
    }
}

int main0()
{
    myFirstLoop();
    mySecondLoop();
    myThirdLoop();
    return 0;
}

///////////////////////////
// EXERCISES
void printEven20()
{
    for (int i{0}; i <= 20; i += 2)
    {
        std::cout << i << " ";
    }
    std::cout << '\n';
}

int sumTo(int N)
{
    int res{0};
    for (int i{0}; i <= N; ++i)
    {
        res += i;
    }
    return res;
}

void fizzbuzz(int N)
{
    for (int i{1}; i <= N; ++i)
    {
        if (i % 3 == 0)
            std::cout << "fizz";
        if (i % 5 == 0)
            std::cout << "buzz";
        if (i % 3 != 0 && i % 5 != 0)
            std::cout << i;

        std::cout << '\n';
    }
}

void fizzbuzz2(int N)
{
    for (int i{1}; i <= N; ++i)
    {
        if (i % 3 == 0)
            std::cout << "fizz";
        if (i % 5 == 0)
            std::cout << "buzz";
        if (i % 7 == 0)
            std::cout << "pop";
        if (i % 3 != 0 && i % 5 != 0 && i % 7 != 0)
            std::cout << i;

        std::cout << '\n';
    }
}

int main()
{
    // printEven20();
    // std::cout << sumTo(5) << '\n';
    fizzbuzz2(150);
    return 0;
}
