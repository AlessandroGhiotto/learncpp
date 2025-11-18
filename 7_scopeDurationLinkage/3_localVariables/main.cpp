#include <iostream>

// put everything inside the #if 0, because this are just examples
#if 0
int max(int x, int y) // x and y enter scope here
{
    // assign the greater of x or y to max
    int max{(x > y) ? x : y}; // max enters scope here

    return max;
} // max, y, and x leave scope here

// variables in the same scope must be unique
void someFunction(int x)
{
    int x{}; // compilation failure due to name collision with function parameter
}

int main0()
{
    int i{5};      // i enters scope here // i created and initialized here
    double d{4.0}; // d enters scope here // d created and initialized here

    return 0;
} // d and i go out of scope here // d and i destroyed here

int main1()
{ // outer block

    int x{5}; // x enters scope and is created here

    {             // nested block
        int y{7}; // y enters scope and is created here

        // x and y are both in scope here
        std::cout << x << " + " << y << " = " << x + y << '\n';
    } // y goes out of scope and is destroyed here

    // y can not be used here because it is out of scope in this block

    return 0;
} // x goes out of scope and is destroyed here

// Local variables have no linkage
int main2()
{
    int x{2}; // local variable, no linkage
    {
        int x{3}; // this declaration of x refers to a different object than the previous x
    }
    return 0;
}

// variables should be defined in the most limited scope
int main()
{
    // do not define y here
    {
        // y is only used inside this block, so define it here
        int y{5};
        std::cout << y << '\n';
    }
    // otherwise y could still be used here, where it's not needed

    return 0;
}
#endif

// EXERCISE
int main()
{
    std::cout << "Enter an integer: ";
    int smaller{}; // smaller initialized here
    std::cin >> smaller;

    std::cout << "Enter a larger integer: ";
    int larger{}; // larger initialized here
    std::cin >> larger;

    // if user did it wrong, swap them
    if (smaller >= larger)
    {
        std::cout << "Swapping the values\n";
        int temp{larger}; // temp initialized here
        larger = smaller;
        smaller = temp;

        // THIS IS THE SAME AS: std::swap(larger, smaller);

    } // temp dies here

    std::cout << "The smaller value is " << smaller << '\n';
    std::cout << "The larger value is " << larger << '\n';

    return 0;
} // smaller and larger die here
