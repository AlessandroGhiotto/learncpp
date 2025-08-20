#include <iostream>

int main0()
{
    constexpr int x{7};
    constexpr int y{4};

    std::cout << "int / int = " << x / y << '\n';
    // we can just use static_cast<double> to perform floating point division with integers
    // like we would do for initializing a new variable double z{static_cast<double>(x)}
    std::cout << "double / int = " << static_cast<double>(x) / y << '\n';
    std::cout << "int / double = " << x / static_cast<double>(y) << '\n';
    std::cout << "double / double = " << static_cast<double>(x) / static_cast<double>(y) << '\n';

    return 0;
}

int main()
{
    constexpr int apples{12};
    std::cout << "You have " << apples << " apples. Enter how many people to divide them between: ";
    int x{};
    std::cin >> x;

    std::cout << "Each person gets " << apples / x << " whole apples.\n"; // apples and x are int, so this is integer division

    return 0;
}
