#include <iostream>

int main0()
{
    int x{5};    // normal integer variable
    int& ref{x}; // ref is now an alias for variable x

    std::cout << x << ref << '\n'; // print 55

    x = 6; // x now has value 6

    std::cout << x << ref << '\n'; // prints 66

    ref = 7; // the object being referenced (x) now has value 7

    std::cout << x << ref << '\n'; // prints 77

    return 0;
}

int main1()
{
    // int& invalidRef;   // error: references must be initialized

    int x{5};
    int& ref{x}; // okay: non-const lvalue reference bound to a modifiable lvalue

#if 0
    const int y{5};
    int& invalidRef{y}; // invalid: non-const lvalue reference can't bind to a
                        // non-modifiable lvalue
    int& invalidRef2{
        0}; // invalid: non-const lvalue reference can't bind to an rvalue
#endif
}

int main2()
{
    int x{5};
    int& ref{x}; // okay: referenced type (int) matches type of initializer

#if 0
    double d{6.0};
    int &invalidRef{d};     // invalid: conversion of double to int is narrowing conversion, disallowed by list initialization
    double &invalidRef2{x}; // invalid: non-const lvalue reference can't bind to rvalue (result of converting x to double)
#endif

    return 0;
}

int main3()
{
    int x{5};
    int y{6};

    int& ref{x}; // ref is now an alias for x

    ref = y; // assigns 6 (the value of y) to x (the object being referenced by
             // ref)
    // The above line does NOT change ref into a reference to variable y!

    std::cout << x << '\n'; // user is expecting this to print 5

    return 0;
}

int main4()
{
    int x{5};

    {
        int& ref{x};              // ref is a reference to x
        std::cout << ref << '\n'; // prints value of ref (5)
    } // ref is destroyed here -- x is unaware of this

    std::cout << x << '\n'; // prints value of x (5)

    return 0;
} // x destroyed here

/*
int var{};
int& ref1{ var };  // an lvalue reference bound to var
int& ref2{ ref1 }; // an lvalue reference bound to var
*/

int main5()
{
    int x{1};
    int& ref{x};

    std::cout << x << ref << '\n'; // 22

    int y{2};
    ref = y;
    y = 3;

    std::cout << x << ref << '\n'; // 33

    x = 4;

    std::cout << x << ref << '\n'; // 44

    return 0;
}
