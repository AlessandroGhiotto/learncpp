#include <iostream>
#include <string>
#include <string_view> // C++17

// the argument passed to the function is a read-only access to the og variable
void printSV(std::string_view string)
{
    std::cout << string << "\n";
}
int main0()
{
    // read only access to the c-style string
    std::string_view sv{"Hi motherf*****!"};
    printSV(sv);

    std::string_view s1{"Hello, world!"}; // initialize with C-style string literal
    std::cout << s1 << '\n';

    std::string s{"Hello, world!"};
    std::string_view s2{s}; // initialize with std::string
    std::cout << s2 << '\n';

    std::string_view s3{s2}; // initialize with std::string_view
    std::cout << s3 << '\n';

    return 0;
}

///////////////////////////////////////////////7
// std::string_view to std::string conversion
void printString(std::string str)
{
    std::cout << str << '\n';
}

int main1()
{
    std::string_view sv{"Hello, world!"};

    // printString(sv);   // compile error: won't implicitly convert std::string_view to a std::string

    std::string s{sv}; // okay: we can create std::string using std::string_view initializer
    printString(s);    // and call the function with the std::string

    printString(static_cast<std::string>(sv)); // okay: we can explicitly cast a std::string_view to a std::string

    return 0;
}

//////////////////////////////////////7
// assigning a new string to a std::string_view cause the object to look at the new string
// it doesn't modify the og one.
int main()
{
    std::string name{"aleee"};
    std::string_view sv{name}; // sv is now viewing name
    std::cout << sv << '\n';   // prints aleee

    sv = "John";             // sv is now viewing "John" (does not change name)
    std::cout << sv << '\n'; // prints John

    std::cout << name << '\n'; // prints Alex

    return 0;
}

// std::string_view has support for constexpr
int main3()
{
    constexpr std::string_view s{"Hello, world!"}; // s is a string symbolic constant
    std::cout << s << '\n';                        // s will be replaced with "Hello, world!" at compile-time

    return 0;
}
