// Forward declaration = functionHeader;
// make the compiler know how the function looks like (input an output)
#include <iostream>

int add(int x, int y); // forward declaration of add() (using a function declaration)

int main0()
{
    std::cout << "The sum of 3 and 4 is: " << add(3, 4) << '\n'; // this works because we forward declared add() above
    return 0;
}

int add(int x, int y) // even though the body of add() isn't defined until here
{
    return x + y;
}

/////////////////////////////////
// ORD

int add(int x, int y)
{
    return x + y;
}

// int add(int x, int y) // violation of ODR, we've already defined function add(int, int)
// {
//     return x + y;
// }

int main()
{
    int x{};
    // int x{5}; // violation of ODR, we've already defined x
}
