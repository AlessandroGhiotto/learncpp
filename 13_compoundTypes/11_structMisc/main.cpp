#include <iostream>
#include <string>
#include <string_view>

struct Company
{
    // If we want Employee to make sense only inside Company
    struct Employee // accessed via Company::Employee
    {
        int id {};
        int age {};
        double wage {};
    };

    int numberOfEmployees {};
    Employee CEO {}; // Employee is a struct within the Company struct
};

int main()
{
    Company myCompany { 7, { 1, 32, 55000.0 } }; // Nested initialization list to initialize Employee
    std::cout << myCompany.CEO.wage << '\n';     // print the CEO's wage

    return 0;
}

///////////////////////////////////////////////////////
// we want our structs to be owners
// we get it if all the members are also owners
struct Owner
{
    std::string name {}; // std::string is an owner
};

struct Viewer
{
    std::string_view name {}; // std::string_view is a viewer
};

// getName() returns the user-entered string as a temporary std::string
// This temporary std::string will be destroyed at the end of the full expression
// containing the function call.
std::string getName()
{
    std::cout << "Enter a name: ";
    std::string name {};
    std::cin >> name;
    return name;
}

int main()
{
    Owner o { getName() };                                // The return value of getName() is destroyed just after initialization
    std::cout << "The owners name is " << o.name << '\n'; // ok

    Viewer v { getName() };                                // The return value of getName() is destroyed just after initialization
    std::cout << "The viewers name is " << v.name << '\n'; // undefined behavior

    return 0;
}
