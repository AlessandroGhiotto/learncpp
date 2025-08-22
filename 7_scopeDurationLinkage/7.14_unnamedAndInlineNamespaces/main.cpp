#include <iostream>

namespace // unnamed namespace
{
    void doSomething() // can only be accessed in this file
    {
        std::cout << "UNNAMED\n";
    }
}
// This is the same
// static void doSomething() // can only be accessed in this file
// {
//     std::cout << "v1\n";
// }

namespace V1 // declare a normal namespace named V1
{
    void printSomething()
    {
        std::cout << "NOT INLINE V1\n";
    }
}

inline namespace V2 // declare an inline namespace named V2
{
    namespace // unnamed namespace
    {
        void printSomething() // has internal linkage
        {
            std::cout << "INLINE V2\n";
        }

    }
}

int main()
{
    doSomething(); // we can call doSomething() without a namespace prefix

    V1::printSomething(); // calls the V1 version of printSomething()
    V2::printSomething(); // calls the V2 version of printSomething()
    printSomething();     // calls the inline version of printSomething() (which is V2)

    return 0;
}
