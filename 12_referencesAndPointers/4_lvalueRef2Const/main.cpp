#include <iostream>

int main1()
{
    int x{5};
    const int& ref{x};
    // ref = 3 // not allowed
    x = 3;

    const int y{7};
    const int& refy{y};
    // refy = 10 // not allowed
    // y = 10; // not allowd

    std::cout << ref << refy << "\n";

    // init const lvalue reference with rvalue
    // case 1
    const double& r1{5};     // temporary double initialized with value 5, r1 binds to temporary
    std::cout << r1 << '\n'; // prints 5

    // case 2
    char c{'a'};
    const int& r2{c};        // temporary int initialized with value 'a', r2 binds to temporary
    std::cout << r2 << '\n'; // prints 97 (since r2 is a reference to int)
}

///   WARNING
// We normally assume that a reference is identical to the object it is bound to --
// but this assumption is broken when a reference is bound to a temporary copy of the object or
// a temporary resulting from the conversion of the object instead
int main()
{
    short bombs{1}; // I can has bomb! (note: type is short)

    const int& you{bombs}; // You can has bomb too (note: type is int&)
    --bombs;               // Bomb all gone

    if (you) // You still has?
    {
        std::cout << "Bombs away!  Goodbye, cruel world.\n"; // Para bailar la bomba
    }

    return 0;
}
