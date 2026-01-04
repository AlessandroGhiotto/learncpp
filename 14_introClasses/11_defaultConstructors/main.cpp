#include <iostream>

class Foo
{
  private:
    int m_x {};
    int m_y {};

  public:
    Foo() // default constructor
    {
        std::cout << "Foo constructed\n";
    }

    /// We can't have more than 1 default constructors
    // Foo(int x = 1, int y = 2) // default constructor
    //     : m_x { x }, m_y { y }
    // {
    //     std::cout << "Foo(" << m_x << ", " << m_y << ") constructed\n";
    // }

    Foo(int x, int y) // non-default constructor
        : m_x { x }, m_y { y }
    {
        std::cout << "Foo(" << m_x << ", " << m_y << ") constructed\n";
    }
};

class Goo
{
    int aaaaaaaa { 42 };

  public:
    Goo() = default;
    void printaaaaaaaa() { std::cout << aaaaaaaa << std::endl; }
};

class Fraction
{
  private:
    int m_n { 0 };
    int m_d { 1 };

  public:
    Fraction() = default;
    Fraction(int n, int d)
        : m_n { n }, m_d { d }
    {
    }
    void print() const { std::cout << m_n << "/" << m_d << std::endl; }
};

class Employee
{
  private:
    std::string m_name {};
    int m_id {};

  public:
    Employee(std::string_view name, int id)
        : m_name { name }, m_id { id }
    {
    }

    void print() const
    {
        std::cout << "Employee(" << m_name << ", " << m_id << ")\n";
    }
};

int main()
{
    Foo foo1 {};       // Calls Foo() constructor
    Foo foo2 { 6, 7 }; // Calls Foo(int, int) constructor

    Goo goose {};
    goose.printaaaaaaaa();

    Fraction f1 {};
    Fraction f2 { 2, 3 };
    f1.print();
    f2.print();

    Employee e1 { "Joe", 1 };
    e1.print();
    // Employee e2 {}; // compile error: no matching constructor
    // e2.print();
    return 0;
}
