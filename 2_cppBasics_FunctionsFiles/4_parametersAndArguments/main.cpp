#include <iostream>

void printValues(int x, int y)
{
    std::cout << x << "\n";
    std::cout << y << "\n";
}

int main0()
{
    printValues(6, 7);

    return 0;
}

///////////////////////////////
int getValueFromUser()
{
    int input{};
    std::cout << "Enteer an integer: ";
    std::cin >> input;

    return input;
}

void printDouble(int value)
{
    std::cout << value << " doubled is: " << value * 2 << '\n';
}

int main1()
{
    int num{getValueFromUser()};
    printDouble(num);
    // or we can just do:
    // printDouble(getValueFromUser());

    return 0;
}

/////////////////////////////////////
int add(int x, int y)
{
    return x + y;
}

int multiply(int x, int y)
{
    return x * y;
}

int main2()
{
    std::cout << add(4, 5) << '\n';
    std::cout << add(1 + 2, 3 * 4) << '\n';

    int a{5};
    std::cout << add(a, a) << '\n';

    std::cout << add(1, multiply(2, 3)) << '\n';
    std::cout << add(1, add(2, 3)) << '\n';

    return 0;
}

//////////////////////////////////
// quizzes
int doubleNumber(int x)
{
    return x * 2;
}

int main()
{
    int input{getValueFromUser()};
    std::cout << doubleNumber(input) << "\n";

    return 0;
}
