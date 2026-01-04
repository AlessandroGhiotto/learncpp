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
    Foo(int x, int y)
        : m_x { x }, m_y { y } // member initialization list
    {
        std::cout << x << ", " << y << " constructed" << std::endl;
    }

    void print() { std::cout << m_x << ", " << m_y << std::endl; }

  private:
    int m_x {};
    int m_y {};
};

// EXERCISE
class Ball
{
  public:
    Ball(std::string_view color, double radius)
        : m_color { color }, m_radius { radius }
    {
    }

    double getRadius() const { return m_radius; }
    const std::string& getColor() const { return m_color; }

  private:
    std::string m_color { "none" };
    double m_radius { 0.0 };
};

void print(const Ball& b)
{
    std::cout << "Ball(" << b.getColor() << ", " << b.getRadius() << ")\n";
}

int main()
{
    Foo f { 3, 4 };
    f.print();

    Ball blue { "blue", 10.0 };
    print(blue);

    Ball red { "red", 12.0 };
    print(red);
    return 0;
}
