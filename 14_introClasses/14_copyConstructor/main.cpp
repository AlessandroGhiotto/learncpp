#include <iostream>

class Fraction
{
  private:
    int m_numerator { 0 };
    int m_denominator { 1 };

  public:
    // Default constructor
    Fraction(int numerator = 0, int denominator = 1)
        : m_numerator { numerator }, m_denominator { denominator }
    {
    }

    // COPY CONSTRUCTOR
    Fraction(const Fraction& fraction)
        : m_numerator { fraction.m_numerator }, m_denominator { fraction.m_denominator }
    {
        std::cout << "Copy constructor called\n"; // just to prove it works
    }

    // delete the copy constructor: no copies can be made
    // Fraction(const Fraction& fraction) = delete;

    void print() const
    {
        std::cout << "Fraction(" << m_numerator << ", " << m_denominator << ")\n";
    }
};

int main()
{
    Fraction f { 5, 3 };  // Calls Fraction(int, int) constructor
    Fraction fCopy { f }; // Calls Fraction(const Fraction&) copy constructor

    f.print();
    fCopy.print();

    return 0;
}
