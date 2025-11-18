#include <iostream>
#include <optional>
#include <string_view>

int main0()
{
    enum class Color // "enum class" defines this as a scoped enumeration rather than an unscoped enumeration
    {
        red, // red is considered part of Color's scope region
        blue,
    };

    enum class Fruit {
        banana, // banana is considered part of Fruit's scope region
        apple,
    };

    Color color { Color::red }; // note: red is not directly accessible, we have to use Color::red
    Fruit fruit { Fruit::banana }; // note: banana is not directly accessible, we have to use Fruit::banana

    // if (color == fruit) // compile error: the compiler doesn't know how to compare different types Color and Fruit
    //     std::cout << "color and fruit are equal\n";
    // else
    //     std::cout << "color and fruit are not equal\n";

    // std::cout << red << '\n'; // compile error: red not defined in this scope region
    // std::cout << Color::red << '\n'; // compile error: std::cout doesn't know how to print this (will not implicitly convert to int)

    // std::cout << color << '\n'; // won't work, because there's no implicit conversion to int
    std::cout << static_cast<int>(color) << '\n'; // explicit conversion to int, will print 1
    std::cout << static_cast<int>(fruit) << '\n';
    return 0;
}

//------------------------------------------------------------
// EXERCISE
enum class Animal {
    pig,
    chicken,
    goat,
    cat,
    dog,
    duck,
};

constexpr std::string_view getAnimalName(Animal animal)
{
    switch (animal) {
    case Animal::pig:
        return "pig";
    case Animal::chicken:
        return "chicken";
    case Animal::goat:
        return "goat";
    case Animal::cat:
        return "cat";
    case Animal::dog:
        return "dog";
    case Animal::duck:
        return "duck";
    default:
        return "???";
    }
}

std::optional<int> getNumberOfLegs(Animal animal)
{
    switch (animal) {
    case Animal::pig:
        return 4;
    case Animal::chicken:
        return 2;
    case Animal::goat:
        return 4;
    case Animal::cat:
        return 4;
    case Animal::dog:
        return 4;
    case Animal::duck:
        return 2;
    default:
        return {};
    }
}

void printNumberOfLegs(Animal animal)
{
    std::optional<int> n_legs { getNumberOfLegs(animal) };
    if (n_legs) {
        std::cout << "A " << getAnimalName(animal) << " has " << *n_legs << " legs.\n";
    } else {
        std::cout << "The animal is not valid.\n";
    }
}
/*
void printNumberOfLegs(Animal animal)
{
    std::cout << "A " << getAnimalName(animal) << " has ";

    // If C++20 capable, could use `using enum Animal` here to reduce Animal prefix redundancy
    switch (animal)
    {
        case Animal::chicken:
        case Animal::duck:
            std::cout << 2;
            break;

        case Animal::pig:
        case Animal::goat:
        case Animal::cat:
        case Animal::dog:
            std::cout << 4;
            break;

        default:
            std::cout << "???";
            break;
    }

    std::cout << " legs.\n";
}
*/

int main()
{
    Animal c { Animal::cat };
    printNumberOfLegs(c);

    Animal d { Animal::duck };
    printNumberOfLegs(d);

    return 0;
}
