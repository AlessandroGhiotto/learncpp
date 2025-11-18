#include <iostream>

int getValue()
{
    // clang-format off
    // -> so the line will not be indented
std::cerr << "getValue() called\n";
    // clang-format on
    return 4;
}

int main0()
{
    // clang-format off
std::cerr << "main() called\n";
    // clang-format on
    std::cout << getValue() << '\n';

    return 0;
}

//////////////////////////////////////////
// print values for debugging
int add(int x, int y)
{
    // clang-format off
std::cerr << "add() called (x=" << x <<", y=" << y << ")\n";
    // clang-format on
    return x + y;
}

void printResult(int z)
{
    std::cout << "The answer is: " << z << '\n';
}

int getUserInput()
{
    std::cout << "Enter a number: ";
    int x{};
    std::cin >> x;
    return x;
}

int main()
{
    int x{getUserInput()};
    // clang-format off
std::cerr << "main::x = " << x << '\n';
    // clang-format on
    int y{getUserInput()};
    // clang-format off
std::cerr << "main::y = " << y << '\n';
    // clang-format on

    int z{add(x, 5)};
    // clang-format off
std::cerr << "main::z = " << z << '\n';
    // clang-format on
    printResult(z);

    return 0;
}
