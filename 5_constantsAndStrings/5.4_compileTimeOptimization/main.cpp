// compile-time vs run-time constants
int five()
{
    return 5;
}
int pass(const int x) // x is a runtime constant
{
    return x;
}
int main()
{
    // The following are non-constants:
    [[maybe_unused]] int a{5};

    // The following are compile-time constants:
    [[maybe_unused]] const int b{5};
    [[maybe_unused]] const double c{1.2};
    [[maybe_unused]] const int d{b}; // b is a compile-time constant

    // The following are runtime constants:
    [[maybe_unused]] const int e{a};       // a is non-const
    [[maybe_unused]] const int f{e};       // e is a runtime constant
    [[maybe_unused]] const int g{five()};  // return value isn't known until runtime
    [[maybe_unused]] const int h{pass(5)}; // return value isn't known until runtime

    return 0;
}
