
#include <iostream>
#include <string_view>

/// PROCEDURAL
enum AnimalType
{
    cat,
    dog,
    chicken,
    snake,
};

constexpr std::string_view animalName(AnimalType type)
{
    switch (type)
    {
    case cat:
        return "cat";
    case dog:
        return "dog";
    case chicken:
        return "chicken";
    case snake:
        return "snake";
    default:
        return "";
    }
}

constexpr int numLegs(AnimalType type)
{
    switch (type)
    {
    case cat:
    case dog:
        return 4;
    case chicken:
        return 2;
    case snake:
    default:
        return 0;
    }
}

// OOP
struct Cat
{
    std::string_view name { "cat" };
    int numLegs { 4 };
};

struct Dog
{
    std::string_view name { "dog" };
    int numLegs { 4 };
};

struct Chicken
{
    std::string_view name { "chicken" };
    int numLegs { 2 };
};

struct Snake
{
    std::string_view name { "snake" };
    int numLegs { 0 };
};

int main()
{
    // PROCEDURAL
    // constexpr AnimalType animal { snake };
    // std::cout << "A " << animalName(animal) << " has " << numLegs(animal) << " legs\n";

    // OOP
    constexpr Snake animal;
    std::cout << "a " << animal.name << " has " << animal.numLegs << " legs\n";

    return 0;
}
