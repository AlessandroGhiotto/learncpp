#include <iostream>
#include <string>

class Employee
{
  private:
    std::string m_name {};
    std::string m_surname {};

  public:
    void setName(std::string_view name) { m_name = name; }
    void setSurname(std::string_view surname) { m_surname = surname; }

    const std::string& getName() const { return m_name; } // getters return by const lvalue reference
    std::string& getSurname() { return m_surname; }       // getters return by NON const lvalue reference
};

// createEmployee() returns an Employee by value (which means the returned value is an rvalue)
Employee createEmployee(std::string_view name)
{
    Employee e;
    e.setName(name);
    return e;
}

int main()
{
    Employee joe;
    joe.setName("joe");
    std::cout << joe.getName() << std::endl;

    joe.setSurname("Doe");
    std::cout << joe.getSurname() << std::endl;

    // I MODIFY THE PRIVATE MEMBER
    // via a non-const reference to the private member
    auto& s = joe.getSurname();
    s = "biden";

    std::cout << joe.getSurname() << std::endl;

    // R VALUES
    // Case 1: okay: use returned reference to member of rvalue class object in same expression
    std::cout << createEmployee("Frank").getName();

    // Case 2: bad: save returned reference to member of rvalue class object for use later
    const std::string& ref { createEmployee("Garbo").getName() }; // reference becomes dangling when return value of createEmployee() is destroyed
    std::cout << ref;                                             // undefined behavior

    // Case 3: okay: copy referenced value to local variable for use later
    std::string val { createEmployee("Hans").getName() }; // makes copy of referenced member
    std::cout << val;                                     // okay: val is independent of referenced member
    return 0;
}
