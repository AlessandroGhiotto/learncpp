#include <iostream>
#include <utility>

// template <typename T>
// struct Pair
// {
//     T first {};
//     T second {};
// };

template <typename T, typename U>
struct Pair
{
    T first {};
    U second {};
};

struct Point
{
    int first {};
    int second {};
};

template <typename T>
constexpr T max(Pair<T, T> p)
{
    return ((p.first > p.second) ? p.first : p.second);
}

template <typename T>
void print(T p) // type template parameter will match anything
{
    // will only compile if type has first and second members
    std::cout << "[ " << p.first << ", " << p.second << " ]" << std::endl;
}

int main()
{
    Pair<int, int> p1 { 5, 6 }; // instantiates Pair<int, int> and creates object p1
    std::cout << p1.first << ' ' << p1.second << '\n';

    Pair<double, int> p2 { 3.4, 0 }; // instantiates Pair<double, int> and creates object p2
    std::cout << p2.first << ' ' << p2.second << '\n';

    Pair<int, int> p3 { 7, 9 }; // creates object p3 using prior definition for Pair<int>
    std::cout << p3.first << ' ' << p3.second << " max: " << max(p3) << '\n';

    Point point { 2, 3 };
    print(point);

    std::pair<int, float> stdPair { 1, 1.2 };
    print(stdPair);
    return 0;
}
