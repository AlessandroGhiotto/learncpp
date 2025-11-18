#include <iostream>

void foo(int x)
{
    std::cout << "foo(int) " << x << "\n";
}
void foo(double x)
{
    std::cout << "foo(double) " << x << "\n";
}
void foo(std::string x)
{
    std::cout << "foo(std::string) " << x << "\n";
}

class X // this defines a new type called X
{
public:
    operator int() { return 0; } // Here's a user-defined conversion from X to int
};

void bar(const int x)
{
    std::cout << "bar(const int) " << x << "\n";
}
void bar(const double &x) // double& is a reference to a double
{
    std::cout << "bar(const double&) " << x << "\n";
}
// if we add this we get ambiguous matches with bar(const int)
// void bar(const int &x) // int& is a reference to a int
// {
//     std::cout << "bar(const int&) " << x << "\n";
// }

void foobar(unsigned int x)
{
    std::cout << "foobar(unsigned int) " << x << "\n";
}

void foobar(float x)
{
    std::cout << "foobar(float) " << x << "\n";
}

int main()
{
    /// 1a. EXACT MATCH
    foo(0);   // exact match with foo(int)
    foo(3.4); // exact match with foo(double)
    std::cout << "-------------------\n";

    /// 1b. TRIVIAL CONVERSION
    bar(1);   // trivially converted from int to const int
    bar(2.3); // trivially converted from double to const double& (non-ref to ref conversion)
    std::cout << "-------------------\n";

    /// 2. NUMERIC PROMOTIONS
    foo('a');  // promoted to match foo(int)
    foo(true); // promoted to match foo(int)
    foo(4.5f); // promoted to match foo(double)
    std::cout << "-------------------\n";

    /// 3. NUMERIC CONVERSIONS
    foo('a'); // 'a' converted to match foo(double) (even though foo(std::string) exists)
    std::cout << "-------------------\n";

    /// 4. USER DEFINED CONVERSIONS
    X x;    // Here, we're creating an object of type X (named x)
    foo(x); // x is converted to type int using the user-defined conversion from X to int
    std::cout << "-------------------\n";

    /// AMBIGUOUS MATCHES
    // foo(5L); // 5L is type long -> can be converted both to int and double (at the same step)
    // foobar(0);       // int can be numerically converted to unsigned int or to float
    // foobar(3.14159); // double can be numerically converted to unsigned int or to float

    /// Resolving ambiguities:
    int y{0};
    foobar(static_cast<unsigned int>(y)); // will call foobar(unsigned int)
    foobar(0u);                           // will call foobar(unsigned int) since 'u' suffix is unsigned int, so this is now an exact match

    return 0;
}
