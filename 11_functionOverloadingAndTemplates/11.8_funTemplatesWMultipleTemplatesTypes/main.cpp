#include <iostream>

template <typename T, typename U> // We're using two template type parameters named T and U
T max(T x, U y)                   // x can resolve to type T, and y can resolve to type U
{
    return (x < y) ? y : x; // uh oh, we have a narrowing conversion problem here
}

/// it can be useful the "auto" for return types in such cases
template <typename T, typename U>
auto max2(T x, U y) // ask compiler can figure out what the relevant return type is
{
    return (x < y) ? y : x;
}

// This is another option, if we could need also a to use the function with just a forward declaration
// template <typename T, typename U>
// auto max(T x, U y) -> std::common_type_t<T, U>
// {
//     return (x < y) ? y : x;
// }

int main2()
{
    // std::cout << max(2, 3.5) << '\n'; // we get also warning for conversion double->int
    std::cout << max2(2, 3.5) << '\n';

    return 0;
}

/// ABBREVIATED FUNCTION TEMPLATES
auto max3(auto x, auto y)
{
    return (x < y) ? y : x;
}
// is a shortcut to this:
// template <typename T, typename U>
// auto max(T x, U y)
// {
//     return (x < y) ? y : x;
// }

///////////////////////////////////////////
/// OVERLOADING FUNCTION TEMPLATES
// Add two values with matching types
template <typename T>
auto add(T x, T y)
{
    return x + y;
}

// Add two values with non-matching types
// As of C++20 we could also use auto add(auto x, auto y)
template <typename T, typename U>
auto add(T x, U y)
{
    return x + y;
}

// Add three values with any type
// As of C++20 we could also use auto add(auto x, auto y, auto z)
template <typename T, typename U, typename V>
auto add(T x, U y, V z)
{
    return x + y + z;
}

int main()
{
    std::cout << add(1.2, 3.4) << '\n'; // instantiates and calls add<double>()
    std::cout << add(5.6, 7) << '\n';   // instantiates and calls add<double, int>()
    std::cout << add(8, 9, 10) << '\n'; // instantiates and calls add<int, int, int>()

    return 0;
}
