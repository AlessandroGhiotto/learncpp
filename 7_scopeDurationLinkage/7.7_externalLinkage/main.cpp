#include <iostream>

void sayHi(); // forward declaration for function sayHi, makes sayHi accessible in this file

int g_x{2};              // non-constant globals are external by default (no need to use extern)
extern const int g_y{3}; // const globals can be defined as extern, making them external
// extern constexpr int g_z{3}; // constexpr globals can be defined as extern, making them external (but this is pretty useless, see the warning in the next section)

extern int g_z;       // this extern is a forward declaration of a variable named g_x that is defined somewhere else
extern const int g_w; // this extern is a forward declaration of a const variable named g_y that is defined somewhere else

int main()
{
    sayHi(); // call to function defined in another file, linker will connect this call to the function definition

    std::cout << g_x << " " << g_y << '\n';

    std::cout << g_z << " " << g_w << '\n';

    return 0;
}

// int g_x { 1 };        // extern by default
// extern int g_x { 1 }; // explicitly extern (may cause compiler warning) [BAD]
// use EXTERN only for defining const global variables or for forward declarations
