// Integrated debugger
// call stack ( in conjuction with breakpoints)
#include <iostream>

void a()
{
    std::cout << "a() called\n";
}

void b()
{
    std::cout << "b() called\n";
    a();
}

int main()
{
    a();
    b();

    return 0;
}
