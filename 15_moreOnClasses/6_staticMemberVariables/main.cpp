#include <iostream>

struct Something
{
    static int s_value; // declare s_value as static (initializer moved below)
};

int Something::s_value { 1 }; // define and initialize s_value to 1 (we'll discuss this section below)

class Whatever
{
  private:
    static inline int s_idGenerator { 1 };
    int m_id {};

  public:
    // grab the next value from the id generator
    Whatever() : m_id { s_idGenerator++ }
    {
    }

    int getID() const { return m_id; }
};

int main()
{
    std::cout << Something::s_value << '\n';

    Something s1 {};
    Something s2 {};

    s1.s_value = 2;

    std::cout << s1.s_value << '\n';
    std::cout << s2.s_value << "\n\n";

    Whatever first {};
    Whatever second {};
    Whatever third {};

    std::cout << first.getID() << '\n';
    std::cout << second.getID() << '\n';
    std::cout << third.getID() << '\n';

    return 0;
}
