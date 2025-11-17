#include <iostream>

void printIDNumber(const int* id = nullptr)
{
    if (id)
        std::cout << "Your ID number is " << *id << ".\n";
    else
        std::cout << "Your ID number is not known.\n";
}
// BETTER VERSION:
/*
void printIDNumber()
{
    std::cout << "Your ID is not known\n";
}
void printIDNumber(int id)
{
    std::cout << "Your ID is " << id << "\n";
}
*/

void nullify([[maybe_unused]] int* ptr2)
{
    ptr2 = nullptr; // Make the function parameter a null pointer
}

void nullifyRef(int*& refptr) // refptr is now a reference to a pointer
{
    refptr = nullptr; // Make the function parameter a null pointer
}

int main()
{
    printIDNumber(); // we don't know the user's ID yet
    int userid { 34 };
    printIDNumber(&userid); // we know the user's ID now

    int x { 5 };
    int* ptr { &x }; // ptr points to x
    std::cout << "ptr is " << (ptr ? "non-null\n" : "null\n");
    nullify(ptr);
    std::cout << "ptr is " << (ptr ? "non-null\n" : "null\n");
    nullifyRef(ptr);
    std::cout << "ptr is " << (ptr ? "non-null\n" : "null\n");
    return 0;
}
