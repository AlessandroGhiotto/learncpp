#include <iostream>

// How many tests would the following function need to minimally validate that it works?
bool isLowerVowel(char c, bool yIsVowel)
{
    switch (c)
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        return true;
    case 'y':
        return yIsVowel;
    default:
        return false;
    }
}

// 4
int testIsLowerVowel()
{
    if (!isLowerVowel('a', true))
        return 1;
    if (isLowerVowel('z', true))
        return 2;
    if (!isLowerVowel('y', true))
        return 3;
    if (isLowerVowel('y', false))
        return 4;

    return 0;
}

int main()
{
    int codeN{testIsLowerVowel()};
    if (codeN == 0)
        std::cout << "Succes!\n";
    else
        std::cout << "Test exit with code" << codeN << '\n';

    return 0;
}
