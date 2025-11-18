#include <iostream>

// unsigned integers
unsigned short us;
unsigned int ui;
unsigned long ul;
unsigned long long ull;

int main0()
{
    unsigned short x{65535}; // largest 16-bit unsigned value possible
    std::cout << "x was: " << x << '\n';

    // x = 65536; with this line I get directly the warning from the compiler
    x = x + 1; // 65536 is out of our range, so we get modulo wrap-around
    std::cout << "x is now: " << x << '\n';

    // x = 65537; // 65537 is out of our range, so we get modulo wrap-around
    x = x + 1;
    std::cout << "x is now: " << x << "\n\n";

    // WRAP AROUND ON THE OTHER SIDE
    unsigned short y{0}; // smallest 2-byte unsigned value possible
    std::cout << "y was: " << y << '\n';

    y = y - 1; // -1 is out of our range, so we get modulo wrap-around
    std::cout << "y is now: " << y << '\n';

    y = y - 1; // -2 is out of our range, so we get modulo wrap-around
    std::cout << "y is now: " << y << '\n';

    return 0;
}

// WHY NOT USING THE UNSIGNED INTEGERS
int main()
{
    unsigned int x{2};
    unsigned int y{3};
    std::cout << x - y << '\n'; // prints 4294967295 (incorrect!)

#if 0
    unsigned int u{2};
    signed int s{3};
    std::cout << u - s << '\n'; // 2 - 3 = 4294967295 // WARNING

    signed int t{-1};
    unsigned int v{1};
    if (t < v) // WARNING -1 is implicitly converted to 4294967295, and 4294967295 < 1 is false
        std::cout << "-1 is less than 1\n";
    else
        std::cout << "1 is less than -1\n"; // this statement executes
#endif

    return 0;
}
