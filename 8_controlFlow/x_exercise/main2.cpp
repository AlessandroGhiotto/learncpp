// Make sure that assert triggers even if we compile in release mode
#undef NDEBUG

#include <cassert> // for assert
#include <iostream>
#include <cmath> // for std::sqrt

bool isPrimev1(int x)
{
    if (x == 0 || x == 1)
        return false;
    if (x == 2)
        return true;

    for (int n{2}; n < x; ++n)
    {
        if (x % n == 0)
            return false;
    }

    return true;
}

bool isPrimev2(int x)
{
    if (x == 2)
        return true;
    if (x <= 1 || x % 2 == 0)
        return false;

    // for (int n{3}; n <= std::sqrt(x); n += 2)
    // {
    //     if (x % n == 0)
    //         return false;
    // }

    // n<=sqrt(x), n,x>0 <=> n*2 <= x
    for (int n{3}; n * n <= x; n += 2)
    {
        if (x % n == 0)
            return false;
    }

    return true;
}

bool isPrime(int x)
{
    // return isPrimev1(x);
    return isPrimev2(x);
}

int main2()
{
    assert(!isPrime(0)); // terminate program if isPrime(0) is true
    assert(!isPrime(1));
    assert(isPrime(2)); // terminate program if isPrime(2) is false
    assert(isPrime(3));
    assert(!isPrime(4));
    assert(isPrime(5));
    assert(isPrime(7));
    assert(!isPrime(9));
    assert(isPrime(11));
    assert(isPrime(13));
    assert(!isPrime(15));
    assert(!isPrime(16));
    assert(isPrime(17));
    assert(isPrime(19));
    assert(isPrime(97));
    assert(!isPrime(99));
    assert(isPrime(13417));

    std::cout << "Success!\n";

    return 0;
}
