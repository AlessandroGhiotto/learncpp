#include <iostream>

// Code blocks can be used to execute multiple statements conditionally
int main()
{ // start of outer block
    std::cout << "Enter an integer: ";
    int value{};
    std::cin >> value;

    if (value >= 0)
    { // start of nested block
        std::cout << value << " is a positive integer (or zero)\n";
        std::cout << "Double this number is " << value * 2 << '\n';
    } // end of nested block
    else
    { // start of another nested block
        std::cout << value << " is a negative integer\n";
        std::cout << "The positive of this number is " << -value << '\n';
    } // end of another nested block

    return 0;
} // end of outer block

// nesting level
int main1()
{ // block 1, nesting level 1
    std::cout << "Enter an integer: ";
    int value{};
    std::cin >> value;

    if (value > 0)
    { // block 2, nesting level 2
        if ((value % 2) == 0)
        { // block 3, nesting level 3
            std::cout << value << " is positive and even\n";
        }
        else
        { // block 4, also nesting level 3
            std::cout << value << " is positive and odd\n";
        }
    }

    return 0;
}
