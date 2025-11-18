// int main(){
//     int x;
//     int y, z;

//     return 0;
// }

// epico ti segna quelle che non usi
// error: unused variable 'x' [-Werror=unused-variable]
//     2 |     int x;
//       |         ^
// /home/ghi/Documents/cpp/1.4_variables/main.cpp:3:9: error: unused variable ‘y’ [-Werror=unused-variable]
//     3 |     int y, z;
//       |         ^
// /home/ghi/Documents/cpp/1.4_variables/main.cpp:3:12: error: unused variable ‘z’ [-Werror=unused-variable]
//     3 |     int y, z;

#include <iostream>

int main0()
{
    int width;          // define
    width = 5;          // assign
    std::cout << width; // print

    width = 7;
    std::cout << width;

    return 0;
}

int main1()
{
    int width{5}; // define + assign initial value
    std::cout << width;

    return 0;
}

// error: narrowing conversion of ‘4.5e+0’ from ‘double’ to ‘int’ [-Wnarrowing]
// int main2(){
//     int w {4.5};
//     std::cout << w;

//     return 0;
// }
// int main3(){
//     int w {7};

//     w = 4.5; // still I get errors because I had set them all as errors
//     std::cout << w;

//     return 0;
// }

// maybe unused
int main()
{
    [[maybe_unused]] double pi{3.14159};  // Don't complain if pi is unused
    [[maybe_unused]] double gravity{9.8}; // Don't complain if gravity is unused
    [[maybe_unused]] double phi{1.61803}; // Don't complain if phi is unused

    std::cout << pi << '\n';
    std::cout << phi << '\n';

    // The compiler will no longer warn about gravity not being used

    return 0;
}
