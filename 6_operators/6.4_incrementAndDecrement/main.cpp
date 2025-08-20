#include <iostream>

int main()
{
    // PREFIX VERSION
    // -> increment/decrement, and then return it
    int x{5};
    int y{++x}; // x is incremented to 6, x is evaluated to the value 6, and 6 is assigned to y

    std::cout << x << ' ' << y << '\n';

    // PSOTFIX VERSION
    // -> copy x, then increment/decrement the og x, but then return the copy
    int a{5};
    int b{a++}; // a is incremented to 6, copy of original a is evaluated to the value 5, and 5 is assigned to b

    std::cout << a << ' ' << b << '\n';
    std::cout << "----------------\n";

    int s{5};
    int t{5};
    std::cout << s << ' ' << t << '\n';
    std::cout << ++s << ' ' << --t << '\n'; // prefix
    std::cout << s << ' ' << t << '\n';
    std::cout << s++ << ' ' << t-- << '\n'; // postfix
    std::cout << s << ' ' << t << '\n';
    std::cout << "----------------\n";

#if 0
    // side effects and evaluation issues
    int z{5};
    std::cout << z + (++z) << '\n'; // undefined behavior: is this 5 + 6, or 6 + 6?
    //  It depends on what order your compiler evaluates the function arguments in
    // the compiler warn us: operation on ‘z’ may be undefined
#endif
    return 0;
}
