#include <iostream>

class Accumulator
{
  private:
    int m_value { 0 };

  public:
    void add(int value) { m_value += value; }

    // Here is the friend declaration that makes non-member function void print(const Accumulator& accumulator) a friend of Accumulator
    friend void print(const Accumulator& accumulator);
};

void print(const Accumulator& accumulator)
{
    // Because print() is a friend of Accumulator
    // it can access the private members of Accumulator
    std::cout << accumulator.m_value;
}

#include <iostream>

class Value
{
  private:
    int m_value {};

  public:
    explicit Value(int v) : m_value { v } {}

    bool isEqual(const Value& v) const;
    friend bool isEqual(const Value& v1, const Value& v2);
};

bool Value::isEqual(const Value& v) const
{
    return m_value == v.m_value;
}

bool isEqual(const Value& v1, const Value& v2)
{
    return v1.m_value == v2.m_value;
}

int main()
{
    Accumulator acc {};
    acc.add(5); // add 5 to the accumulator

    print(acc); // call the print() non-member function

    Value v1 { 5 };
    Value v2 { 6 };

    std::cout << v1.isEqual(v2) << '\n';
    std::cout << isEqual(v1, v2) << '\n';

    return 0;
}
