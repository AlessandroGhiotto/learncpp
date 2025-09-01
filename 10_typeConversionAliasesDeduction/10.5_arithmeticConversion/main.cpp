#include <iostream>
#include <typeinfo> // for typeid()

int main()
{
    int x{2};
    std::cout << typeid(x).name() << '\n'; // show us the name of the type for i

    double y{3.5};
    std::cout << typeid(y).name() << '\n'; // show us the name of the type for d

    std::cout << typeid(x + y).name() << ' ' << x + y << '\n'; // show us the type of i + d
    std::cout << "--------------------------\n";

    // SIGNED AND UNSIGNED ISSUES
    std::cout << typeid(5u - 10).name() << ' ' << 5u - 10 << '\n'; // 5u means treat 5 as an unsigned integer
    std::cout << std::boolalpha << (-3 < 5u) << '\n';

    return 0;
}
