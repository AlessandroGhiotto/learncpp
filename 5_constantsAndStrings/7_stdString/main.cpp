#include <iostream>
#include <string>

int main1()
{
    std::string name{}; // empty string
    std::cout << '[' << name << "]\n";
    name = "Ale";               // change name to "Ale"
    std::string surname{"Ghi"}; // initialize surname with string literal "Ghi"
    std::string myID{"21"};     // "21" is not the same as integer 45!
    std::cout << "My name is: " << name << " " << surname << ". age: " << myID << '\n';

    return 0;
}

// operator>> extract the values from std::cin until the whitespace!
// not nice for strings
int main()
{
#if 0
    std::cout << "Enter your full name: "; // nome e cognome
    std::string name{};                    // nome
    std::cin >> name;                      // this won't work as expected since std::cin breaks on whitespace

    std::cout << "Enter your favorite color: ";
    std::string color{};
    std::cin >> color; // this is going to extract the surname which is buffered    

    std::cout << "Your name is " << name << " and your favorite color is " << color << '\n';
#endif

    std::cout << "Enter your name and surname: ";
    std::string name{};
    std::getline(std::cin >> std::ws, name);

    std::cout << "Enter your city of birth: ";
    std::string city{};
    std::getline(std::cin >> std::ws, city);
    std::cout << "\n";

    std::cout << "Hello " << name << ", ninja di " << city << "\n";
    // std::cout << "Your name is long: " << name.length() << " characters \n"; // get the length
    // std::string::length returns a size_t type. to store it as an int, we need to cast it
    // otherwise we get a warning for conversion from unsigned int to signed it,
    int length{static_cast<int>(name.length())};
    std::cout << "Your name is long: " << length << " characters \n\n";
    // long int length2{std::ssize(name)}; // std::ssize returns a signed value
    // std::cout << "Your name is long: " << length2 << " characters \n";

    // std::string literals:
    using namespace std::string_literals; // easy access to the s suffix
    std::cout << "foo\n";                 // no suffix is a C-style string literal
    std::cout << "goo\n"s;                // s suffix is a std::string literal

    return 0;
}
