#include <iostream>

constexpr double calcCircumference(double radius) // now a constexpr function
{
    constexpr double pi{3.14159265359};
    return 2.0 * pi * radius;
}

int main()
{
    constexpr double circumference{calcCircumference(3.0)}; // now compiles

    std::cout << "Our circle has circumference " << circumference << "\n";

    // constepr functions can be evaluated at run-time
    int rad{2};                                                                     // not a constexpr var
    std::cout << "Our circle has circumference " << calcCircumference(rad) << "\n"; // will be evaluated at runtime

    return 0;
}
