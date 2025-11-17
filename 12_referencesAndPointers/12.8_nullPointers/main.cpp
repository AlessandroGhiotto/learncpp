#include <iostream>

int main()
{
    int* ptr {}; // ptr is a null pointer, and is not holding an address

    int x { 5 };
    ptr = &x; // ptr now pointing at object x (no longer a null pointer)

    std::cout << *ptr << '\n'; // print value of x through dereferenced ptr

    // int* ptr { nullptr }; // can use nullptr to initialize a pointer to be a null pointer

    int value { 5 };
    int* ptr2 { &value }; // ptr2 is a valid pointer
    ptr2 = nullptr; // Can assign nullptr to make the pointer a null pointer

    // someFunction(nullptr); // we can also pass nullptr to a function that has a pointer parameter

    // if (ptr2 == nullptr) // explicit test for equivalence
    if (ptr2) // implicit conversion to Boolean
        std::cout << "ptr is null\n";
    else
        std::cout << "ptr is non-null\n";

    return 0;
}
