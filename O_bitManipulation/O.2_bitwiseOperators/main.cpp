#include <bitset>
#include <iostream>
#include <cstdint>

// BIT SHIFT >>, <<
int main0()
{
    std::bitset<4> x{0b1100};

    std::cout << x << '\n';
    std::cout << (x >> 1) << '\n'; // shift right by 1, yielding 0110
    std::cout << (x << 1) << '\n'; // shift left by 1, yielding 1000

    return 0;
}

// BITWISE NOTE - we get different results demìpending on the number of bits
// (when the bits are interpreted as integers)
int main1()
{
    std::bitset<4> b4{0b100}; // b4 is 0100
    std::bitset<8> b8{0b100}; // b8 is 0000 0100

    std::cout << "Initial values:\n";
    std::cout << "Bits: " << b4 << ' ' << b8 << '\n';
    std::cout << "Values: " << b4.to_ulong() << ' ' << b8.to_ulong() << "\n\n";

    b4 = ~b4; // flip b4 to 1011
    b8 = ~b8; // flip b8 to 1111 1011

    std::cout << "After bitwise NOT:\n";
    std::cout << "Bits: " << b4 << ' ' << b8 << '\n';
    std::cout << "Values: " << b4.to_ulong() << ' ' << b8.to_ulong() << '\n';

    return 0;
}

// OR AND XOR
int main2()
{
    std::cout << (std::bitset<4>{0b0101} | std::bitset<4>{0b0110}) << '\n';
    std::cout << (std::bitset<4>{0b0111} | std::bitset<4>{0b0011} | std::bitset<4>{0b0001}) << '\n';
    std::cout << (std::bitset<4>{0b0001} & std::bitset<4>{0b0011} & std::bitset<4>{0b0111}) << '\n';
    std::cout << (std::bitset<4>{0b0001} ^ std::bitset<4>{0b0011} ^ std::bitset<4>{0b0111}) << '\n';

    // bitwise assignment op >>=, <<=, &=, |=, ^=
    std::bitset<4> bits{0b0100};
    bits >>= 1;
    std::cout << bits << '\n';

    return 0;
}

// bitwise operator promote operands which are narrower than an int to an int (or unsigned int)
// I can get back the narrow vesion with static_cast
// be carefoul with op<< and op~ since are sidth-sensitive
int main3()
{
    std::uint8_t c{0b00001111};

#if 0
    std::cout << std::bitset<32>(~c) << '\n';     // incorrect: prints 11111111111111111111111111110000
    std::cout << std::bitset<32>(c << 6) << '\n'; // incorrect: prints 0000000000000000001111000000
    std::uint8_t cneg { ~c };                     // error: narrowing conversion from unsigned int to std::uint8_t
    c = ~c;                                       // possible warning: narrowing conversion from unsigned int to std::uint8_t
#endif

    std::cout << std::bitset<32>(static_cast<std::uint8_t>(~c)) << '\n';     // correct: prints 00000000000000000000000011110000
    std::cout << std::bitset<32>(static_cast<std::uint8_t>(c << 6)) << '\n'; // correct: prints 0000000000000000000011000000
    [[maybe_unused]] std::uint8_t cneg{static_cast<std::uint8_t>(~c)};       // compiles
    c = static_cast<std::uint8_t>(~c);                                       // no warning

    return 0;
}

///////////////////////////7
// EXERCISE: bitwise rotation

// "rotl" stands for "rotate left"
std::bitset<4> rotl(std::bitset<4> bits)
{
    // with TEST and SET
    // std::bitset<4> res{bits << 1};
    // if (bits.test(3))
    //     res.set(0);
    // return res

    // with bitwise operation
    std::bitset<4> remainder{bits >> 3};
    return (bits << 1) | remainder;
}

int main()
{
    std::bitset<4> bits1{0b0001};
    std::cout << rotl(bits1) << '\n';

    std::bitset<4> bits2{0b1001};
    std::cout << rotl(bits2) << '\n';

    return 0;
}
