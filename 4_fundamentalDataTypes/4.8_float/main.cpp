#include <iostream>
#include <limits>
#include <iomanip> // for output manipulator std::setprecision()

int main0()
{
    // check if our types <re compatible with  IEEE 754 standard
    std::cout << std::boolalpha; // print bool as true or false rather than 1 or 0
    std::cout << "float: " << std::numeric_limits<float>::is_iec559 << '\n';
    std::cout << "double: " << std::numeric_limits<double>::is_iec559 << '\n';
    std::cout << "long double: " << std::numeric_limits<long double>::is_iec559 << '\n';

    return 0;
}

// examples
int a{5};      // 5 means integer
double b{5.0}; // 5.0 is a floating point literal (no suffix means double type by default)
float c{5.0f}; // 5.0 is a floating point literal, f suffix means float type

int d{0};      // 0 is an integer
double e{0.0}; // 0.0 is a double

int main()
{
    std::cout << 5.0 << '\n';
    std::cout << 6.7f << '\n';
    std::cout << 9876543.21 << "\n\n";

    std::cout << 9.87654321f << '\n';
    std::cout << 987.654321f << '\n';
    std::cout << 987654.321f << '\n';
    std::cout << 9876543.21f << '\n';
    std::cout << 0.0000987654321f << "\n\n";

    std::cout << std::setprecision(17);                              // show 17 digits of precision
    std::cout << 3.33333333333333333333333333333333333333f << '\n';  // f suffix means float
    std::cout << 3.33333333333333333333333333333333333333 << "\n\n"; // no suffix means double

    float f{123456789.0f};             // f has 10 significant digits
    std::cout << std::setprecision(9); // to show 9 digits in f
    std::cout << f << "\n\n";

    double d{0.1};
    std::cout << d << '\n'; // use default cout precision of 6
    std::cout << std::setprecision(17);
    std::cout << d << "\n\n";

    std::cout << std::setprecision(17);
    double d1{1.0};
    std::cout << d1 << '\n';
    double d2{0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1}; // should equal 1.0
    std::cout << d2 << "\n\n";

    // inf, nan, ans signed zero
    double zero{0.0};
    double posinf{5.0 / zero}; // positive infinity
    std::cout << posinf << '\n';
    double neginf{-5.0 / zero}; // negative infinity
    std::cout << neginf << '\n';
    double z1{0.0 / posinf}; // positive zero
    std::cout << z1 << '\n';
    double z2{-0.0 / posinf}; // negative zero
    std::cout << z2 << '\n';
    double nan{zero / zero}; // not a number (mathematically invalid)
    std::cout << nan << '\n';

    return 0;
}
