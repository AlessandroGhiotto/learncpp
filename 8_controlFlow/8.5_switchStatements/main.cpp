#include <iostream>

void printDigitName(int x)
{
#if 0
    if (x == 1)
        std::cout << "One";
    else if (x == 2)
        std::cout << "Two";
    else if (x == 3)
        std::cout << "Three";
    else
        std::cout << "Unknown";
#endif
    switch (x)
    {
    case 1:
        std::cout << "One";
        return;
    case 2:
        std::cout << "Two";
        return;
    case 3:
        std::cout << "Three";
        return;
    default:
        std::cout << "Unknown";
        return;
    }

#if 0
// SAME but with "break" instead of "return"
    switch (x)
    {
    case 1:
        std::cout << "One";
        break;
    case 2:
        std::cout << "Two";
        break;
    case 3:
        std::cout << "Three";
        break;
    default:
        std::cout << "Unknown";
        break;
    }
#endif

    // execution continues here
    std::cout << " Ah-Ah-Ah!";
}

int main()
{
    printDigitName(2);
    std::cout << '\n';
    printDigitName(3);
    std::cout << '\n';
    printDigitName(4);
    std::cout << '\n';

    return 0;
}
