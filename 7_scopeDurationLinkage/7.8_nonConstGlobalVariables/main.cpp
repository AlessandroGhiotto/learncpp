#include <iostream>

int g_mode; // declare global variable (will be zero-initialized by default)

void doSomething()
{
    g_mode = 2; // set the global g_mode variable to 2
}

int main0()
{
    g_mode = 1; // note: this sets the global g_mode variable to 1.  It does not declare a local g_mode variable!

    doSomething();

    // Programmer still expects g_mode to be 1
    // But doSomething changed it to 2!

    if (g_mode == 1)
        std::cout << "No threat detected.\n";
    else
        std::cout << "Launching nuclear missiles...\n";

    return 0;
}

///////////////////////////////////77
int initX(); // forward declaration
int initY(); // forward declaration

int g_x{initX()}; // g_x is initialized first
int g_y{initY()};

int initX()
{
    return g_y; // g_y isn't initialized when this is called
}

int initY()
{
    return 5;
}

int main()
{
    std::cout << g_x << ' ' << g_y << '\n';
}

//////////////////////////////////////////////////
// if you want to use global variables, here some best practices
namespace constants
{
    constexpr double gravity{9.8}; // will not collide with other global variables named gravity
}
// constexpr double g_gravity{9.8}; // in alternative

double getGravity(); // forward declaration

// This function can calculate the instant velocity for any gravity value (more useful)
double instantVelocity(int time, double gravity)
{
    // instead of constants::gravity * time
    return gravity * time;
}

int main()
{
    std::cout << constants::gravity << '\n'; // clear this is a global variable (since namespaces are global)

    std::cout << getGravity() << '\n';

    std::cout << instantVelocity(5, constants::gravity) << '\n'; // pass our constant to the function as a parameter

    return 0;
}
