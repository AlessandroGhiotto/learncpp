#include <iostream>
#include <string>
#include <string_view>

// Write a program that asks for the name and age of two people, then prints which person is older

std::string personName(int n)
{
    std::cout << "Enter the name of person #" << n << ": ";
    std::string name{};
    std::getline(std::cin >> std::ws, name);
    return name;
}

int personAge(std::string_view person_name)
{
    std::cout << "Enter the age of " << person_name << ": ";
    int age{};
    std::cin >> age;
    return age;
}

void whoIsOlder(std::string_view n1, int age1, std::string_view n2, int age2)
{
    if (age1 > age2)
        std::cout << n1 << " (age " << age1 << ") is older than " << n2 << " (age " << age2 << ").\n";
    else
        std::cout << n2 << " (age " << age2 << ") is older than " << n1 << " (age " << age1 << ").\n";
}

int main()
{
    std::string name1{personName(1)};
    int age1{personAge(name1)};

    std::string name2{personName(2)};
    int age2{personAge(name2)};

    whoIsOlder(name1, age1, name2, age2);

    return 0;
}
