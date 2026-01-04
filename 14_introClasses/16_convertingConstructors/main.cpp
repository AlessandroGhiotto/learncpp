#include <iostream>
#include <string>
#include <string_view>

class Employee
{
  private:
    std::string m_name {};

  public:
    Employee(std::string_view name)
        : m_name { name }
    {
    }

    const std::string& getName() const { return m_name; }
};

void printEmployee(Employee e) // has an Employee parameter
{
    std::cout << e.getName();
}

///
#include <iostream>

class Dollars
{
  private:
    int m_dollars {};

  public:
    explicit Dollars(int d) // now explicit
        : m_dollars { d }
    {
    }

    int getDollars() const { return m_dollars; }
};

void print(Dollars d)
{
    std::cout << "$" << d.getDollars();
}

int main()
{
    // we're supplying an string literal argument. this needs 2 implicit conversions
    // printEmployee("Joe");

    // we can just use this way, using implicit conversions is dangerours
    printEmployee(Employee { "Joe" });

    /// EXPLICIT
    // print(5); // compilation error because Dollars(int) is explicit
    Dollars d1(5);                  // ok
    Dollars d2 { 5 };               // ok
    print(Dollars { 5 });           // ok: explicitly create a Dollars
    print(static_cast<Dollars>(5)); // ok: static_cast will use explicit constructors

    return 0;
}
