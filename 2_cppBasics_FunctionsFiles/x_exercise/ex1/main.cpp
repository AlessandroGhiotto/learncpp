#include <iostream>

int readNumber()
{
    int input{};
    std::cout << "Choose an integer: ";
    std::cin >> input;

    return input;
}

void writeAnswer(int x)
{
    std::cout << "The result is : " << x << "\n";
}

int main()
{
    writeAnswer(readNumber() + readNumber());

    return 0;
}
