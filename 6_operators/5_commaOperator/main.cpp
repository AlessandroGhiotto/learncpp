#include <iostream>

int main()
{
    int x{1};
    int y{2};

    // comma operator:
    // x,y => evaluate x, then evaluate y, and return the result of the right operand
    std::cout << (++x, ++y) << '\n'; // increment x and y, evaluates to the right operand
    std::cout << x << ' ' << y << '\n';

// Which is equal to the following
#if 0
    ++x;
    std::cout << ++y << '\n';
#endif

    return 0;
}
