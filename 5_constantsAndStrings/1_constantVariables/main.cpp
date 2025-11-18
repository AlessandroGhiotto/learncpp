#include <iostream>
#define GRAVITY "SIUUUUUUMMMMMMMMMM\n"

int main()
{
    const double gravity{9.8}; // preferred use of const before type
    std::cout << gravity << "\n";
#if 0
    const double c;            // error: const variables must be initialized
    gravity = 9.9;             // error: const variables can not be changed
#endif

    int age{18};
    const int constAge{age}; // initialize const variable using non-const value
    age = 5;                 // ok: age is non-const, so we can change its value
    // constAge = 6; // error: constAge is const, so we cannot change its value
    std::cout << constAge << "\n";

    // avoid macros!! (strange, no scope, not like c++, direct substitutions - not seen by debugger)
    std::cout << GRAVITY;
    return 0;
}
