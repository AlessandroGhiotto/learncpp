#include <iostream>

// Define a new unscoped enumeration named Color
enum Color {
    // Here are the enumerators
    // These symbolic constants define all the possible values this type can hold
    // Each enumerator is separated by a comma, not a semicolon
    red,
    green,
    blue, // trailing comma optional but recommended
}; // the enum definition must end with a semicolon

// avoifing naming collisions:
enum Feeling {
    feeling_happy,
    feeling_tired,
    feeling_blue, // no longer has a naming collision with color_blue
};

namespace Animals {
enum Animals {
    cat,
    fog,
    platipus
};
}
int main0()
{
    // Define a few variables of enumerated type Color
    [[maybe_unused]] Color apple { red }; // my apple is red
    [[maybe_unused]] Color shirt { green }; // my shirt is green
    [[maybe_unused]] Color cup { blue }; // my cup is blue

    // Color socks { white }; // error: white is not an enumerator of Color
    // Color hat { 2 }; // error: 2 is not an enumerator of Color

    [[maybe_unused]] Color pear { red }; // okay, accessing enumerator from global namespace
    [[maybe_unused]] Color raspberry { Color::red }; // also okay, accessing enumerator from scope of Color
    return 0;
}

// EXERCISE
namespace Monster {
enum MonsterType {
    orc,
    goblin,
    troll,
    ogre,
    skeleton
};
}
int main()
{
    Monster::MonsterType aTroll { Monster::troll };
    if (aTroll)
        std::cout << "A troll\n";
}
