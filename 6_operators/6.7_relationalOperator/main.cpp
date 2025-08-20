#include <algorithm> // for std::max
#include <cmath>     // for std::abs
#include <iostream>

int main0()
{
    std::cout << "Enter an integer: ";
    int x{};
    std::cin >> x;

    std::cout << "Enter another integer: ";
    int y{};
    std::cin >> y;

    if (x == y)
        std::cout << x << " equals " << y << '\n';
    if (x != y)
        std::cout << x << " does not equal " << y << '\n';
    if (x > y)
        std::cout << x << " is greater than " << y << '\n';
    if (x < y)
        std::cout << x << " is less than " << y << '\n';
    if (x >= y)
        std::cout << x << " is greater than or equal to " << y << '\n';
    if (x <= y)
        std::cout << x << " is less than or equal to " << y << '\n';

    return 0;
}

// COMPARING FLOATING POINT VALUES IS DANGEROUS
// absEpsilon is an absolute value - this is bad, e should depend on the magnitude of a/b
#if 0
bool approximatelyEqualAbs(double a, double b, double absEpsilon)
{
    // if the distance between a and b is less than or equal to absEpsilon, then a and b are "close enough"
    return std::abs(a - b) <= absEpsilon;
}
#endif
// Return true if the difference between a and b is within epsilon percent of the larger of a and b
// this is bad if we are close to 0!
bool approximatelyEqualRel(double a, double b, double relEpsilon)
{
    return (std::abs(a - b) <= (std::max(std::abs(a), std::abs(b)) * relEpsilon));
}
// Return true if the difference between a and b is less than or equal to absEpsilon, or within relEpsilon percent of the larger of a and b
// we combine both methods, bas epsilon is used for values close to zero. otherwise the relative version is used
bool approximatelyEqualAbsRel(double a, double b, double absEpsilon, double relEpsilon)
{
    // Check if the numbers are really close -- needed when comparing numbers near zero.
    if (std::abs(a - b) <= absEpsilon)
        return true;

    // Otherwise fall back to Knuth's algorithm
    return approximatelyEqualRel(a, b, relEpsilon);
}

int main()
{
    // a is really close to 1.0, but has rounding errors
    constexpr double a{0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1};

    constexpr double relEps{1e-8};
    constexpr double absEps{1e-12};

    std::cout << std::boolalpha; // print true or false instead of 1 or 0

    std::cout << approximatelyEqualRel(a, 1.0, relEps) << '\n';       // compare "almost 1.0" to 1.0
    std::cout << approximatelyEqualRel(a - 1.0, 0.0, relEps) << '\n'; // compare "almost 0.0" to 0.0

    std::cout << approximatelyEqualAbsRel(a, 1.0, absEps, relEps) << '\n';       // compare "almost 1.0" to 1.0
    std::cout << approximatelyEqualAbsRel(a - 1.0, 0.0, absEps, relEps) << '\n'; // compare "almost 0.0" to 0.0

    return 0;
}
