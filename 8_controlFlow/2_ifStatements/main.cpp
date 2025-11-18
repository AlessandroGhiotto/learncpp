#include <iostream>

void ifelse(bool a, bool b, bool c)
{
    if (a) // always evaluates
        std::cout << "a";
    else if (b) // only evaluates when prior if-statement condition is false
        std::cout << "b";
    else if (c) // only evaluates when prior if-statement condition is false
        std::cout << "c";
    std::cout << '\n';
}

void ifif(bool a, bool b, bool c)
{
    if (a) // always evaluates
        std::cout << "a";
    if (b) // always evaluates
        std::cout << "b";
    if (c) // always evaluates
        std::cout << "c";
    std::cout << '\n';
}

char getFirstMatchingChar(bool a, bool b, bool c)
{
#if 0
    if (a) // always evaluates
        return 'a';
    else if (b) // only evaluates when prior if-statement condition is false
        return 'b';
    else if (c) // only evaluates when prior if-statement condition is false
        return 'c';
#endif

    // using the elfe doens't provide any additional value when each statemetn has a return
    if (a)          // always evaluates
        return 'a'; // returns when if-statement is true
    if (b)          // only evaluates when prior if-statement condition is false
        return 'b'; // returns when if-statement is true
    if (c)          // only evaluates when prior if-statement condition is false
        return 'c'; // returns when if-statement is true

    return 0;
}

int main()
{
    ifelse(false, true, true);
    ifif(false, true, true);

    return 0;
}
