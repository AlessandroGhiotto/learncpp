#include <iostream>

// Variables declared outside of a function are global variables
int g_x{};            // global variable g_x
const int g_z{1};     // const global variable g_y, initialized with a value
constexpr int g_w{2}; // constexpr global variable g_z, initialized with a value

namespace Foo // Foo is defined in the global scope
{
    // g_y is now inside the Foo namespace, but is still a global variable
    // since it is globally accessible
    int g_y{};
}

void doSomething()
{
    // global variables can be seen and used everywhere in the file
    g_x = 3;
    Foo::g_y = 7;
    std::cout << g_x << " " << Foo::g_y << '\n';
}

int main()
{
    doSomething();
    std::cout << g_x << " " << Foo::g_y << '\n';

    // global variables can be seen and used everywhere in the file
    g_x = 5;
    Foo::g_y = 8;
    std::cout << g_x << " " << Foo::g_y << '\n';

    std::cout << g_z << '\n';
    std::cout << g_w << '\n';

    return 0;
}
// g_x goes out of scope here
