#include <iostream>

int readNumber1(int x)
{
    std::cout << "Please enter a number: ";
    std::cin >> x;
    return x;
}

void writeAnswer1(int x)
{
    std::cout << "The sum is: " << x << '\n';
}

int main1()
{
    int x{};
    readNumber1(x);
    // with error to be fixed
    // x = x + readNumber1(x);
    x = readNumber1(x) + readNumber1(x); // or just make readNumber() take no input
    writeAnswer1(x);

    return 0;
}
//////////////////////////////////////////7
// exercise 2

int readNumber2()
{
    std::cout << "Please enter a number: ";
    int x{};
    std::cin >> x;
    return x;
}

void writeAnswer2(int x)
{
    std::cout << "The quotient is: " << x << '\n';
}

int main2()
{
    int x{};
    int y{};
    x = readNumber2();
    // x = readNumber2();
    y = readNumber2();
    writeAnswer2(x / y);

    return 0;
}

//////////////////////////////////////////
// exercise 3: look at the function stack
// d()
// b()
// a()
// main()

void d()
{ // here
}

void c()
{
}

void b()
{
    c();
    d();
}

void a()
{
    b();
}

int main3()
{
    a();

    return 0;
}

//////////////////////////
// exercise 4
#include <iostream>

int readNumber()
{
    std::cout << "Please enter a number: ";
    // char x{};
    int x{};
    std::cin >> x;

    return x;
}

void writeAnswer(int x)
{
    std::cout << "The sum is: " << x << '\n';
}

int main()
{
    int x{readNumber()};
    int y{readNumber()};
    writeAnswer(x + y);

    return 0;
}
