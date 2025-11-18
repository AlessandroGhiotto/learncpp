#include <iostream>

using Deg = double;
using Rad = double;

namespace constants
{
    constexpr double pi{3.14159};
}

Rad convertToRadians(Deg degrees)
{
    return degrees * constants::pi / 180;
}

int main()
{
    std::cout << "Enter a number of degrees: ";
    Deg degrees{};
    std::cin >> degrees;

    Rad radians{convertToRadians(degrees)};
    std::cout << degrees << " degrees is " << radians << " radians.\n";

    return 0;
}
