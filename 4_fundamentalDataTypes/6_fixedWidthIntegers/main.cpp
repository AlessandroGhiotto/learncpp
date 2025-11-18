#include <cstdint> // for fixed-width integers
#include <iostream>

int main0()
{
    int x{32767};           // x may be 16-bits or 32-bits
    x = x + 1;              // 32768 overflows if int is 16-bits, okay if int is 32-bits
    std::cout << x << '\n'; // what will this print?

    std::int32_t y{32767}; // y is always a 32-bit integer
    y = y + 1;             // so 32768 will always fit - I'm sure about it
    std::cout << y << '\n';

    std::int8_t z{65};      // initialize 8-bit integral type with value 65
    std::cout << z << '\n'; // You're probably expecting this to print 65 - prints A

    return 0;
}

// fast and least types
int main()
{
    std::cout << "least 8:  " << sizeof(std::int_least8_t) * 8 << " bits\n";
    std::cout << "least 16: " << sizeof(std::int_least16_t) * 8 << " bits\n";
    std::cout << "least 32: " << sizeof(std::int_least32_t) * 8 << " bits\n";
    std::cout << '\n';
    std::cout << "fast 8:  " << sizeof(std::int_fast8_t) * 8 << " bits\n";
    std::cout << "fast 16: " << sizeof(std::int_fast16_t) * 8 << " bits\n";
    std::cout << "fast 32: " << sizeof(std::int_fast32_t) * 8 << " bits\n";

    return 0;
}
