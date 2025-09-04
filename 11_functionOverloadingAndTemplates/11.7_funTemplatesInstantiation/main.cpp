#include <iostream>

template <typename T>
T max(T x, T y)
{
    return (x < y) ? y : x;
}

int main0()
{
    std::cout << max<int>(1, 2) << '\n';    // instantiates and calls function max<int>(int, int)
    std::cout << max<int>(4, 3) << '\n';    // calls already instantiated function max<int>(int, int)
    std::cout << max<double>(1, 2) << '\n'; // instantiates and calls function max<double>(double, double)
    // 1,2 are going to be implicitly converted to double in this case (we could also supply double literals)

    return 0;
}

/// This is going to generate thw following function instance:

// a declaration for our function template (we don't need the definition any more)
#if 0
template <typename T>
T max(T x, T y);

template<>
int max<int>(int x, int y) // the generated function max<int>(int, int)
{
    return (x < y) ? y : x;
}

template<>
double max<double>(double x, double y) // the generated function max<double>(double, double)
{
    return (x < y) ? y : x;
}
#endif

/// FUNCTION TEMPLATE VS NORMAL FUN
// This function template can handle many types, so its implementation is generic
template <typename T>
void print(T x)
{
    std::cout << x; // print T however it normally prints
}

// This function only needs to consider how to print a bool, so it can specialize how it handles
// printing of a bool
void print(bool x)
{
    std::cout << std::boolalpha << x; // print bool as true or false, not 1 or 0
}

template <typename T>
T addOne(T x)
{
    return x + 1;
}

int main1()
{
    print<bool>(true); // calls print<bool>(bool) -- prints 1
    std::cout << '\n';

    print<>(true); // deduces print<bool>(bool) (non-template functions not considered) -- prints 1
    std::cout << '\n';

    print(true); // calls print(bool) -- prints true
    std::cout << '\n';

    /// Instantiated functions may not run:
    // std::string hello{"Hello, world!"};
    // std::cout << addOne(hello) << '\n';
    /// Or may not make sense semantically
    std::cout << addOne("hello") << '\n'; // C-style literal

    return 0;
}

/// STATIC LOCAL VARIABLES ARE DIFFERENT FOR EACH INSTANTIATED FUNCTION
// Here's a function template with a static local variable that is modified
template <typename T>
void printIDAndValue(T value)
{
    static int id{0};
    std::cout << ++id << ") " << value << '\n';
}

int main()
{
    printIDAndValue(12);
    printIDAndValue(13);

    printIDAndValue(14.5); // we get id == 1 here

    return 0;
}
