#include <iostream>

struct Date
{
    int year {};
    int month {};
    int day {};

    void print() const
    {
        std::cout << year << "-" << month << "-" << day << '\n';
    }

    void setYear(int y)
    {
        year = y;
    }
};

void doSomething(const Date& date)
{
    date.print(); // OK: calling a const member function on a const reference
    // date.setYear(2025); // Error: cannot call non-const member function on a const reference
}

struct aStruct
{
    void print() const
    {
        std::cout << "const print\n";
    }

    void print()
    {
        std::cout << "non-const print\n";
    }
};

int main()
{
    const Date date { 2024, 10, 14 }; // const object
    date.print();                     // OK: calling a const member function on a const object

    // date.setYear(2025);            // Error: cannot call non-const member function on a const object

    Date today { 2026, 10, 14 }; // non-const object
    today.setYear(2027);         // OK: calling non-const member function on a non-const object
    today.print();               // OK: calling a const member function on a non-const object

    // const references are treated as const objects
    doSomething(date); // OK: passing const object to function expecting const reference

    // const participate to overloading
    const aStruct x {};
    x.print();
    aStruct y {};
    y.print();
    return 0;
}
