// condition ? expression1 : expression2;
//  If condition evaluates to true, then expression1 is evaluated, otherwise expression2 is evaluated.

#include <iostream>

int getValue()
{
    std::cout << "Enter a number: ";
    int x{};
    std::cin >> x;
    return x;
}

int main0()
{
    int x{getValue()};
    int y{getValue()};
    int max{(x > y) ? x : y};
    std::cout << "The max of " << x << " and " << y << " is " << max << ".\n";

    return 0;
}

int main1()
{
    constexpr bool inBigClassroom{false};
    constexpr int classSize{inBigClassroom ? 30 : 20};

#if 0
    // without conditional statement doenst work!
    if (inBigClassroom)
        constexpr int classSize { 30 };
    else
        constexpr int classSize { 20 };
#endif
    std::cout << "The class size is: " << classSize << '\n';

    return 0;
}

// given the low precedence of ?: it is better to always use parenthesis
// for example here we get strange behaviours since
// op<< has higher precedence wrt op?:
int main2()
{
    int x{2};
    // std::cout << (x < 0) ? "negative" : "non-negative";
    std::cout << ((x < 0) ? "negative" : "non-negative") << "\n";

    return 0;
}

// types of the second and third operand must match
// or be convertible to the same type
int main()
{
    std::cout << (true ? 1 : 2) << '\n';    // okay: both operands have matching type int
    std::cout << (false ? 1 : 2.2) << '\n'; // okay: int value 1 converted to double
    // std::cout << (true ? -1 : 2u) << '\n';  // surprising result: -1 converted to unsigned int, result out of range

    int x{5}; // intentionally non-constexpr for this example
    // We can explicitly convert the types to match
    std::cout << ((x != 5) ? std::to_string(x) : std::string{"x is 5"}) << '\n';
    // Or use an if-else statement
    if (x != 5)
        std::cout << x << '\n';
    else
        std::cout << "x is 5" << '\n';

    return 0;
}
