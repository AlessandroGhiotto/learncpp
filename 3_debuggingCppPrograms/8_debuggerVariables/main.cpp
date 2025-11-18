// Integrated debugger
// watching variables, watch vindow, break on value change,
// evaluate expressions, local watches
#include <iostream>

int main()
{
    int x{1};
    std::cout << x << ' ';

    x = x + 2;
    std::cout << x << ' ';

    x = x + 3;
    std::cout << x << ' ';

    return 0;
}
