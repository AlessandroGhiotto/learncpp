#include <iostream>

void doSomething()
{
    std::cout << "Hello!\n";
}

int main()
{
    int x{0}; // x's lifetime begins here

    doSomething(); // x is still alive during this function call

    return 0;
} // x's lifetime ends here

////////////////////////////////////////////////
// in/out scope
// x is not in scope anywhere in this function
void doSomething()
{
    std::cout << "Hello!\n";
}

int main()
{
    // x can not be used here because it's not in scope yet
    int x{0}; // x enters scope here and can now be used within this function
    doSomething();

    return 0;
} // x goes out of scope here and can no longer be used

////////////////////////////////
int add(int x, int y) // add's x and y are created and enter scope here
{
    // add's x and y are visible/usable within this function only
    return x + y;
} // add's y and x go out of scope and are destroyed here

int main()
{
    int x{5}; // main's x is created, initialized, and enters scope here
    int y{6}; // main's y is created, initialized, and enters scope here

    // main's x and y are usable within this function only
    std::cout << add(x, y) << '\n'; // calls function add() with x=5 and y=6

    return 0;
} // main's y and x go out of scope and are destroyed here
