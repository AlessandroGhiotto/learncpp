#include <iostream>
#include <string>

struct Monster
{
    enum Type
    {
        unknown,
        ogre,
        dragon,
        orc,
        giant_spider,
        slime
    };

    Type type { Type::unknown };
    std::string name { "" };
    int health { 0 };
};

// Return the name of the monster's type as a string
// Since this could be used elsewhere, it's better to make this its own function
// constexpr std::string_view getMonsterTypeString(Monster::Type type)
// {
//     switch (type)
//     {
//     case Monster::ogre:
//         return "Ogre";
//     case Monster::dragon:
//         return "Dragon";
//     case Monster::orc:
//         return "Orc";
//     case Monster::giant_spider:
//         return "Giant Spider";
//     case Monster::slime:
//         return "Slime";
//     }

//     return "Unknown";
// }

std::ostream& operator<<(std::ostream& out, Monster::Type type)
{
    using enum Monster::Type;
    switch (type)
    {
    case unknown:
        out << "unknown";
        return out;
    case ogre:
        out << "ogre";
        return out;
    case dragon:
        out << "dragon";
        return out;
    case orc:
        out << "orc";
        return out;
    case giant_spider:
        out << "giant spider";
        return out;
    case slime:
        out << "slime";
        return out;
    default:
        out << "unknown";
        return out;
    }
}

void printMonster(const Monster& m)
{
    std::cout << "Type: " << m.type << std::endl;
    std::cout << "Name: " << m.name << std::endl;
    std::cout << "health: " << m.health << std::endl;
}

int main0()
{
    Monster turp { Monster::ogre, "Turp", 145 };
    Monster slurp { Monster::slime, "Slurp", 24 };

    printMonster(turp);
    std::cout << std::endl;
    printMonster(slurp);

    return 0;
}

/////////////////////////////////////////////////////
// EXERCISE 2
template <typename T>
struct Triad
{
    T first {};
    T second {};
    T third {};
};

template <typename T>
void print(const Triad<T>& tri)
{
    std::cout << "[" << tri.first << ", " << tri.second << ", " << tri.third << "]";
}

int main()
{
    Triad t1 { 1, 2, 3 }; // note: uses CTAD to deduce template arguments
    print(t1);

    Triad t2 { 1.2, 3.4, 5.6 }; // note: uses CTAD to deduce template arguments
    print(t2);

    return 0;
}
