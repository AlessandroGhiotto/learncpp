#include <iostream>

/*
struct Foo // Foo is an aggregate
{
    int x {};
    int y {};
};

Foo foo { 6, 7 }; // uses aggregate initialization
*/

class Foo
{
  public:
    // here's our constructor function that takes two initializers
    Foo(int x, int y) { std::cout << x << ", " << y << std::endl; }

    void print() { std::cout << m_x << ", " << m_y << std::endl; }

  private:
    int m_x {};
    int m_y {};
};
int main()
{
    Foo f { 3, 4 };
    f.print();
    return 0;
}
