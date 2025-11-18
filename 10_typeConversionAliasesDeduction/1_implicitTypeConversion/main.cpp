#include <iostream>

// IMPLICIT TYPE CONVERSION EXAMPLES
double d{3}; // int value 3 implicitly converted to type double
// d = 6;       // int value 6 implicitly converted to type double #comment it because gets warning

float doSomething1()
{
    return 3.0; // double value 3.0 implicitly converted to type float
}
double division{4.0 / 3}; // int value 3 implicitly converted to type double

void doSomething2(long l)
{
    std::cout << l << '\n';
}

int main()
{
    if (5) // int value 5 implicitly converted to type bool
    {
        std::cout << d;
    }

    doSomething2(3); // int value 3 implicitly converted to type long

    // int x { "14" }; // conversions can fail
    // int x { 3.5 }; // brace-initialization disallows conversions that result in data loss

    return 0;
}
