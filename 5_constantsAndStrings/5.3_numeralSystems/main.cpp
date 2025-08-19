#include <bitset> // for std::bitset
#include <iostream>

int main()
{
    int x1{25}; // decimal
    std::cout << x1 << '\n';

    int x2{012}; // 0 before the number means this is octal
    std::cout << x2 << '\n';

    int x3{0xF}; // 0x before the number means this is hexadecimal
    std::cout << x3 << '\n';

    int bin{};        // assume 16-bit ints
    bin = 0b1;        // assign binary 0000 0000 0000 0001 to the variable
    bin = 0b11;       // assign binary 0000 0000 0000 0011 to the variable
    bin = 0b1010;     // assign binary 0000 0000 0000 1010 to the variable
    bin = 0b11110000; // assign binary 0000 0000 1111 0000 to the variable
    std::cout << bin << "\n\n";

    // digit separator
    // int bin {0b1011'0010};  // assign binary 1011 0010 to the variable

    // outputting in other systems
    int x{12};
    std::cout << x << '\n';             // decimal (by default)
    std::cout << std::hex << x << '\n'; // hexadecimal
    std::cout << x << '\n';             // now hexadecimal
    std::cout << std::oct << x << '\n'; // octal
    std::cout << std::dec << x << '\n'; // return to decimal
    std::cout << x << "\n\n";           // decimal

    // outputting binary
    // std::bitset<8> means we want to store 8 bits
    std::bitset<8> bin1{0b1100'0101}; // binary literal for binary 1100 0101
    std::bitset<8> bin2{0xC5};        // hexadecimal literal for binary 1100 0101
    std::cout << bin1 << '\n'
              << bin2 << '\n';
    std::cout << std::bitset<4>{0b1010} << '\n'; // create a temporary std::bitset and print it

    return 0;
}
