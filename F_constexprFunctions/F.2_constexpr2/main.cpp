#include <iostream>

int getValue(int x)
{
    return x;
}

// This function can be evaluated at runtime
// When evaluated at compile-time, the function will produce a compilation error
// because the call to getValue(x) cannot be resolved at compile-time
constexpr int foo(int x)
{
    if (x < 0)
        return 0;
    return getValue(x); // call to non-constexpr function here
}

int main1()
{
    int x{foo(5)}; // okay: will evaluate at runtime
    // constexpr int y{foo(5)}; // compile error: foo(5) can't evaluate at compile-time
    std::cout << x << '\n';

    return 0;
}

////////////////////////7
constexpr int greater(int x, int y)
{
    return (x > y ? x : y);
}

int main()
{
    constexpr int g{greater(5, 6)}; // case 1: always evaluated at compile-time
    std::cout << g << " is greater!\n";

    std::cout << greater(5, 6) << " is greater!\n"; // case 2: may be evaluated at either runtime or compile-time

    int x{5};                                       // not constexpr but value is known at compile-time
    std::cout << greater(x, 6) << " is greater!\n"; // case 3: likely evaluated at runtime

    std::cin >> x;
    std::cout << greater(x, 6) << " is greater!\n"; // case 4: always evaluated at runtime

    return 0;
}
