#include <iostream>

int main()
{
    using Distance = double; // define Distance as an alias for type double

    Distance milesToDestination{3.4}; // defines a variable of type double

    std::cout << milesToDestination << '\n'; // prints a double value

    // typedef: old way for aliases [Avoid it]
    // typedef double Distance;

    // OTHER uses of aliases:
#if 0
using VectPairSI = std::vector<std::pair<std::string, int>>; // make VectPairSI an alias for this crazy type

using TestScore = int;
TestScore gradeTest();

#endif

    return 0;
}

// exercise:
// int printData();
// =>
// using PrintError = int;
// PrintError printData();
