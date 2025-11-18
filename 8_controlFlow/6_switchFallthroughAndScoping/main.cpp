#include <iostream>

bool isVowel(char c)
{
    // return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
    //         c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');

    // sequential case labels works as "or"
    switch (c)
    {
    case 'a': // if c is 'a'
    case 'e': // or if c is 'e'
    case 'i': // or if c is 'i'
    case 'o': // or if c is 'o'
    case 'u': // or if c is 'u'
    case 'A': // or if c is 'A'
    case 'E': // or if c is 'E'
    case 'I': // or if c is 'I'
    case 'O': // or if c is 'O'
    case 'U': // or if c is 'U'
        return true;
    default:
        return false;
    }
}

int main0()
{
#if 0
    // we are going to get warnings for this
    switch (2)
    {
    case 1:                     // Does not match
        std::cout << 1 << '\n'; // Skipped
    case 2:                     // Match!
        std::cout << 2 << '\n'; // Execution begins here
        // HERE WE HAVE NO RETURN OR BREAK!!
    case 3:
        std::cout << 3 << '\n'; // This is also executed
    case 4:
        std::cout << 4 << '\n'; // This is also executed
    default:
        std::cout << 5 << '\n'; // This is also executed
    }
#endif

    // we can make intentional uses of the fallthrough
    switch (2)
    {
    case 1:
        std::cout << 1 << '\n';
        break;
    case 2:
        std::cout << 2 << '\n'; // Execution begins here
        [[fallthrough]];        // intentional fallthrough -- note the semicolon to indicate the null statement
    case 3:
        std::cout << 3 << '\n'; // This is also executed
        break;
    }

    return 0;
}

//////////////////7
#if 0
switch (1)
{
    int a;    // okay: definition is allowed before the case labels
    int b{5}; // illegal: initialization is not allowed before the case labels

case 1:
    int y; // okay but bad practice: definition is allowed within a case
    y = 4; // okay: assignment is allowed
    break;

case 2:
    int z{4}; // illegal: initialization is not allowed if subsequent cases exist
    y = 5;    // okay: y was declared above, so we can use it here too
    break;

case 3:
    break;
}
#endif

////////////////
// EXERCISE
#include <iostream>

int calculate(int x, char op, int y)
{
    switch (op)
    {
    case '+':
        return x + y;
    case '-':
        return x - y;
    case '*':
        return x * y;
    case '/':
        return x / y;
    case '%':
        return x % y;
    default:
        std::cout << "An invalid operator was passed\n";
        return -1;
    }
}
int getNum()
{
    std::cout << "Enter an integer: ";
    int n{};
    std::cin >> n;
    return n;
}
char getOp()
{
    std::cout << "Enter an operator (+, -, *, /, or %): ";
    char op{};
    std::cin >> op;
    return op;
}
int main()
{
    int x{getNum()};
    char op{getOp()};
    int y{getNum()};

    // We'll call calculate first so an invalid operator prints an error message on its own line
    int result{calculate(x, op, y)};
    std::cout << x << ' ' << op << ' ' << y << " is " << result << '\n';
    return 0;
}
