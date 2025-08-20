#include <iostream>

bool isOdd(int x)
{
    // return (x % 2) == 1; // fails when x is -5
    // always better to compare the % with 0
    return (x % 2) != 0; // could also write return (x % 2)
}

int main0()
{
    std::cout << "Enter an integer: ";
    int x{};
    std::cin >> x;

    std::cout << "Enter another integer: ";
    int y{};
    std::cin >> y;

    std::cout << "The remainder is: " << x % y << '\n';

    // nice use for the remainder operator:
    if ((x % y) == 0)
        std::cout << x << " is evenly divisible by " << y << '\n';
    else
        std::cout << x << " is not evenly divisible by " << y << '\n';

    return 0;
}

///////////////////////////////////////7
// POWER OP
#include <cmath>
#include <cassert> // for assert
#include <cstdint> // for std::int64_t

// note: exp must be non-negative
// note: does not perform range/overflow checking, use with caution
constexpr std::int64_t powint(std::int64_t base, int exp)
{
    assert(exp >= 0 && "powint: exp parameter has negative value");

    // Handle 0 case
    if (base == 0)
        return (exp == 0) ? 1 : 0;

    std::int64_t result{1};
    while (exp > 0)
    {
        if (exp & 1) // if exp is odd
            result *= base;
        exp /= 2;
        base *= base;
    }

    return result;
}

int main1()
{
    double x{std::pow(7.0, 12.0)}; // 3 to the 4th power
    std::cout << x << '\n';
    std::cout << powint(7, 12) << '\n'; // 7 to the 12th power

    return 0;
}

//////////////
// EXERCISE
constexpr bool isEven(int n)
{
    return (n % 2) == 0;
}
void printRes(int n)
{
    bool even{isEven(n)};
    if (even)
        std::cout << n << " is Even.\n";
    else
        std::cout << n << " is Odd.\n";
}
int main()
{
    printRes(0);
    printRes(1);
    printRes(2);
    printRes(-1);
    printRes(-2);

    return 0;
}
