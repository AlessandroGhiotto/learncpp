#include <iostream> // imports the declaration of std::cout into the global scope

// All of the following statements are part of the global namespace

void foo(); // okay: function forward declaration
int x;      // compiles but strongly discouraged: non-const global variable definition (without initializer)
int y{5};   // compiles but strongly discouraged: non-const global variable definition (with initializer)
// x = 5;      // compile error: executable statements are not allowed in namespaces

int main() // okay: function definition
{
    return 0;
}

void goo(); // okay: A function forward declaration

///////////////////////////////////////////////////
void foo(int x) // foo is defined in the global scope, x is defined within scope of foo()
{               // braces used to delineate nested scope region for function foo()
    std::cout << x << '\n';
} // x goes out of scope here

int main()
{ // braces used to delineate nested scope region for function main()
    foo(5);

    int x{6}; // x is defined within the scope of main()
    std::cout << x << '\n';

    return 0;
} // x goes out of scope here
// foo and main (and std::cout) go out of scope here (the end of the file)
