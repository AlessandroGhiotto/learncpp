// this gives an error (the function is going to be imported twice!)
#include "square.h"
// #include "wave.h"

// since the two includes are equivalent to the following:
#if 0
int getSquareSides()  // from square.h
{
    return 4;
}

int getSquareSides() // from wave.h (via square.h)
{
    return 4;
}
#endif

int main()
{
    return 0;
}
