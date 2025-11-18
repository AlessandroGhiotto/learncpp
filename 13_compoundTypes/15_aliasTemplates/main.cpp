#include <iostream>

template <typename T, typename U>
struct Pair
{
    T first {};
    U second {};
};

template <typename T, typename U>
void print(const Pair<T, U>& p)
{
    std::cout << p.first << ' ' << p.second << '\n';
}

template <typename T>
using Coord = Pair<T, T>;

int main()
{
    using Point = Pair<int, int>;
    Point p { 1, 2 }; // compiler replaces this with Pair<int>

    print(p);

    Coord<int> p1 { 1, 2 }; // Pre C++-20: We must explicitly specify all type template argument
    Coord p2 { 1, 2 };      // In C++20, we can use alias template deduction to deduce the template arguments in cases where CTAD works

    print(p1);
    print(p2);
    return 0;
}
