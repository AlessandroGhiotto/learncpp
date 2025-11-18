#include <iostream>

void sayHi() // this function has external linkage, and can be seen by other files
{
    std::cout << "Hi!\n";
}

// global variable definitions
int g_z{7};              // non-constant globals have external linkage by default
extern const int g_w{8}; // this extern gives g_y external linkage
