#include <iostream>

int main0()
{
    std::cout << "Enter an integer: ";
    int x{};
    std::cin >> x;

#if 0
    // OPTION 1
    if (x == 0)
        std::cout << "The value is zero\n";
    if (x != 0)
        std::cout << "The value is non-zero\n";

    // OPTION 2
    bool zero { (x == 0) };
    if (zero)
        std::cout << "The value is zero\n";
    if (!zero)
        std::cout << "The value is non-zero\n";

    // OPTION 3
    if (x == 0)
        std::cout << "The value is zero\n";
    else
        std::cout << "The value is non-zero\n";
#endif

    // CHAINING IF STATEMENTS
    if (x > 0)
        std::cout << "The value is positive\n";
    else if (x < 0)
        std::cout << "The value is negative\n";
    else
        std::cout << "The value is zero\n";

    return 0;
}

////////////////////////////////////////////////////////
// Bools works well with if statements
bool isEqual(int x, int y)
{
    return x == y;
}

int main1()
{
    int x{};
    std::cout << "Enter an integer: ";
    std::cin >> x;

    int y{};
    std::cout << "Enter another integer: ";
    std::cin >> y;

    if (isEqual(x, y))
        std::cout << x << " and " << y << " are equal\n";
    else
        std::cout << x << " and " << y << " aren't equal\n";

    return 0;
}

/////////////////////////////////////////////////
// early returns with if conditions
int abs(int x)
{
    if (x < 0)
        return -x;
    return x;
}
int main2()
{
    std::cout << "|3| = " << abs(3) << '\n';
    std::cout << "|-5| = " << abs(-5) << '\n';

    return 0;
}

///////////////////////////////////777
// is prime exercise
bool isPrime(int x)
{
    if (x == 2)
        return true;
    else if (x == 3)
        return true;
    else if (x == 5)
        return true;
    else if (x == 7)
        return true;
    else
        return false;
}

int main()
{
    int x{};
    std::cout << "Enter an integer in [1, 9] : ";
    std::cin >> x;

    if (isPrime(x))
        std::cout << x << " is prime.\n";
    else
        std::cout << x << " is not prime.\n";

    return 0;
}
