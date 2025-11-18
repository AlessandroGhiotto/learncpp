#include <iostream>

int add(int x, int y)
{
    return x + y;
}

// this is a testing function, used to test add()
void testadd()
{
    std::cout << "This function should print: 2 0 0 -2\n";
    std::cout << add(1, 1) << ' ';
    std::cout << add(-1, 1) << ' ';
    std::cout << add(1, -1) << ' ';
    std::cout << add(-1, -1) << ' ';
}

int main()
{
    testadd();

    return 0;
}
