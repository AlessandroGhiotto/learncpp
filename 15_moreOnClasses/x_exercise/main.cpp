#include "Random.h"
#include <iostream>
#include <string>

class Monster
{
  public:
    enum Type
    {
        dragon,
        goblin,
        ogre,
        orc,
        skeleton,
        troll,
        vampire,
        zombie,
        maxMonsterTypes
    };

    Monster(Type type, std::string_view name, std::string_view roar, int hitpoints)
        : m_type { type }, m_name { name }, m_roar { roar }, m_hitpoints { hitpoints }
    {
    }

    constexpr std::string_view getTypeString() const
    {
        switch (m_type)
        {
        case dragon:
            return "dragon";
        case goblin:
            return "goblin";
        case ogre:
            return "ogre";
        case orc:
            return "orc";
        case skeleton:
            return "skeleton";
        case troll:
            return "troll";
        case vampire:
            return "vampire";
        case zombie:
            return "zombie";
        default:
            return "???";
        }
    }

    void print() const
    {
        std::cout << m_name << " the " << getTypeString();
        if (m_hitpoints <= 0)
            std::cout << " is dead.\n";
        else
            std::cout << " has " << m_hitpoints << " hit points and says " << m_roar << ".\n";
    }

  private:
    Type m_type {};
    std::string m_name { "???" };
    std::string m_roar { "???" };
    int m_hitpoints {};
};

namespace MonsterGenerator
{
std::string_view getName(int n)
{
    switch (n)
    {
    case 0:
        return "John gambardine";
    case 1:
        return "Gaton";
    case 2:
        return "Bobby";
    case 3:
        return "Klein";
    case 4:
        return "Merlin";
    case 5:
        return "Rick";
    default:
        return "???";
    }
}

std::string_view getRoar(int n)
{
    switch (n)
    {
    case 0:
        return "*barf*";
    case 1:
        return "**buuuuurp**";
    case 2:
        return "*click clock*";
    case 3:
        return "*shhhhhh*";
    case 4:
        return "POLIZIAAAA";
    case 5:
        return "never gonna give you up, never gonna let you down,...";
    default:
        return "???";
    }
}

Monster generate()
{
    return Monster {
        static_cast<Monster::Type>(Random::get(0, Monster::maxMonsterTypes - 1)),
        getName(Random::get(0, 5)),
        getRoar(Random::get(0, 5)),
        Random::get(0, 100)
    };
}
} // namespace MonsterGenerator

int main()
{
    Monster skeleton { Monster::skeleton, "Bones", "*rattle*", 4 };
    skeleton.print();

    Monster vampire { Monster::vampire, "Nibblez", "*hiss*", 0 };
    vampire.print();

    Monster m { MonsterGenerator::generate() };
    m.print();

    return 0;
}
