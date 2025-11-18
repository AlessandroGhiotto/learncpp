#include <iostream>

static int g_x{}; // non-constant globals have external linkage by default, but can be given internal linkage via the static keyword

const int g_y{1};     // const globals have internal linkage by default
constexpr int g_z{2}; // constexpr globals have internal linkage by default

// this separate internal g_var is only accessible within main.cpp
// we are not going to get any errors for overlap with g_var in a.cpp
// main.cpp have no idea that exists a g_var in a.cpp (because they have internal linkage)
static int g_var{3};

// forward declaration for function add
// we are not going to link any function, since add has internal linkage
int add(int x, int y);

int main()
{
    std::cout << g_x << ' ' << g_y << ' ' << g_z << '\n';

    std::cout << g_var << '\n'; // uses main.cpp's g_x, prints 3

    // std::cout << add(3, 4) << '\n'; // undefined reference to `add(int, int)'

    return 0;
}
