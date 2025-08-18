#include <iostream>

// object-like macros with substitution text
#define MY_NAME "AleGhi8"

int main0()
{
    std::cout << "My name is: " << MY_NAME << '\n';

    return 0;
}

//////////////////////////////////////////////
// Conditional compilation
#define PRINT_JOE

int main1()
{
#ifdef PRINT_JOE
    std::cout << "Joe\n"; // will be compiled since PRINT_JOE is defined
#endif

#ifdef PRINT_BOB
    std::cout << "Bob\n"; // will be excluded since PRINT_BOB is not defined
#endif

#ifndef PRINT_BOB
    std::cout << "Not Bob\n"; // will be compiled since PRINT_BOB is NOT defined
#endif

    return 0;
}

///////////////////////////////
// #if 0

int main2()
{
    std::cout << "Joe\n";

#if 0  // Don't compile anything starting here
    std::cout << "Bob\n";
    /* Some
     * multi-line
     * comment here
     */
    std::cout << "Steve\n";
#endif // until this point

    return 0;
}

//////////////////////////////////////
// we can import them
#include "Ale.h" // copies #define MY_NAME_2 from Ale.h here

int main()
{
    std::cout << "My name is: " << MY_NAME_2 << '\n'; // preprocessor replaces MY_NAME_2 with "AleGhi"

    return 0;
}
