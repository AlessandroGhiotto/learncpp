#include <iostream>

int main()
{
    const int x { 5 };
    // int* ptr { &x }; // compile error: cannot convert from const int* to int*

    const int* ptr { &x }; // okay: ptr is pointing to a "const int"

    // *ptr = 6; // not allowed: we can't change a const value

    int y { 6 };
    ptr = &y; // okay: ptr now points at const int y

    int z { 9 };
    int* const ptr2 { &z }; // okay: the const pointer is initialized to the address of x
    // ptr2 = &y; // error: once initialized, a const pointer can not be changed.

    int value { 5 };
    const int* const ptr3 { &value }; // a const pointer to a const value

    std::cout << ptr << ": " << *ptr2 << "\n";
    std::cout << ptr << ": " << *ptr3 << "\n";
    return 0;
}
