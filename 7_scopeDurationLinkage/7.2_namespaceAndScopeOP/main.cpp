#include <iostream>
#include "add.h"    // for BasicMath::add()
#include "circle.h" // for BasicMath::pi
#include "growth.h" // for BasicMath::e

void print() // this print() lives in the global namespace
{
    std::cout << " there\n";
}

// We could also place this Foo and Goo namespaces in two other separated files
// (like foo.cpp and goo.cpp)
namespace Foo // define a namespace named Foo
{
    // This doSomething() belongs to namespace Foo
    int doSomething(int x, int y)
    {
        return x + y;
    }
    void print() // this print() lives in the Foo namespace
    {
        std::cout << "Hello";
    }
    void printHelloThere()
    {
        print();   // calls print() in Foo namespace
        ::print(); // calls print() in global namespace
    }
    namespace Goo // Goo is a namespace inside the Foo namespace
    {
        int add(int x, int y)
        {
            return x + y;
        }
    }

}
// THIS IS ANOTHER WAY FOR NESTED NAMESPACES
// namespace Foo::Goo // Goo is a namespace inside the Foo namespace (C++17 style)
// {
//     int add(int x, int y)
//     {
//         return x + y;
//     }
// }

namespace Goo // define a namespace named Goo
{
    // This doSomething() belongs to namespace Goo
    int doSomething(int x, int y)
    {
        return x - y;
    }
}

int main()
{
    std::cout << "Foo: " << Foo::doSomething(4, 3) << '\n'; // use the doSomething() that exists in namespace Foo
    std::cout << "Goo: " << Goo::doSomething(4, 3) << '\n'; // same for Goo
    Foo::printHelloThere();

    std::cout << "BasicMath: " << BasicMath::add(4, 3) << '\n';
    std::cout << "BasicMath::pi : " << BasicMath::pi << '\n';
    std::cout << "BasicMath::e  : " << BasicMath::e << '\n';

    std::cout << "Foo::Goo : " << Foo::Goo::add(1, 2) << '\n';
    namespace Active = Foo::Goo;                          // active now refers to Foo::Goo
    std::cout << "Active: " << Active::add(1, 2) << '\n'; // This is really Foo::Goo::add()

    return 0;
}
