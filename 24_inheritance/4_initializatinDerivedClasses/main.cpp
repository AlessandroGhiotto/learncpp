#include <iostream>

class Base
{
  private: // our member is now private
    int m_id {};

  public:
    Base(int id = 0)
        : m_id { id }
    {
    }

    int getId() const { return m_id; }
};

class Derived : public Base
{
  private: // our member is now private
    double m_cost;

  public:
    Derived(double cost = 0.0, int id = 0)
        : Base { id } // Call Base(int) constructor with value id!
          ,
          m_cost { cost }
    {
    }

    double getCost() const { return m_cost; }
};

int main0()
{
    Derived derived { 1.3, 5 }; // use Derived(double, int) constructor
    std::cout << "Id: " << derived.getId() << '\n';
    std::cout << "Cost: " << derived.getCost() << '\n';

    return 0;
}

// -------------------------------------------------------------------
// EXERCISE

class Fruit
{
  private:
    std::string m_name {};
    std::string m_color {};

  public:
    Fruit(std::string_view name, std::string_view color)
        : m_name { name }, m_color { color }
    {
    }

    const std::string& getName() const { return m_name; }
    const std::string& getColor() const { return m_color; }
};

class Apple : public Fruit
{
  private:
    double m_fiber {};

  public:
    Apple(std::string_view name, std::string_view color, double fiber)
        : Fruit { name, color }, m_fiber { fiber }
    {
    }

    double getFiber() const { return m_fiber; }
};

std::ostream& operator<<(std::ostream& out, const Apple& a)
{
    out << "Apple(" << a.getName() << ", " << a.getColor() << ", " << a.getFiber() << ')';
    return out;
}

class Banana : public Fruit
{
  public:
    Banana(std::string_view name, std::string_view color)
        : Fruit { name, color }
    {
    }
};

std::ostream& operator<<(std::ostream& out, const Banana& b)
{
    out << "Banana(" << b.getName() << ", " << b.getColor() << ')';
    return out;
}

int main()
{
    const Apple a { "Red delicious", "red", 4.2 };
    std::cout << a << '\n';

    const Banana b { "Cavendish", "yellow" };
    std::cout << b << '\n';

    return 0;
}
