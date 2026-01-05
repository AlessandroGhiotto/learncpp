#include <iostream>

class Base
{
  public:
    int m_id {};

    Base(int id = 0)
        : m_id { id }
    {
        std::cout << "Base\n";
    }

    int getId() const { return m_id; }
};

class Derived : public Base
{
  public:
    double m_cost {};

    Derived(double cost = 0.0)
        : m_cost { cost }
    {
        std::cout << "Derived\n";
    }

    double getCost() const { return m_cost; }
};

class A
{
  public:
    A()
    {
        std::cout << "A\n";
    }
};

class B : public A
{
  public:
    B()
    {
        std::cout << "B\n";
    }
};

class C : public B
{
  public:
    C()
    {
        std::cout << "C\n";
    }
};

int main()
{
    std::cout << "Instantiating Base\n";
    Base base;

    std::cout << "Instantiating Derived\n";
    Derived derived;

    std::cout << "Constructing A: \n";
    A a;

    std::cout << "Constructing B: \n";
    B b;

    std::cout << "Constructing C: \n";
    C c;

    return 0;
}
