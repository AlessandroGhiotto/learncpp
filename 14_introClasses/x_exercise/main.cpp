#include <cmath>
#include <iostream>

/// EXERCISE 1
class Point2d
{
  public:
    Point2d(double x, double y)
        : m_x { x }, m_y { y }
    {
    }
    // Point2d()
    //     : Point2d { 0.0, 0.0 }
    // {
    // }
    Point2d() = default;

    void print() const
    {
        std::cout << "Point2d(" << m_x << ", " << m_y << ")\n";
    }

    double distanceTo(const Point2d& other) const
    {
        return std::sqrt((m_x - other.m_x) * (m_x - other.m_x) +
                         (m_y - other.m_y) * (m_y - other.m_y));
    }

  private:
    double m_x { 0.0 };
    double m_y { 0.0 };
};

int main0()
{
    Point2d first {};
    Point2d second { 3.0, 4.0 };

    // Point2d third{ 4.0 }; // should error if uncommented

    first.print();
    second.print();

    std::cout << "Distance between two points: " << first.distanceTo(second) << '\n';
    return 0;
}

/// EXERCISE 2
class Fraction
{
  public:
    Fraction(int numerator, int denominator)
        : m_numerator { numerator }, m_denominator { denominator }
    {
    }

    Fraction multiply(const Fraction& other)
    {
        return { m_numerator * other.m_numerator, m_denominator * other.m_denominator };
    }

    void printFraction()
    {
        std::cout << m_numerator << '/' << m_denominator << '\n';
    }

    void getFraction()
    {
        std::cout << "Enter a value for numerator: ";
        std::cin >> m_numerator; // this is a member function, so we can access members directly
        std::cout << "Enter a value for denominator: ";
        std::cin >> m_denominator;
        std::cout << '\n';
    }

  private:
    int m_numerator { 0 };
    int m_denominator { 1 };
};

Fraction getFraction()
{
    std::cout << "Enter a value for numerator: ";
    int numerator {};
    std::cin >> numerator;
    std::cout << "Enter a value for denominator: ";
    int denominator {};
    std::cin >> denominator;
    std::cout << '\n';

    return Fraction { numerator, denominator };
}

int main()
{
    Fraction f1 { getFraction() };
    Fraction f2 { getFraction() };

    std::cout << "Your fractions multiplied together: ";

    (f1.multiply(f2)).printFraction();

    return 0;
}
