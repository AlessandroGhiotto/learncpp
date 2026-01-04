#include <iostream>
#include <string>

struct Date
{
    int year {};
    int month {};
    int day {};

    void print()
    {
        std::cout << year << '/' << month << '/' << day << std::endl;
    }

    // Overload
    void print(std::string_view prefix)
    {
        std::cout << prefix << year << '/' << month << '/' << day;
    }
};

// non member function version
void print(const Date& d)
{
    std::cout << d.year << '/' << d.month << '/' << d.day << std::endl;
}

struct Person
{
    std::string name {};
    int age {};

    void kisses(const Person& other)
    {
        std::cout << name << " kisses " << other.name << std::endl;
    }
};

struct IntPair
{
    int first {};
    int second {};
    void print()
    {
        std::cout << "Pair (" << first << ", " << second << ")\n";
    }

    bool isEqual(IntPair other)
    {
        if (first == other.first && second == other.second)
            return true;
        else
            return false;
    }
};

int main()
{
    Date d { 2025, 11, 18 };
    d.print();
    print(d);
    d.print("today: ");
    std::cout << std::endl;

    Person joe { "joe", 30 };
    Person alice { "alice", 27 };
    joe.kisses(alice);
    std::cout << std::endl;

    // EXERCISE
    IntPair p1 { 1, 2 };
    IntPair p2 { 3, 4 };

    std::cout << "p1: ";
    p1.print();

    std::cout << "p2: ";
    p2.print();

    std::cout << "p1 and p1 " << (p1.isEqual(p1) ? "are equal\n" : "are not equal\n");
    std::cout << "p1 and p2 " << (p1.isEqual(p2) ? "are equal\n" : "are not equal\n");
    return 0;
}
