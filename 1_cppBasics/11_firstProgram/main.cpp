#include <iostream>

int main0()
{
    std::cout << "Enter an integer: ";

    int num{};
    std::cin >> num;

    // use an expression to multiply num * 2 at the point where we are going to print it
    // std::cout << "Double that number is: " << num * 2 << '\n';

    std::cout << "Double " << num << " is: " << num * 2 << '\n';
    std::cout << "Triple " << num << " is: " << num * 3 << '\n';

    return 0;
}

int main1()
{
    std::cout << "Enter an integer: ";
    int x{};
    std::cin >> x;

    std::cout << "Enter another integer: ";
    int y{};
    std::cin >> y;

    std::cout << x << " + " << y << " is " << x + y << ".\n";
    std::cout << x << " - " << y << " is " << x - y << ".\n";

    return 0;
}
