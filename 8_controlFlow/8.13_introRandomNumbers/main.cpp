#include <iostream>

int plusOne()
{
    static int s_state{3}; // only initialized the first time this function is called

    // Generate the next number

    ++s_state;      // first we modify the state
    return s_state; // then we use the new state to generate the next number in the sequence
}

int main0()
{
    std::cout << plusOne() << '\n';
    std::cout << plusOne() << '\n';
    std::cout << plusOne() << '\n';

    return 0;
}

//////////////////////////////////////////////////////////////
// we can seed our PRNG
unsigned int g_state{0};

void seedPRNG(unsigned int seed)
{
    g_state = seed;
}

unsigned int LCG16() // our PRNG
{
    // We modify the state using large constants and intentional overflow to make it hard
    // for someone to casually determine what the next number in the sequence will be.

    g_state = 8253729 * g_state + 2396403; // first we modify the state
    return g_state % 32768;                // then we use the new state to generate the next number in the sequence
}

void print10()
{
    // Print 10 random numbers
    for (int count{1}; count <= 10; ++count)
    {
        std::cout << LCG16() << '\t';
    }

    std::cout << '\n';
}

int main()
{
    unsigned int x{};
    std::cout << "Enter a seed value: ";
    std::cin >> x;

    seedPRNG(x); // seed our PRNG
    print10();   // generate 10 random values

    return 0;
}
