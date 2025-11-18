#include <iostream>

// infinite loops
int main0()
{
    for (unsigned int count{5}; count >= 0; --count) // notice the type of count
    {
        if (count == 0)
            std::cout << "blastoff! ";
        else
            std::cout << count << ' ';
    }

    std::cout << '\n';

    return 0;
}

// precision for floating point
int main1()
{
    float f{0.123456789f};  // f for a float literal
    std::cout << f << '\n'; // the number is rounded

    return 0;
}

// accidental null statements
int main()
{
    std::cout << "Should we blow up the world again? (y/n): ";
    char c{};
    std::cin >> c;

    if (c == 'y')
        ;                     // accidental null statement here
    std::cout << "Kaboom!\n"; // so this will always execute since it's not part of the if-statement

    return 0;
}
