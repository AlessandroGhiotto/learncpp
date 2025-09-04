#include <iostream>

template <int N> // declare a non-type template parameter of type int named N
void print1()
{
    std::cout << N << '\n'; // use value of N here
}

int main1()
{
    print1<5>(); // 5 is our non-type template argument

    return 0;
}

template <auto N> // deduce non-type template parameter from template argument
void print2()
{
    std::cout << N << '\n';
}

int main2()
{
    print2<5>();   // N deduced as int `5`
    print2<'c'>(); // N deduced as char `c`

    return 0;
}

///////////////////////////////////
// EXERCISE
template <int N>
constexpr int factorial()
{
    // we can use static assert since N is a constexpr value
    static_assert(N >= 0);

    int res{1};
    for (int i{2}; i <= N; ++i)
    {
        res *= i;
    }

    return res;
}

int main()
{
    static_assert(factorial<0>() == 1);
    static_assert(factorial<3>() == 6);
    static_assert(factorial<5>() == 120);

    // factorial<-3>(); // should fail to compile

    return 0;
}
