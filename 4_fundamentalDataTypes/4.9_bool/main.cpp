#include <iostream>

int main0()
{
#if 0
    bool b1{true};
    bool b2{false};
    b1 = false;
    bool b3{}; // default initialize to false

    bool b4{!true};  // b1 will be initialized with the value false
    bool b5{!false}; // b2 will be initialized with the value true
#endif

    // printed and evaluated as 0/1
    std::cout << true << '\n';  // true evaluates to 1
    std::cout << !true << '\n'; // !true evaluates to 0
    bool b{false};
    std::cout << b << '\n';    // b is false, which evaluates to 0
    std::cout << !b << "\n\n"; // !b is true, which evaluates to 1

    std::cout << std::boolalpha; // print bools as true or false
    std::cout << true << '\n';
    std::cout << false << "\n\n";

    bool b1 = 4; // copy initialization allows implicit conversion from int to bool (may be warning)
    std::cout << b1 << '\n';
    bool b2 = 0; // copy initialization allows implicit conversion from int to bool
    std::cout << b2 << '\n';
    bool b3 = 1;
    std::cout << b3 << '\n';

    return 0;
}

// bool as input
int main1()
{
#if 0
    bool b{};                               // default initialize to false
    std::cout << "Enter a boolean value: "; // try to put true ajajajjja
    std::cin >> b;
    std::cout << "You entered: " << b << "\n\n";
#endif

    bool b{};
    // Allow the user to input 'true' or 'false' for boolean values
    // This is case-sensitive, so True or TRUE will not work
    std::cin >> std::boolalpha;
    std::cin >> b;
    // Let's also output bool values as `true` or `false`
    std::cout << std::boolalpha;
    std::cout << "You entered: " << b << '\n';
    return 0;
}

// returns true if x and y are equal, false otherwise
bool isEqual(int x, int y)
{
    return x == y; // operator== returns true if x equals y, and false otherwise
}

int main()
{
    std::cout << "Enter an integer: ";
    int x{};
    std::cin >> x;

    std::cout << "Enter another integer: ";
    int y{};
    std::cin >> y;

    std::cout << std::boolalpha; // print bools as true or false
    std::cout << x << " and " << y << " are equal? ";
    std::cout << isEqual(x, y) << '\n'; // will return true or false

    return 0;
}
