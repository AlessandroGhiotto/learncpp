#include <iostream>
#include <random> // for std::mt19937
#include <chrono> // for std::chrono

void testMT()
{
    std::mt19937 mt{}; // Instantiate a 32-bit Mersenne Twister

    // Print a bunch of random numbers
    for (int count{1}; count <= 40; ++count)
    {
        std::cout << mt() << '\t'; // generate a random number

        // If we've printed 5 numbers, start a new row
        if (count % 5 == 0)
            std::cout << '\n';
    }
}

void rollDice(int times)
{
    // no seeding -> always the same sequence
    // std::mt19937 mt{};

    // Seed our Mersenne Twister using steady_clock
    std::mt19937 mt{static_cast<std::mt19937::result_type>(
        std::chrono::steady_clock::now().time_since_epoch().count())};

    // seeding with random device
    // std::mt19937 mt{std::random_device{}()};

    // Create a reusable random number generator that generates uniform numbers between 1 and 6
    std::uniform_int_distribution die6{1, 6}; // for C++14, use std::uniform_int_distribution<> die6{ 1, 6 };

    // Print a bunch of random numbers
    for (int count{1}; count <= times; ++count)
    {
        std::cout << die6(mt) << '\t'; // generate a roll of the die here

        // If we've printed 10 numbers, start a new row
        if (count % 10 == 0)
            std::cout << '\n';
    }
}

int main()
{
    // testMT();
    rollDice(3);
    return 0;
}
