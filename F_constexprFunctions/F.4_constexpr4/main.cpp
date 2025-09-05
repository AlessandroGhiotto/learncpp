#include <iostream>

// Constexpr/consteval functions can use non-const local variables
consteval int doSomething(int x, int y) // function is consteval
{
    x = x + 2; // we can modify the value of non-const function parameters

    int z{x + y}; // we can instantiate non-const local variables
    if (x > y)
        z = z - 1; // and then modify their values

    return z;
}

int main0()
{
    constexpr int g{doSomething(5, 6)};
    std::cout << g << '\n';

    return 0;
}

///////////////////////////////////////////////////
constexpr int goo(int c) // goo() is now constexpr
{
    return c;
}

constexpr int foo(int b) // b is not a constant expression within foo()
{
    return goo(b); // if foo() is resolved at compile-time, then `goo(b)` can also be resolved at compile-time
}

int main()
{
    std::cout << foo(5);

    return 0;
}
