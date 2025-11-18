#include <iostream>

// Definition of user-defined function doPrint()
void doPrint()
{
    std::cout << "In doPrint()\n";
}

// Definition of user-defined function main()
int main0()
{
    std::cout << "Starting main()\n";
    doPrint();                      // Interrupt main() by making a function call to doPrint().  main() is the caller.
    std::cout << "Ending main()\n"; // This statement is executed after doPrint() ends

    return 0;
}

// functions can be called more than once
int main1()
{
    std::cout << "Starting main()\n";
    doPrint();
    doPrint();
    doPrint();
    std::cout << "Ending main()\n";

    return 0;
}

//////////////////////////////////////
// functions can call other functions
void doB()
{
    std::cout << "Doing B\n";
}
void doA()
{
    std::cout << "Start A\n";
    doB();
    std::cout << "End A\n";
}
int main()
{
    std::cout << "Start main\n";
    doA();
    std::cout << "End main\n";

    return 0;
}

//////////////////////////////////////
// functions can't be nested
// int main()
// {
//     void foo() // Illegal: this function is nested inside function main()
//     {
//         std::cout << "foo!\n";
//     }

//     foo();

//     return 0;
// }
