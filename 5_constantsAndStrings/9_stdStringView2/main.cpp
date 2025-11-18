#include <iostream>
#include <string>
#include <string_view>

// very nice use for std::string_view
// we don't make expensive copy of the arguments
void printSV(std::string_view str) // now a std::string_view, creates a view of the argument
{
    std::cout << str << '\n';
}

int main0()
{
    printSV("Hello, world!"); // call with C-style string literal

    std::string s2{"Hello, world!"};
    printSV(s2); // call with std::string

    std::string_view s3{s2};
    printSV(s3); // call with std::string_view

    s2 = "Siuuumm!";
    printSV(s3); // UNDEFINED BEHAVIOR, s2 has been modified

    return 0;
}

///////////////////////////////////////////
// ATTENTION TO MISUSES OF STRING_VIEW
std::string getName()
{
    std::string s{"ale ghi"};
    return s;
}

int main1()
{
    std::string_view sv{};

    {                                      // create a nested block
        std::string s{"Aiuto poliziaaa!"}; // create a std::string local to this nested block
        sv = s;                            // sv is now viewing s
    } // s is destroyed here, so sv is now viewing an invalid string

    std::cout << sv << '\n'; // undefined behavior

    // here a similar case
    std::string_view name{getName()}; // name initialized with return value of function
    std::cout << name << '\n';        // undefined behavior

    // another case
    using namespace std::string_literals;
    std::string_view x{"il don di torino"s}; // "Alex"s creates a temporary std::string, this is going to be destroyed
    std::cout << x << '\n';                  // undefined behavior

    // and again
    std::string y{"Hello, world!"};
    std::string_view sv_y{y};  // sv is now viewing s
    y = "Hello, a!";           // modifies s, which invalidates sv (s is still valid)
    std::cout << sv_y << '\n'; // undefined behavior
    sv_y = y;
    std::cout << sv_y << '\n'; // RIVALIDATE the string_view object

    return 0;
}

/////////////////////////////////
// Be careful returning a std::string_view
std::string_view getBoolName1(bool b)
{
    std::string t{"true"};  // local variable
    std::string f{"false"}; // local variable
    if (b)
        return t; // return a std::string_view viewing t
    return f;     // return a std::string_view viewing f
} // t and f are destroyed at the end of the function

std::string_view getBoolName2(bool b)
{
    if (b)
        return "true"; // return a std::string_view viewing "true"

    return "false"; // return a std::string_view viewing "false"
} // "true" and "false" are not destroyed at the end of the function

std::string_view firstAlphabetical(std::string_view s1, std::string_view s2)
{
    if (s1 < s2)
        return s1;
    return s2;
}

int main2()
{
    // Problem: returning a view on local variable (which is going to be destroied)
    std::cout << getBoolName1(true) << ' ' << getBoolName1(false) << '\n'; // undefined behavior
    // OKAY: returning a view on a c-style string (they exists for the entire program)
    std::cout << getBoolName2(true) << ' ' << getBoolName2(false) << '\n'; // ok
    // OKAY: returning arguments
    std::string a{"World"};
    std::string b{"Hello"};
    std::cout << firstAlphabetical(a, b) << '\n'; // prints "Hello"

    return 0;
}

///////////////////////////////////
// view modification functions
int main()
{
    std::string_view str{"Peach"};
    std::cout << str << '\n';

    // Remove 1 character from the left side of the view
    str.remove_prefix(1);
    std::cout << str << '\n';

    // Remove 2 characters from the right side of the view
    str.remove_suffix(2);
    std::cout << str << '\n';

    str = "Peach"; // reset the view
    std::cout << str << '\n';

    return 0;
}
