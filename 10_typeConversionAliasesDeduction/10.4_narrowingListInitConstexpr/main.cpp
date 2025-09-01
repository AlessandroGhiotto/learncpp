#include <iostream>

int someFcn(int i)
{
    return i;
}

int main()
{
    // If I really need narrowing conversions: DO IT EXPLICITLY
    double d{5.0};

    // someFcn(d); // bad: implicit narrowing conversion will generate compiler warning

    // good: we're explicitly telling the compiler this narrowing conversion is intentional
    someFcn(static_cast<int>(d)); // no warning generated

    // BRACE INIT DISALLOWS NARROWING CONVERSIONS
    // int i { 3.5 }; // won't compile
    [[maybe_unused]] int i{static_cast<int>(d)}; // static_cast<int> converts double to int, initializes i with int result

    // CONSTEXPR
    [[maybe_unused]] constexpr double d2{0.1};
    // [[maybe_unused]] float f{d2}; // not narrowing, even though loss of precision results -warning

    // LIST INIT WITH CONSTSEXPR
    // We can avoid literals with suffixes
    [[maybe_unused]] unsigned int u{5}; // okay (we don't need to use `5u`)
    [[maybe_unused]] float f2{1.5};     // okay (we don't need to use `1.5f`)

    // We can avoid static_casts
    constexpr int n{5};
    [[maybe_unused]] double d3{n}; // okay (we don't need a static_cast here)
    [[maybe_unused]] short s{5};   // okay (there is no suffix for short, we don't need a static_cast here)

    // [[maybe_unused]] float f3{1.23456789}; // not a narrowing conversion, even though precision lost! -warning

    return 0;
}
