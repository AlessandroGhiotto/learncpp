#include <iostream>
#include <string>
#include <string_view>

class Employee // members are private by default
{
    std::string m_name {};
    char m_firstInitial {};

  public:
    void setName(std::string_view name)
    {
        m_name = name;
        m_firstInitial = name.front(); // use std::string::front() to get first letter of `name`
    }

    void print() const
    {
        std::cout << "Employee " << m_name << " has first initial " << m_firstInitial << '\n';
    }
};

/////////////////////////////////////////////////////////
class Something1
{
    int a {};
    int b {};
    int c {};

  public:
    void setValue1(int zorro) { a = zorro; }
    int getValue1() { return a; }
};
class Something2
{
    int vis[3];

  public:
    void setValue1(int zorro) { vis[0] = zorro; }
    int getValue1() { return vis[0]; }
};

/////////////////////////////////////////////////////////////
class Yogurt
{
  private:
    std::string m_taste { "vanilla" };

  public:
    void setTaste(std::string_view t) { m_taste = t; }
    const std::string& getTaste() const { return m_taste; }

    // WORST : acces m_taste even if we have a getter for it
    // void print() const { std::cout << "taste: " << m_taste << std::endl; }

    // OKAY
    void print() const { std::cout << "taste: " << getTaste() << std::endl; }
};

// BETTER ONE
void print(const Yogurt& y) { std::cout << "taste: " << y.getTaste() << std::endl; }

int main()
{
    Employee e {};
    e.setName("John");
    e.print();

    e.setName("Mark");
    e.print();
    // there is no way to change e.m_firstInitial from outside

    // change implementatioon wo changeing interface
    Something1 x;
    x.setValue1(3);
    std::cout << x.getValue1() << std::endl;
    Something2 y;
    y.setValue1(3);
    std::cout << y.getValue1() << std::endl;

    /////
    Yogurt yoo {};
    yoo.setTaste("cherry");
    yoo.print();
    print(yoo);

    return 0;
}
