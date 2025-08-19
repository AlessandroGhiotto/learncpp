#include <iostream>

int main()
{
#if 0
    bool myNameIsAlex{true}; // true is a boolean literal
    double d{3.4};           // 3.4 is a double literal
#endif
    std::cout << "Hello, world!"; // "Hello, world!" is a C-style string literal

    // liteal suffixes
    std::cout << 5 << '\n';    // 5 (no suffix) is type int (by default)
    std::cout << 5L << '\n';   // 5L is type long
    std::cout << 5u << "\n\n"; // 5u is type unsigned int

#if 0
    // in general, we don't need to use them
    int a{5};          // ok: types match
    unsigned int b{6}; // ok: compiler will convert int value 6 to unsigned int value 6
    long c{7};         // ok: compiler will convert int value 7 to long value 7
#endif

    // THIS SUFFIX IS IMPORTANT: f (float)
    std::cout << 5.0 << '\n';  // 5.0 (no suffix) is type double (by default)
    std::cout << 5.0f << '\n'; // 5.0f is type float
#if 0
    // float f { 4.1 }; // warning: 4.1 is a DOUBLE literal, NOT A FLOAT literal
    float f{4.1f}; // use 'f' suffix so the literal is a float and matches variable type of float
    double d{4.1}; // change variable to type double so it matches the literal type double

    // floats
    double pi{3.14159};           // 3.14159 is a double literal in standard notation
    double d{-1.23};              // the literal can be negative
    double why{0.};               // syntactically acceptable, but avoid this because it's hard to see the decimal point (prefer 0.0)
    double avogadro{6.02e23};     // 6.02 x 10^23 is a double literal in scientific notation
    double protonCharge{1.6e-19}; // charge on a proton is 1.6 x 10^-19

    // magic numbers (bad)
    const int maxStudentsPerSchool{ numClassrooms * 30 };
    setMax(30);
    // good - fixed
    const int maxStudentsPerClass { 30 };
    const int totalStudents{ numClassrooms * maxStudentsPerClass }; // now obvious what this 30 means
    const int maxNameLength{ 30 };
    setMax(maxNameLength); // now obvious this 30 is used in a different context
#endif
}
