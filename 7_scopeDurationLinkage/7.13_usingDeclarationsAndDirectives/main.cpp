#include <iostream>

int main0()
{
    using std::cout;          // this using declaration tells the compiler that cout should resolve to std::cout
    cout << "Hello world!\n"; // so no std:: prefix is needed here!

    return 0;
} // the using declaration expires at the end of the current scope

///////////////////////////////////////////////////
int main()
{
    using namespace std;      // all names from std namespace now accessible without qualification
    cout << "Hello world!\n"; // so no std:: prefix is needed here

    return 0;
} // the using-directive ends at the end of the current scope

//////////////////////////////////////////////////
// using directives are very dangerous
namespace A
{
    int x{10};
}

namespace B
{
    int x{20};
}

// Here we get naming collisions
// int main()
// {
// 	using namespace A;
// 	using namespace B;

// 	std::cout << x << '\n';

// 	return 0;
// }
