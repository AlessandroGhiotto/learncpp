#include <iostream>

class Base
{
  protected:
    int m_value {};

  public:
    Base(int value)
        : m_value { value }
    {
    }

    void identify() const { std::cout << "I am a Base\n"; }
};

class Derived : public Base
{
  public:
    Derived(int value)
        : Base { value }
    {
    }

    int getValue() const { return m_value; }
};

int main()
{
    Base b { 7 };
    // std::cout << b.getValue() << std::endl; // NOT IN BASE

    Derived d { 10 };
    std::cout << d.getValue() << std::endl;
}
