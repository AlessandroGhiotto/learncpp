#include <iostream>

void printHi()
{
    std::cout << "Hi!\n";
    // does not return a value
}

int main0()
{
    printHi();

    return 0;
}

////////////////////////////////////
#include <iostream>

// a void func
void returnNothing()
{
}

// a value-returningn func
int returnFive()
{
    return 5;
}

int main()
{
    // calling a function by itself, no value is required
    returnNothing();
    returnFive(); // return value is ignored

    // calling a function in a context that requires a value (like std::cout)
    std::cout << returnFive(); // we can use a function that returns a value
    // std::cout << returnNothing(); // compile error

    return 0;
}

////////////////////////////////
// returning something in a void function gives an error
// void printHi()
// {
//     std::cout << "In printHi()" << '\n';

//     return 5;
// }
