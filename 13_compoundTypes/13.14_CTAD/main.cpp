#include <utility> // for std::pair

int main0()
{
    std::pair<int, int> p1 { 1, 2 }; // explicitly specify class template std::pair<int, int> (C++11 onward)
    std::pair p2 { 1, 2 };           // CTAD used to deduce std::pair<int, int> from the initializers (C++17)

    // std::pair<> p1 { 1, 2 };    // error: too few template arguments, both arguments not deduced
    // std::pair<int> p2 { 3, 4 }; // error: too few template arguments, second argument not deduced

    std::pair p3 { 3.4f, 5.6f }; // deduced to pair<float, float>
    std::pair p4 { 1u, 2u };     // deduced to pair<unsigned int, unsigned int>
    return 0;
}

template <typename T = int, typename U = int>
struct Pair
{
    T first {};
    U second {};
};

// Here's a deduction guide for our Pair (needed in C++17 only)
// Pair objects initialized with arguments of type T and U should deduce to Pair<T, U>
template <typename T, typename U>
Pair(T, U) -> Pair<T, U>;

int main()
{
    Pair<int, int> p1 { 1, 2 }; // explicitly specify class template Pair<int, int> (C++11 onward)
    Pair p2 { 1, 2 };           // CTAD used to deduce Pair<int, int> from the initializers (C++17)

    return 0;
}

#if 0
// CTAD doesn't work with non-static member initialization
struct Foo
{
    std::pair<int, int> p1{ 1, 2 }; // ok, template arguments explicitly specified
    std::pair p2{ 1, 2 };           // compile error, CTAD can't be used in this context
};

// CTAD doesn’t work with function parameters
void print(std::pair p) // compile error, CTAD can't be used here
{
    std::cout << p.first << ' ' << p.second << '\n';
}
// We dhould use a template
template <typename T, typename U>
void print(std::pair<T, U> p)
#endif
