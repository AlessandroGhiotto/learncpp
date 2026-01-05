#include <iostream>

// enum class FruitType
// {
// 	apple,
// 	banana,
// 	cherry
// };

class Fruit
{
  public:
    // FruitType has been moved inside the class, under the public access specifier
    // We've also renamed it Type and made it an enum rather than an enum class
    enum Type
    {
        apple,
        banana,
        cherry
    };

    using Percentage = int;

    class Printer
    {
      public:
        void print(const Fruit& f) const
        {
            // Printer can't access Fruit's `this` pointer
            // so we can't print m_type and m_percentageEaten directly
            // Instead, we have to pass in an Fuit object to use
            // Because Printer is a member of Fuit,
            // we can access private members f.m_type and f.m_percentageEaten directly
            switch (f.m_type)
            {
            case Fruit::apple:
                std::cout << "Apple";
                break;
            case Fruit::banana:
                std::cout << "Banana";
                break;
            case Fruit::cherry:
                std::cout << "Cherry";
                break;

            default:
                break;
            }
            std::cout << " has percentage eaten: " << f.m_percentageEaten << '\n';
        }
    };

  private:
    Type m_type {};
    Percentage m_percentageEaten { 0 };

  public:
    Fruit(Type type) : m_type { type }
    {
    }

    Type getType() { return m_type; }
    Percentage getPercentageEaten() { return m_percentageEaten; }

    bool isCherry() { return m_type == cherry; } // Inside members of Fruit, we no longer need to prefix enumerators with FruitType::
};

int main()
{
    // Note: Outside the class, we access the enumerators via the Fruit:: prefix now
    Fruit apple { Fruit::apple };

    if (apple.getType() == Fruit::apple)
        std::cout << "I am an apple\n";
    else
        std::cout << "I am not an apple\n";

    Fruit::Percentage p { apple.getPercentageEaten() };
    std::cout << "percentage eaten: " << p << std::endl;

    const Fruit::Printer printer {}; // instantiate an object of the inner class
    printer.print(apple);
    return 0;
}
