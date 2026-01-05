#include <ios> // for std::boolalpha
#include <iostream>

template <typename T>
struct PairStruct
{
    T first {};
    T second {};
};

// Here's a deduction guide for our Pair (required in C++17 or older)
// Pair objects initialized with arguments of type T and T should deduce to Pair<T>
// now can be omitted
//
// template <typename T>
// Pair(T, T) -> Pair<T>;

template <typename T>
class Pair
{
  private:
    T m_first {};
    T m_second {};

  public:
    Pair(T first, T second)
        : m_first { first }, m_second { second }
    {
    }

    bool isEqual(const Pair<T>& pair);
};

// When we define a member function outside the class definition,
// we need to resupply a template parameter declaration
template <typename T>
bool Pair<T>::isEqual(const Pair<T>& pair)
{
    return m_first == pair.m_first && m_second == pair.m_second;
}

/// EXERCISE
template <typename XX, typename YY, typename ZZ>
class Triad
{
  private:
    XX m_x {};
    YY m_y {};
    ZZ m_z {};

  public:
    Triad(XX x, YY y, ZZ z)
        : m_x { x }, m_y { y }, m_z { z }
    {
    }

    XX first() const { return m_x; }
    YY second() const { return m_y; }
    ZZ third() const { return m_z; }

    void print() const;
    // {
    //     std::cout << "Triad(" << m_x << ", " << m_y << ", " << m_z << ")";
    // }
};

template <typename XX, typename YY, typename ZZ>
void Triad<XX, YY, ZZ>::print() const
{
    std::cout << "Triad(" << m_x << ", " << m_y << ", " << m_z << ")";
}

int main()
{
    PairStruct<int> p1 { 5, 6 }; // instantiates Pair<int> and creates object p1
    std::cout << p1.first << ' ' << p1.second << '\n';

    PairStruct<double> p2 { 1.2, 3.4 }; // instantiates Pair<double> and creates object p2
    std::cout << p2.first << ' ' << p2.second << '\n';

    PairStruct<double> p3 { 7.8, 9.0 }; // creates object p3 using prior definition for Pair<double>
    std::cout << p3.first << ' ' << p3.second << '\n';

    Pair p4 { 5, 6 }; // uses CTAD to infer type Pair<int>
    std::cout << std::boolalpha << "isEqual(5, 6): " << p4.isEqual(Pair { 5, 6 }) << '\n';
    std::cout << std::boolalpha << "isEqual(5, 7): " << p4.isEqual(Pair { 5, 7 }) << "\n\n";

    Triad<int, int, int> t1 { 1, 2, 3 };
    t1.print();
    std::cout << '\n';
    std::cout << t1.first() << '\n';

    using namespace std::literals::string_literals;
    const Triad t2 { 1, 2.3, "Hello"s };
    t2.print();
    std::cout << '\n';

    return 0;
}
