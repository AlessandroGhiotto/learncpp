#include <iostream>

void print1(int x, int y = 10) // 10 is the default argument
{
    std::cout << "x: " << x << '\n';
    std::cout << "y: " << y << '\n';
}
int main1()
{
    print1(1, 2); // y will use user-supplied argument 2
    print1(3);    // y will use default argument 4, as if we had called print(3, 4)
    return 0;
}

/// THE ARGUMENTS ARE PROVIDED FROM LEFT TO RIGHT (AND CAN'T BE SKIPPED)
void print2(std::string_view sv = "Hello", double d = 10.0)
{
    std::cout << "Values: " << sv << " " << d << '\n';
}
int main2()
{
    print2();           // okay: both arguments defaulted
    print2("Macaroni"); // okay: d defaults to 10.0
    // print3(20.0);       // error: does not match above function (cannot skip argument for sv)

    return 0;
}

/// DEFAULT ARGUMENTS CAN'T BE REDECLARED
#if 0
void print(int x, int y=4); // forward declaration
void print(int x, int y=4) // compile error: redefinition of default argument
{
    std::cout << "x: " << x << '\n';
    std::cout << "y: " << y << '\n';
}
#endif

// we just need to put them once
// usually is better in the forward declaration, since that is what is going
// to be included in other files (like importing a header file)
#include "foo.h"
void printFOO(int x, int y)
{
    std::cout << "x: " << x << '\n';
    std::cout << "y: " << y << '\n';
}
int main()
{
    printFOO(5);

    return 0;
}

/// ALSO OVERLOADED FUN CAN HAVE DEFAULT VALUES:
#if 0
void print(int x);                  // signature print(int)
void print(int x, int y = 10);      // signature print(int, int)
void print(int x, double y = 20.5); // signature print(int, double)

// defualt args can lead to ambiguous function calls:
int main()
{
    print(1, 2);   // will resolve to print(int, int)
    print(1, 2.5); // will resolve to print(int, double)
    print(1);      // ambiguous function call

    return 0;
}
#endif
