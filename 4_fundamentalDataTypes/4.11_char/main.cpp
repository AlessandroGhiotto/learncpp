#include <iostream>

int main0()
{
    char ch1{'a'};            // (preferred)
    std::cout << ch1 << '\n'; // cout prints character 'a'

    char ch2{98};             // code point for 'b' (not preferred)
    std::cout << ch2 << '\n'; // cout prints a character ('b')
    std::cout << "c\n";

    // don't mix character numbers ('9') with integer numbers (9)
    char ch3{'9'};
    std::cout << ch3 << "\n\n";

    // char input
    char ch{};
    std::cout << "Input a keyboard character: ";
    std::cin >> ch; // this ignores the whitespaces (discarded)
    // std::cin.get(ch);  // this allows to extract also the whitespaces
    std::cout << "You entered: " << ch << '\n';

    // we are going to use this if we input more than one char
    // Note: The following cin doesn't ask the user for input, it grabs queued input!
    std::cin >> ch; // ch = 'b', "cd" is left queued.
    std::cout << "You entered: " << ch << '\n';

    return 0;
}

int main()
{
    // special characters
    std::cout << "\"This is quoted text\"\n";
    std::cout << "This string contains a single backslash \\\n";
    std::cout << "6F in hex is char '\x6F'\n";

    // don't use multicharacter literals!!!
    // int x{5};
    // std::cout << "The value of x is " << x << '!\n'; // luckily this gives as warnings
    return 0;
}
