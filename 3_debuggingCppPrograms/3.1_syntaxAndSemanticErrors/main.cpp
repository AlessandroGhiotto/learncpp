#include <iostream>

// syntax error:
#if 0
int main( // missing closing brace
{
    int 1x; // variable name can't start with number
    std::cout << "Hi there"; << x +++ << '\n'; // extraneous semicolon, operator+++ does not exist
    return 0 // missing semicolon at end of statement
}
#endif

/////////////////
// Semantic errors

#if 0
int main0()
{
    5 = x;          // x not declared, cannot assign a value to 5
    return "hello"; // "hello" cannot be converted to an int
}
#endif

int main1()
{
    int a{10};
    int b{0};
    std::cout << a << " / " << b << " = " << a / b << '\n'; // division by 0 is undefined in mathematics
    return 0;
}

int main2()
{
    int x;                  // no initializer provided
    std::cout << x << '\n'; // Use of uninitialized variable leads to undefined result

    return 0;
}

int add(int x, int y) // this function is supposed to perform addition
{
    return x - y; // but it doesn't due to the wrong operator being used
}

int main3()
{
    std::cout << "5 + 3 = " << add(5, 3) << '\n'; // should produce 8, but produces 2

    return 0;
}

int main4()
{
    return 0; // function returns here

    std::cout << "Hello, world!\n"; // so this never executes
}
