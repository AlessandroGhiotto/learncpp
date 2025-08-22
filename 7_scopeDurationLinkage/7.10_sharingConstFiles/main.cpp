// METHOD 1
#include "constants1.h" // include a copy of each constant in this file

// METHOD 2
#include "constants2.h" // include a copy of all the forward declarations for each constants

// METHOD 3
#include "constants3.h" // inlude copy of constants, but this time they are INLINE

#include <iostream>

int main()
{
    std::cout << "Enter a radius: ";
    double radius{};
    std::cin >> radius;

    std::cout << "The circumference is: " << 2 * radius * constants1::pi << '\n';

    std::cout << "The circumference is: " << 2 * radius * constants2::pi << '\n';

    std::cout << "The circumference is: " << 2 * radius * constants3::pi << '\n';

    return 0;
}
