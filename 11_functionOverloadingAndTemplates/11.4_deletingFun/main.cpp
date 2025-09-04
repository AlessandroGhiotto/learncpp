#include <iostream>

void printInt(int x)
{
    std::cout << x << '\n';
}

void printInt(char) = delete; // calls to this function will halt compilation
void printInt(bool) = delete; // calls to this function will halt compilation

int main()
{
    printInt(97); // okay

#if 0
    printInt('a');  // compile error: function deleted
    printInt(true); // compile error: function deleted

    printInt(5.0);  // compile error: ambiguous match
#endif

    return 0;
}

///////////////////////////////////////////////////////////////
/// TEMPLATES: avoid all non-matching types
// This function will take precedence for arguments of type int
void printInt2(int x)
{
    std::cout << x << '\n';
}

// This function template will take precedence for arguments of other types
// Since this function template is deleted, calls to it will halt compilation
template <typename T>
void printInt2(T x) = delete;

int main2()
{
    printInt2(97); // okay
    // printInt2('a');  // compile error
    // printInt2(true); // compile error

    return 0;
}
