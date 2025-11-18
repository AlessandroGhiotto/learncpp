#include <iostream>

int main()
{
    // VALUE PRESERVING CONVERSIONS
    int n{5};
    [[maybe_unused]] long l = n; // okay, produces long value 5

    short s{5};
    [[maybe_unused]] double d = s; // okay, produces double value 5.0

    // they can be converted back
    int m = static_cast<int>(static_cast<long>(3)); // convert int 3 to long and back
    std::cout << m << '\n';                         // prints 3

    char c = static_cast<char>(static_cast<double>('c')); // convert 'c' to double and back
    std::cout << c << '\n';                               // prints 'c'

    // REINTERPRETATIVE CONVERSIONS
#if 0
    int n1{5};
    // even if this are okay, we still get a warning
    unsigned int u1{n1}; // okay: will be converted to unsigned int 5 (value preserved)

    int n2{-5};
    unsigned int u2{n2}; // bad: will result in large integer outside range of signed int
#endif

    // LOSSY CONVERSIONS
    // if we convert and then convert bakc we may lose something and get a different value
    int u = static_cast<int>(static_cast<unsigned int>(-5)); // convert '-5' to unsigned and back
    std::cout << u << '\n';                                  // prints -5

    double d1{static_cast<double>(static_cast<int>(3.5))}; // convert double 3.5 to int and back
    std::cout << d1 << '\n';                               // prints 3

    double d2{static_cast<double>(static_cast<float>(1.23456789))}; // convert double 1.23456789 to float and back
    std::cout << d2 << '\n';                                        // prints 1.23457

    return 0;
}
