#include <iostream>

// Const integral variables with a constant expression initializer can be used in constant expressions:
const int a{5};      // a is usable in constant expressions
const int b{a};      // b is usable in constant expressions (a is a constant expression per the prior statement)
const long c{a + 2}; // c is usable in constant expressions (operator+ has constant expression operands)

// Other variables cannot be used in constant expressions (even when they have a constant expression initializer):
int d{5};            // d is not usable in constant expressions (d is non-const)
const int e{d};      // e is not usable in constant expressions (initializer is not a constant expression)
const double f{1.2}; // f is not usable in constant expressions (not a const integral variable)

int getNumber()
{
    std::cout << "Enter a number: ";
    int y{};
    std::cin >> y; // can only execute at runtime

    return y; // this return expression is a runtime expression
}

// The return value of a non-constexpr function is a runtime expression
// even when the return expression is a constant expression
int five()
{
    return 5; // this return expression is a constant expression
}

int main()
{
#if 0
    // Literals can be used in constant expressions
    5;              // constant expression
    1.2;            // constant expression
    "Hello world!"; // constant expression

    // Most operators that have constant expression operands can be used in constant expressions
    5 + 6;           // constant expression
    1.2 * 3.4;       // constant expression
    8 - 5.6;         // constant expression (even though operands have different types)
    sizeof(int) + 1; // constant expression (sizeof can be determined at compile-time)

    // The return values of non-constexpr functions can only be used in runtime expressions
    getNumber(); // runtime expression
    five();      // runtime expression (even though the return expression is a constant expression)

    // Operators without constant expression operands can only be used in runtime expressions
    std::cout << 5; // runtime expression (std::cout isn't a constant expression operand)
#endif

    return 0;
}
