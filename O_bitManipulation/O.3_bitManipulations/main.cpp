#include <cstdint>
#include <bitset>
#include <iostream>

int main0()
{
    // BIT MASKS (c++14)
    // before c++14 we needed to use like conversion from hexadecimal (there wasn't the 0b prefix)
    [[maybe_unused]] constexpr std::uint8_t mask0{0b0000'0001}; // represents bit 0
    [[maybe_unused]] constexpr std::uint8_t mask1{0b0000'0010}; // represents bit 1
    [[maybe_unused]] constexpr std::uint8_t mask2{0b0000'0100}; // represents bit 2
    [[maybe_unused]] constexpr std::uint8_t mask3{0b0000'1000}; // represents bit 3
    [[maybe_unused]] constexpr std::uint8_t mask4{0b0001'0000}; // represents bit 4
    [[maybe_unused]] constexpr std::uint8_t mask5{0b0010'0000}; // represents bit 5
    [[maybe_unused]] constexpr std::uint8_t mask6{0b0100'0000}; // represents bit 6
    [[maybe_unused]] constexpr std::uint8_t mask7{0b1000'0000}; // represents bit 7

    std::uint8_t flags{0b0000'0101}; // 8 bits in size means room for 8 flags

    // TESTING A BIT (<bool> AND)
    // op& with the correct mask let us see what bit is set on
    std::cout << "bit 0 is " << (static_cast<bool>(flags & mask0) ? "on\n" : "off\n");
    std::cout << "bit 1 is " << (static_cast<bool>(flags & mask1) ? "on\n" : "off\n");
    std::cout << "-----------------\n";

    // SETTING A BIT (OR)
    flags |= mask1; // turn on bit 1
    std::cout << "now we turn on bit 1:\n";
    std::cout << "bit 1 is " << (static_cast<bool>(flags & mask1) ? "on\n" : "off\n");
    std::cout << "-----------------\n";

    // RESETTING A BIT (AND ~)
    std::cout << "now we turn it off again:\n";
    // flags &= ~mask1; // turn off bit 1
    flags &= static_cast<std::uint8_t>(~mask1); // we need this because ~mask upgrade the mask to an integer
    std::cout << "bit 1 is " << (static_cast<bool>(flags & mask1) ? "on\n" : "off\n");
    std::cout << "-----------------\n";

    // FLIPPING A BIT (XOR)
    std::cout << "bit 2 is " << (static_cast<bool>(flags & mask2) ? "on\n" : "off\n");
    flags ^= mask2; // flip bit 2
    std::cout << "bit 2 is " << (static_cast<bool>(flags & mask2) ? "on\n" : "off\n");
    flags ^= mask2; // flip bit 2
    std::cout << "bit 2 is " << (static_cast<bool>(flags & mask2) ? "on\n" : "off\n");
    std::cout << "-----------------\n";

    return 0;
}

// EVERYTHING WORKS ALSO WITH BITSET TYPES
int main1()
{
    [[maybe_unused]] constexpr std::bitset<8> mask0{0b0000'0001}; // represents bit 0
    [[maybe_unused]] constexpr std::bitset<8> mask1{0b0000'0010}; // represents bit 1
    [[maybe_unused]] constexpr std::bitset<8> mask2{0b0000'0100}; // represents bit 2
    [[maybe_unused]] constexpr std::bitset<8> mask3{0b0000'1000}; // represents bit 3
    [[maybe_unused]] constexpr std::bitset<8> mask4{0b0001'0000}; // represents bit 4
    [[maybe_unused]] constexpr std::bitset<8> mask5{0b0010'0000}; // represents bit 5
    [[maybe_unused]] constexpr std::bitset<8> mask6{0b0100'0000}; // represents bit 6
    [[maybe_unused]] constexpr std::bitset<8> mask7{0b1000'0000}; // represents bit 7

    std::bitset<8> flags{0b0000'0101}; // 8 bits in size means room for 8 flags
    std::cout << "bit 1 is " << (flags.test(1) ? "on\n" : "off\n");
    std::cout << "bit 2 is " << (flags.test(2) ? "on\n" : "off\n");

    flags ^= (mask1 | mask2); // flip bits 1 and 2
    std::cout << "bit 1 is " << (flags.test(1) ? "on\n" : "off\n");
    std::cout << "bit 2 is " << (flags.test(2) ? "on\n" : "off\n");

    flags |= (mask1 | mask2); // turn bits 1 and 2 on
    std::cout << "bit 1 is " << (flags.test(1) ? "on\n" : "off\n");
    std::cout << "bit 2 is " << (flags.test(2) ? "on\n" : "off\n");

    flags &= ~(mask1 | mask2); // turn bits 1 and 2 off
    std::cout << "bit 1 is " << (flags.test(1) ? "on\n" : "off\n");
    std::cout << "bit 2 is " << (flags.test(2) ? "on\n" : "off\n");

    return 0;
}

// names are nice to clarigy the meaning of the masks
int main()
{
    // Define a bunch of physical/emotional states
    [[maybe_unused]] constexpr std::bitset<8> isHungry{0b0000'0001};
    [[maybe_unused]] constexpr std::bitset<8> isSad{0b0000'0010};
    [[maybe_unused]] constexpr std::bitset<8> isMad{0b0000'0100};
    [[maybe_unused]] constexpr std::bitset<8> isHappy{0b0000'1000};
    [[maybe_unused]] constexpr std::bitset<8> isLaughing{0b0001'0000};
    [[maybe_unused]] constexpr std::bitset<8> isAsleep{0b0010'0000};
    [[maybe_unused]] constexpr std::bitset<8> isDead{0b0100'0000};
    [[maybe_unused]] constexpr std::bitset<8> isCrying{0b1000'0000};

    std::bitset<8> me{};          // all flags/options turned off to start
    me |= (isHappy | isLaughing); // I am happy and laughing
    me &= ~isLaughing;            // I am no longer laughing

    // Query a few states (we use the any() function to see if any bits remain set)
    std::cout << std::boolalpha; // print true or false instead of 1 or 0
    std::cout << "I am happy? " << (me & isHappy).any() << '\n';
    std::cout << "I am laughing? " << (me & isLaughing).any() << '\n';

    return 0;
}

/////////////////////////////////////////////////////////////////////////////////
// This functions use masks to extract the Red, Green, Blue, and Alpha from a color in hexadecimal
int main3()
{
    constexpr std::uint32_t redBits{0xFF000000};
    constexpr std::uint32_t greenBits{0x00FF0000};
    constexpr std::uint32_t blueBits{0x0000FF00};
    constexpr std::uint32_t alphaBits{0x000000FF};

    std::cout << "Enter a 32-bit RGBA color value in hexadecimal (e.g. FF7F3300): ";
    std::uint32_t pixel{};
    std::cin >> std::hex >> pixel; // std::hex allows us to read in a hex value

    // use Bitwise AND to isolate the pixels for our given color,
    // then right shift the value into the lower 8 bits
    const std::uint8_t red{static_cast<std::uint8_t>((pixel & redBits) >> 24)};
    const std::uint8_t green{static_cast<std::uint8_t>((pixel & greenBits) >> 16)};
    const std::uint8_t blue{static_cast<std::uint8_t>((pixel & blueBits) >> 8)};
    const std::uint8_t alpha{static_cast<std::uint8_t>(pixel & alphaBits)};

    std::cout << "Your color contains:\n";
    std::cout << std::hex; // print the following values in hex

    // reminder: std::uint8_t will likely print as a char
    // we static_cast to int to ensure it prints as an integer
    std::cout << static_cast<int>(red) << " red\n";
    std::cout << static_cast<int>(green) << " green\n";
    std::cout << static_cast<int>(blue) << " blue\n";
    std::cout << static_cast<int>(alpha) << " alpha\n";

    return 0;
}
