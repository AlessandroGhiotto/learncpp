#include <iostream>
#include <string_view>

std::string_view getQuantityPhrase(int nApples)
{
    if (nApples < 0)
        return "negative";
    if (nApples == 0)
        return "no";
    if (nApples == 1)
        return "a single";
    if (nApples == 2)
        return "a couple of";
    if (nApples == 3)
        return "a few";
    else // if (nApples > 3)
        return "many";
}

std::string_view getApplesPluralized(int nApples)
{
    // if (nApples == 1)
    //     return "apple";
    // else
    //     return "apples";
    return (nApples == 1) ? "apple" : "apples";
}

int main()
{
    constexpr int maryApples{3};
    std::cout << "Mary has " << getQuantityPhrase(maryApples) << ' ' << getApplesPluralized(maryApples) << ".\n";

    std::cout << "How many apples do you have? ";
    int numApples{};
    std::cin >> numApples;

    std::cout << "You have " << getQuantityPhrase(numApples) << ' ' << getApplesPluralized(numApples) << ".\n";

    return 0;
}
