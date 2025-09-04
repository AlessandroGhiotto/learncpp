#include <iostream>

// what if we want too define a max function for many other types
// the function body is the same... we should need to overload with all the types that we need...
#if 0
int max(int x, int y)
{
    return (x < y) ? y : x;
}
#endif

template <typename T> // this is the template parameter declaration defining T as a type template parameter
T max(T x, T y)       // this is the function template definition for max<T>
{
    return (x < y) ? y : x;
}

int main()
{
    std::cout << "max(5, 6): " << max(5, 6) << "\n";
    std::cout << "max(5.0, 6.0): " << max(5.0, 6.0) << "\n";
    std::cout << "max('5', '6'): " << max('5', '6') << "\n";
}
