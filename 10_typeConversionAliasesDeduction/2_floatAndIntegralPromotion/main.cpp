#include <iostream>

void printDouble(double d)
{
    std::cout << d << '\n';
}

void printInt(int x)
{
    std::cout << x << '\n';
}

int main()
{
    // FLOATING POINT PROMOTION
    printDouble(5.0);  // no conversion necessary
    printDouble(4.0f); // numeric promotion of float to double

    // INTEGRAL PROMOTIONS
    printInt(2);

    short s{3};  // there is no short literal suffix, so we'll use a variable for this one
    printInt(s); // numeric promotion of short to int

    printInt('a');  // numeric promotion of char to int
    printInt(true); // numeric promotion of bool to int
}
