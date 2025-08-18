#include <iostream>

int main0()
{
    int x{8};

    std::cout << "hello World";
    std::cout << x;
    std::cout << "\n"
              << "aahahaha" << x;

    return 0;
}

int main1()
{
    std::cout << "Hi!" << std::endl;
    std::cout << "My name is aleghi8!" << std::endl;
    // we put endl also here os is more clear that the line output is complete
    return 0;
}

// \n special char
int main2()
{
    int x{5};
    std::cout << "x is equal to: " << x << '\n'; // single quoted (by itself) (conventional)
    std::cout << "Yep." << "\n";                 // double quoted (by itself) (unconventional but okay)
    std::cout << "And that's all, folks!\n";     // between double quotes in existing text (conventional)
    return 0;
}

// cin
int main3()
{
    std::cout << "Enter a number: ";

    int x{};
    std::cin >> x;

    std::cout << "You entered " << x << "\n";

    return 0;
}

// cin with more values
int main4()
{
    std::cout << "Enter 2 numbers separated with a whitespcae: ";

    int x{}, y{};
    std::cin >> x >> y;

    std::cout << "You entered " << x << " and " << y << "\n";

    return 0;
}

// cin is buffered
// try to input "4 5" in the first input
int main5()
{
    std::cout << "Enter two numbers: ";

    int x{};
    std::cin >> x;

    int y{};
    std::cin >> y;

    std::cout << "You entered " << x << " and " << y << '\n';

    return 0;
}

// question
// Ask the user to enter three values. The program should then print these values. Add an appropriate comment above function main().

// The program should match the following output (when run with input values 4, 5, and 6):

// Enter three numbers: 4 5 6
// You entered 4, 5, and 6.
int main()
{
    std::cout << "Enter three numbers: ";

    int x{}, y{}, z{};
    std::cin >> x >> y >> z;
    std::cout << "You entered " << x << ", " << y << ", and " << z << ".\n4";

    return 0;
}
