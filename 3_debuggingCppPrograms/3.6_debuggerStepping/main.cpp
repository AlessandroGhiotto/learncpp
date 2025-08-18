// test integreted debugger
// step into, step over, step out
#include <iostream>
#define DEBUG

void printValue(int value)
{
    std::cout << value << '\n';
}

int main()
{
#ifdef DEBUG
    std::cout << std::unitbuf; // enable automatic flushing for std::cout (for debugging)
#endif
    printValue(5);

    return 0;
}
