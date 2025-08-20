#include <iostream>

int main()
{
    // NOT !
    int x{5};
    int y{7};

    if (!(x > y))
        std::cout << x << " is not greater than " << y << '\n';
    else
        std::cout << x << " is greater than " << y << '\n';
    std::cout << "----------------\n";

    // OR ||
    std::cout << "Enter a number: ";
    int value{};
    std::cin >> value;

    if (value == 0 || value == 1)
        std::cout << "You picked 0 or 1\n";
    else
        std::cout << "You did not pick 0 or 1\n";
    std::cout << "----------------\n";

    // AND &&
    if (value > 10 && value < 20)
        std::cout << "Your value is between 10 and 20\n";
    else
        std::cout << "Your value is not between 10 and 20\n";
    std::cout << "----------------\n";

    // XOR !=
    std::cout << "0 XOR 1" << (false != true) << '\n';
    std::cout << "0 XOR 0" << (false != false) << '\n';
    std::cout << "1 XOR 1" << (true != true) << '\n';
    // for non bool values:
    // if (static_cast<bool>(a) != static_cast<bool>(b) != static_cast<bool>(c))
    // THIS IS LONG AJAJAJA
    // if (!!a != !!b != !!c)
    // !!x converts x to bool and negate it two times

    return 0;
}
// NOTE
// (x % 2) == 0  <=>  !(x % 2)
