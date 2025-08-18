#include <cstdint>
#include <iostream>

void print(double x) // print takes a double parameter
{
    std::cout << x << '\n';
}

int main0()
{
    int y{5};
    print(y); // y is of type int -> going to be converted

    // implicit type conversion
    // still luckyli we get warnings
    // double d{5}; // okay: int to double is safe
    // int x{5.5};  // error: double to int not safe

    // static cast
    double x{5.5};
    print(static_cast<int>(x));   // explicitly convert double value 5.5 to an int
    print(static_cast<int>(5.5)); // dierctly with the literal
    std::cout << '\n';

    // get the integral value from a char
    char ch{97}; // 97 is ASCII code for 'a'
    std::cout << ch << " has value " << static_cast<int>(ch) << "\n\n";

    // SIGN CONVERSION
    // case 1) everything is okay
    unsigned int u1{5};
    int s1{static_cast<int>(u1)}; // Convert value of u1 to a signed int
    std::cout << s1 << '\n';      // prints 5

    int s2{5};
    unsigned int u2{static_cast<unsigned int>(s2)}; // Convert value of s2 to an unsigned int
    std::cout << u2 << '\n';                        // prints 5

    // case 2) we can't convert -> modulo wrapping
    int a{-7};
    std::cout << a << " -> " << static_cast<unsigned int>(a) << "\n"; // we wrap from 0 to the max value (-6)
    unsigned int b{4294967295};
    std::cout << b << " -> " << static_cast<int>(b) << "\n"; // unsigned int can't hold this number

    return 0;
}

// std::int8_t and std::uint8_t are treated as characters
int main1()
{
    // the number we input are treated as characters, so we read just the first one (ex 42 -> '4' and '2')
    // once is extraced, it is converted into ASCII code
    std::cout << "Enter a number between 0 and 127: ";
    std::int8_t myInt{};
    std::cin >> myInt;

    std::cout << "You entered: " << static_cast<int>(myInt) << '\n'; // we convert to int so we are sure to print int

    return 0;
}

// exercises
int charAsInt(char x) // conversion is at the output
{
    return x;
}
int getInt(int x) // conversion is already at input
{
    return x;
}
int main()
{
    std::cout << "Enter a single character: ";
    char x{};
    std::cin >> x;

    // EXPLICIT CONVERSION
    std::cout << "You entered '" << x << "', which as ASCII code " << static_cast<int>(x) << ".\n";
    // IMPLICIT CONVERSION
    // int x_int{x};
    // std::cout << "You entered '" << x << "', which as ASCII code " << x_int << ".\n";
    // std::cout << "You entered '" << x << "', which as ASCII code " << convertToInt(x) << ".\n";
    return 0;
}
