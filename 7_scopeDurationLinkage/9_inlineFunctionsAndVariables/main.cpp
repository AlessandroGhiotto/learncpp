#include "pi.h" // will include a copy of pi() here
#include <iostream>

int min(int x, int y)
{
    return (x < y) ? x : y;
}

double circumference(double radius); // forward declaration

int main()
{
    std::cout << min(5, 6) << '\n';
    std::cout << min(3, 2) << '\n';
    // vs
    // std::cout << ((5 < 6) ? 5 : 6) << '\n';
    // std::cout << ((3 < 2) ? 3 : 2) << '\n';

    //
    std::cout << pi() << '\n';
    std::cout << circumference(2.0) << '\n';

    return 0;
}
