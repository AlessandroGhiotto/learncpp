#include <iostream>

struct Pair // Pair is an aggregate
{
    int m_x {};
    int m_y {};

    constexpr int greater() const
    {
        return (m_x > m_y ? m_x : m_y);
    }
};

class PairC
{
  private:
    int m_x {};
    int m_y {};

  public:
    constexpr PairC(int x, int y) : m_x { x }, m_y { y } {} // now constexpr

    constexpr int greater() const
    {
        return (m_x > m_y ? m_x : m_y);
    }
};

int main()
{
    constexpr Pair p { 5, 6 };
    std::cout << p.greater() << '\n';

    constexpr int g { p.greater() };
    std::cout << g << '\n';

    constexpr PairC t { 5, 6 };       // now constexpr
    std::cout << t.greater() << '\n'; // t.greater() evaluates at runtime or compile-time

    constexpr int s { t.greater() }; // t.greater() must evaluate at compile-time
    std::cout << s << '\n';

    return 0;
}
