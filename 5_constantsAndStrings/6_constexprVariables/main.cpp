#include <iostream>

// The return value of a non-constexpr function is not constexpr
int five()
{
    return 5;
}

int main0()
{
    constexpr double gravity{9.8}; // ok: 9.8 is a constant expression
    constexpr int sum{4 + 5};      // ok: 4 + 5 is a constant expression
    constexpr int something{sum};  // ok: sum is a constant expression
    std::cout << gravity << " " << sum << " " << something;

    std::cout << "Enter your age: ";
    int age{};
    std::cin >> age;

    // constexpr int myAge{age}; // compile error: age is not a constant expression
    // constexpr int f{five()};  // compile error: return value of five() is not constexpr

    return 0;
}

int max(int x, int y) // this is a non-constexpr function
{
    if (x > y)
        return x;
    else
        return y;
}

constexpr int cmax(int x, int y) // this is a constexpr function
{
    if (x > y)
        return x;
    else
        return y;
}

int main()
{
    int m1{max(5, 6)};       // ok
    const int m2{max(5, 6)}; // ok
    // constexpr int m3{max(5, 6)}; // compile error: max(5, 6) not a constant expression

    int m4{cmax(5, 6)};           // ok: may evaluate at compile-time or runtime
    const int m5{cmax(5, 6)};     // ok: may evaluate at compile-time or runtime
    constexpr int m6{cmax(5, 6)}; // okay: must evaluate at compile-time

    std::cout << m1 << m2 << m4 << m5 << m6;

    return 0;
}
