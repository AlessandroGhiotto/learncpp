#include <iostream>

struct Employee
{
    int id {};
    int age {};
    double wage {};
};

void printEmployee(const Employee& e)
{
    // Use member selection operator (.) to select member from reference to struct
    std::cout << "Id: " << e.id << '\n';
    std::cout << "Age: " << e.age << '\n';
    std::cout << "Wage: " << e.wage << '\n';
}

int main()
{
    Employee joe { 1, 34, 65000.0 };

    ++joe.age;
    joe.wage = 68000.0;

    printEmployee(joe);

    Employee* ptr { &joe };
    // std::cout << "joe.wage: " << (*ptr).wage << std::endl;
    // equivalent to
    std::cout << "joe.wage: " << ptr->wage << std::endl;

    return 0;
}
