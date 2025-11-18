#include <iostream>
#include <string>

const std::string& getProgramName() // returns a const reference
{
    static const std::string s_programName {
        "Calculator"
    }; // has static duration, destroyed at end of program
    return s_programName;
}

// THIS RESULT IN UNDEFINEDD BEHAVIOUR
// const std::string& getProgramName()
// {
//     const std::string programName { "Calculator" }; // now a non-static local
//     variable, destroyed when function ends return programName;
// }

const int& getNextId()
{
    static int s_x { 0 }; // note: variable is non-const
    ++s_x;                // generate the next id
    return s_x;           // and return a reference to it
}

int main1()
{
    std::cout << "This program is named " << getProgramName() << std::endl;

    const int& id1 { getNextId() }; // id1 is a reference
    const int& id2 { getNextId() }; // id2 is a reference
    std::cout << id1 << id2 << '\n';

    return 0;
}

int& max(int& x, int& y)
{
    return ((x > y) ? x : y);
}

int main()
{
    int a { 5 };
    int b { 7 };

    max(a, b) = 9;
    std::cout << a << b << std::endl;
    return 0;
}
