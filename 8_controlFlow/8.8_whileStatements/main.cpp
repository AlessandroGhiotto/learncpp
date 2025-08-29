#include <iostream>

void printFirstN(int N)
{
    int count{1};
    while (count <= N)
    {
        std::cout << count++ << ' ';
    }

// unintenional infinite loop
#if 0
    while (count <= 10); // note the semicolon here
    {
        std::cout << count++ << ' ';
    }
#endif

    std::cout << "Done\n";
}

int infLoop()
{
    while (true) // infinite loop
    {
        std::cout << "Loop again (y/n)? ";
        char c{};
        std::cin >> c;

        if (c == 'n')
            return 0;
    }
}

// Do something every N iterations
void print50()
{
    int count{1};
    while (count <= 50)
    {
        // print the number (pad numbers under 10 with a leading 0 for formatting purposes)
        if (count < 10)
        {
            std::cout << '0';
        }

        std::cout << count << ' ';

        // if the loop variable is divisible by 10, print a newline
        if (count % 10 == 0)
        {
            std::cout << '\n';
        }

        // increment the loop counter
        ++count;
    }
}

int main0()
{
    printFirstN(5);
    // this is not going to print anything
    printFirstN(-2);
    std::cout << "----------------\n";

    // infLoop();
    // std::cout << "----------------\n";

    print50();
    return 0;
}

//////////////////////////////////////////////
// NESTED LOOPS
int main1()
{
    // outer loops between 1 and 5
    int outer{1};
    while (outer <= 5)
    {
        // For each iteration of the outer loop, the code in the body of the loop executes once

        // inner loops between 1 and outer
        // note: inner will be created and destroyed at the end of the block
        int inner{1};
        while (inner <= outer)
        {
            std::cout << inner++ << ' ';
        }

        // print a newline at the end of each row
        std::cout << '\n';
        ++outer;
    } // inner destroyed here

    return 0;
}

///////////////////////////////////////////
// EXERCISES
// 1) Write a program that prints out the letters a through z along with their ASCII codes. Use a loop variable of type char
void printLetters()
{
    char c{'a'};
    while (c <= 'z')
    {
        std::cout << c << ": " << static_cast<int>(c) << '\n';
        ++c;
    }
}

// 2) Invert the nested loops example
void printInvNestedLoop()
{
    int outer{5};
    while (outer <= 5)
    {
        int inner{outer};
        while (inner >= 1)
        {
            std::cout << inner-- << ' ';
        }

        std::cout << '\n';
        --outer;
    }
}

// 3) nested loop again
void printNestedLoopSpaced()
{
    int outer{1};
    while (outer <= 5)
    {
        int inner{1};
        while (inner <= 5 - outer)
        {
            std::cout << "  ";
            inner++;
        }

        inner = 1;
        while (inner <= outer)
        {
            std::cout << inner++ << ' ';
        }

        std::cout << '\n';
        ++outer;
    }
}

int main()
{
    // printLetters(); // 1
    // printInvNestedLoop(); // 2
    printNestedLoopSpaced(); // 3

    return 0;
}
