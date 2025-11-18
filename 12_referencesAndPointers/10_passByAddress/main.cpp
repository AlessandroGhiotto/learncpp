#include <iostream>
#include <string>

void printByValue(std::string val) // The function parameter is a copy of str
{
    std::cout << val << '\n'; // print the value via the copy
}

void printByReference(const std::string &ref) // The function parameter is a
                                              // reference that binds to str
{
    std::cout << ref << '\n'; // print the value via the reference
}

void printByAddress(const std::string *ptr) // The function parameter is a pointer that holds the address of str
{
    std::cout << *ptr << '\n'; // print the value via the dereferenced pointer
}

void changeValue(int *ptr) // note: ptr is a pointer to non-const in this example
{
    *ptr = 6; // change the value to 6
}

void print(int *ptr)
{
    if (!ptr) // if ptr is a null pointer, early return back to the caller
        return;

    // if we reached this point, we can assume ptr is valid
    // so no more testing or nesting required

    std::cout << *ptr << '\n';
}

int main()
{
    std::string str { "Hello, world!" };

    printByValue(str);     // pass str by value, makes a copy of str
    printByReference(str); // pass str by reference, does not make a copy of str
    printByAddress(&str);  // pass str by address, does not make a copy of str

    int x { 5 };
    std::cout << "x = " << x << '\n';
    changeValue(&x); // we're passing the address of x to the function
    std::cout << "x = " << x << '\n';

    print(&x);
    print(nullptr);

    // Here why passing by referebce is better
    // printByValue(5); // valid (but makes a copy)
    // printByReference(5); // valid (because the parameter is a const
    // reference) printByAddress(&5); // error: can't take address of r-value

    return 0;
}
