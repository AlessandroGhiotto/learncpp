#include <iostream>

class Base
{
  private:
    int m_value_priv {};

  public:
    int m_value_pub { 4 };

    Base(int value)
        : m_value_priv { value }
    {
    }

  protected:
    void printValue() const { std::cout << m_value_priv; }
};

class Derived : public Base
{
  private:
    using Base::m_value_pub;

  public:
    Derived(int value)
        : Base { value }
    {
    }

    // Base::printValue was inherited as protected, so the public has no access
    // But we're changing it to public via a using declaration
    using Base::printValue; // note: no parenthesis here
};

int main()
{
    Derived derived { 7 };

    // printValue is public in Derived, so this is okay
    derived.printValue(); // prints 7

    // std::cout << derived.m_value_pub; // error: m_value_pub is private in Derived

    Base& base { derived };
    std::cout << base.m_value_pub; // okay: m_value_pub is public in Base

    return 0;
}
