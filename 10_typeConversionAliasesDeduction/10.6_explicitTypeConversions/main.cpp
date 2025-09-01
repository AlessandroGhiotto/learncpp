#include <iostream>

int main()
{
    int x{10};
    int y{4};

    std::cout << (double)x / y << '\n'; // C-style cast of x to double
    std::cout << double(x) / y << '\n'; // function-style cast of x to double
    std::cout << "------------------\n";

    // STATIC CAST
    char c{'a'};
    std::cout << static_cast<int>(c) << '\n'; // prints 97 rather than a

    // static cast x to a double so we get floating point division
    std::cout << static_cast<double>(x) / y << '\n'; // prints 2.5

    // a C-style string literal can't be converted to an int, so the following is an invalid conversion
    // int x { static_cast<int>("Hello") }; // invalid: will produce compilation error
    int i{48};
    // char ch = i; // implicit narrowing conversion => WARNING
    char ch{static_cast<char>(i)}; // explicit conversion from int to char, so that a char is assigned to variable ch
    std::cout << ch << '\n';

    int i{100};
    // i = i / 2.5; WARNING
    i = static_cast<int>(i / 2.5);

    // We want to do floating point division, so one of the operands needs to be a floating point type
    std::cout << double{x} / y << '\n'; // okay if int is 32-bit, narrowing if x is 64-bit

    // direct list init allows for signle word types only
    // unsigned char c{'a'};
    // std::cout << unsigned int{c} << '\n';

    return 0;
}
