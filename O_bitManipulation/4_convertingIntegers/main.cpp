#include <cstdint>
#include <bitset>
#include <iostream>

// EXERCISE
int modifyDigit(int n, int power2)
{
    if (n >= power2)
    {
        std::cout << 1;
        return n - power2;
    }
    std::cout << 0;
    return n;
}
void printBinary(int n)
{
    n = modifyDigit(n, 128);
    n = modifyDigit(n, 64);
    n = modifyDigit(n, 32);
    n = modifyDigit(n, 16);
    std::cout << " ";
    n = modifyDigit(n, 8);
    n = modifyDigit(n, 4);
    n = modifyDigit(n, 2);
    n = modifyDigit(n, 1);
    std::cout << '\n';
}
int main()
{
    int num{};
    std::cout << "Enter a number between 0 and 255: ";
    std::cin >> num;

    printBinary(num);
}

// with another method of integer to binary conversion:
#if 0
void printBit(int x, int pow)
{
    std::cout << ((x / pow) % 2);
}

void print8BitBinary(int x)
{
    printBit(x, 128);
    printBit(x, 64);
    printBit(x, 32);
    printBit(x, 16);

    std::cout << ' ';

    printBit(x, 8);
    printBit(x, 4);
    printBit(x, 2);
    printBit(x, 1);
}

int main()
{
    std::cout << "Enter an integer between 0 and 255: ";
    int x{};
    std::cin >> x;

    print8BitBinary(x);

    std::cout << '\n';

    return 0;
}
#endif
