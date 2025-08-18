// defining signed integers:
short s; // prefer "short" instead of "short int"
int i;
long l;       // prefer "long" instead of "long int"
long long ll; // prefer "long long" instead of "long long int"

// we can also us the int suffix or signed prefix:
// (this is just redundant - avoid it)
signed long sl;
long int li;
signed long int sli;

#include <iostream>

int main()
{
    // assume 4 byte integers
    int x{2'147'483'647}; // the maximum value of a 4-byte signed integer
    std::cout << x << '\n';

    x = x + 1; // integer overflow, undefined behavior
    std::cout << x << "\n\n";

    std::cout << "20 / 4 = " << 20 / 4 << '\n';
    std::cout << "8 / 5 = " << 8 / 5 << '\n';
    std::cout << "-8 / 5 = " << -8 / 5 << '\n';

    return 0;
}
