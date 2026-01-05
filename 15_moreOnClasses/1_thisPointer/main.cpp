#include <iostream>

class Simple
{
  private:
    int m_id {};

  public:
    Simple(int id)
        : m_id { id }
    {
    }

    int getID() const { return m_id; }
    void setID(int id) { m_id = id; }
    // Simple::setID(&simple, 2); // note that simple has been changed from an object prefix to a function argument!
    // static void setID(Simple* const this, int id) { this->m_id = id; }

    void print() const { std::cout << this->m_id; } // use `this` pointer to access the implicit object and operator-> to select member m_id
};

int main0()
{
    Simple simple { 1 };
    simple.setID(2);

    simple.print();

    return 0;
}

class Calc
{
  private:
    int m_value {};

  public:
    Calc& add(int value)
    {
        m_value += value;
        return *this;
    }
    Calc& sub(int value)
    {
        m_value -= value;
        return *this;
    }
    Calc& mult(int value)
    {
        m_value *= value;
        return *this;
    }

    int getValue() const { return m_value; }

    void reset() { *this = {}; }
};

int main()
{
    Calc calc {};
    calc.add(5).sub(3).mult(4);

    std::cout << calc.getValue() << '\n'; // prints 8

    calc.reset();

    std::cout << calc.getValue() << '\n'; // prints 0

    return 0;
}
