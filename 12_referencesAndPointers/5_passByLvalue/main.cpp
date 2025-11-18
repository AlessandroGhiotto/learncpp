#include <iostream>
#include <string>

void printValue(std::string y)
{
    std::cout << y << '\n';
} // y is destroyed here

void printValueRef(std::string& y) // type changed to std::string&
{
    std::cout << y << '\n';
} // y is destroyed here

void printAddresses(int val, int& ref)
{
    std::cout << "The address of the value parameter is: " << &val << '\n';
    std::cout << "The address of the reference parameter is: " << &ref << '\n';
}

void addOne(int& z) // z is bound to the actual object y
{
    ++z; // this modifies the actual object y
}

int main()
{
    std::string x { "Hello, world!" }; // x is a std::string

    printValue(x); // x is passed by value (copied) into parameter y (expensive)
    printValueRef(x); // x is now passed by reference into reference parameter y (inexpensive)
    // const int z { 5 };
    // printValueRef(z); // error: z is a non-modifiable lvalue
    // printValueRef(5); // error: 5 is an rvalue

    int y { 5 };
    std::cout << "The address of y is: " << &y << '\n';
    printAddresses(y, y);

    std::cout << "value = " << y << '\n';
    addOne(y);
    std::cout << "value = " << y << '\n'; // x has been modified

    return 0;
}
