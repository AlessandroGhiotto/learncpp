#include <iostream>

class Base
{
  public:
    Base() {}

    void identify() const { std::cout << "Base::identify()\n"; }
};

class Derived1 : public Base
{
  public:
    Derived1() {}
};

class Derived2 : public Base
{
  public:
    Derived2() {}

    void identify() const { std::cout << "Derived2::identify()\n"; }
};

class Derived3 : public Base
{
  public:
    Derived3() {}

    void identify() const
    {
        std::cout << "Derived::identify()\n  L-- ";
        Base::identify(); // note call to Base::identify() here
    }
};

//
class BaseNew
{
  public:
    void print(int) { std::cout << "BaseNew::print(int)\n"; }
    void print(double) { std::cout << "BaseNew::print(double)\n"; }
};

class DerivedNew : public BaseNew
{
  public:
    using BaseNew::print; // make all BaseNew::print() functions eligible for overload resolution
    void print(double) { std::cout << "DerivedNew::print(double)"; }
};

int main()
{
    Base base {};
    base.identify();

    Derived1 derived1 {};
    derived1.identify();

    Derived2 derived2 {};
    derived2.identify();

    Derived3 derived3 {};
    derived3.identify();

    DerivedNew d {};
    d.print(5); // calls Base::print(int), which is the best matching function visible in Derived

    return 0;
}
