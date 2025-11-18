#include <iostream>

struct Employee
{
    int id {};
    int age {};
    double wage { 76000.0 };
    double whatever { 0.0 }; // ADDED DEFAULT 0.0 so I don't get the warning
};

std::ostream &operator<<(std::ostream &out, Employee e)
{
    out << "id: " << e.id << " age: " << e.age << " wage: " << e.wage << " whatever: " << e.whatever << std::endl;
    return out;
}

int main()
{
    Employee joe { 2, 28 }; // joe.whatever will be value-initialized to 0.0

    std::cout << joe;
    joe = { joe.id, 33, 66000.0 }; // Joe had a birthday and got a raise

    [[maybe_unused]] const Employee constance { 3, 32 };

    // designated initializers:
    [[maybe_unused]] Employee bob { .id = 55, .age = 55, .whatever = 3.3 };
    return 0;
}
