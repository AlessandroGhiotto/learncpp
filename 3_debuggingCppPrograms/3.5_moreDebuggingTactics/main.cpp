#include <iostream>

// just need to comment this out to disable debugging
#define ENABLE_DEBUG

int getUserInput()
{
#ifdef ENABLE_DEBUG
    std::cerr << "Beginning getUserInput()\n";
#endif
    std::cout << "Enter a number: ";
    int x{};
    std::cin >> x;
    return x;
}

int main()
{
#ifdef ENABLE_DEBUG
    std::cerr << "Beginning main()\n";
#endif
    int x{getUserInput()};
    std::cout << "You entered: " << x << '\n';

    return 0;
}

////////////////////////////////////////
// PLOG
#if 0
#include <plog/Log.h> // Step 1: include the logger headers
#include <plog/Initializers/RollingFileInitializer.h>
// #include <plog/Log.h> /
// #include <plog/Initializers/RollingFileInitializer.h>

int getUserInput()
{
    PLOGD << "getUserInput() called"; // PLOGD is defined by the plog library

    std::cout << "Enter a number: ";
    int x{};
    std::cin >> x;
    return x;
}

int main()
{
    plog::init(plog::debug, "Logfile.txt"); // Step 2: initialize the logger

    PLOGD << "main() called"; // Step 3: Output to the log as if you were writing to the console

    int x{getUserInput()};
    std::cout << "You entered: " << x << '\n';

    return 0;
}

#endif
