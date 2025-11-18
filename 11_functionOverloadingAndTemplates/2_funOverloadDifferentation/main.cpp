#include <iostream>

int add(int x, int y) // integer version
{
    return x + y;
}

// overloading based on diff #parameters
int add(int x, int y, int z) // 3 operands version
{
    return x + y + z;
}

// overloading based on diff type of parameters
double add(double x, double y) // floating point version
{
    return x + y;
}
// also the following works:
// double add(int x, double y); // mixed version
// double add(double x, int y); // mixed version

/// THE FOLLOWING DOESNT WORK (aliases and const)
#if 0
typedef int Height; // typedef
using Age = int;    // type alias

void print(int value);
void print(Age value);    // not differentiated from print(int)
void print(Height value); // not differentiated from print(int)
void print(const int);    // not differentiated from print(int)

// different return type doens't differentiate them
int getRandomValue();
double getRandomValue();
#endif

int main()
{
    std::cout << "add(3, 5) = " << add(3, 5) << "\n";         // call to integer version
    std::cout << "add(1, 2, 3) = " << add(1, 2, 3) << "\n";   // call to 3-vals version
    std::cout << "add(2.5, 3.3) = " << add(2.5, 3.3) << "\n"; // call to floating point version
}
