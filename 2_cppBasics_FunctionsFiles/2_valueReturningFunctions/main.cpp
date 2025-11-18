#include <iostream>

int returnFive()
{
    return 5;
}

int main0()
{
    std::cout << returnFive() << "\n";
    std::cout << returnFive() + 2 << "\n";

    returnFive(); // 5 is returned, but is ignored

    return 0;
}

//////////////////////////////////////
// get value from user with functions
int getValueFromUser()
{
    int num{};
    std::cout << "Enter an integer: ";
    std::cin >> num;

    return num;
}

int main1()
{
    int num{getValueFromUser()};
    std::cout << num << " doubled is: " << num * 2 << "\n";

    return 0;
}

////////////////////////////
// void foo()
// {
//     main(); // Compile error: main not allowed to be called explicitly
// }

// void main() // Compile error: main not allowed to have non-int return type
// {
//     foo();
// }

/////////////////////////////
// DRY: Don't Repeat Yourself
int main()
{
    int x{getValueFromUser()};
    int y{getValueFromUser()};

    std::cout << x << " + " << y << " = " << x + y << "\n";
}
