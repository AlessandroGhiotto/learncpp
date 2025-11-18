#include <string>
#include <string_view>

int add(int x, int y)
{
    return x + y;
}

int main()
{
    [[maybe_unused]] auto d{5.0};   // 5.0 is a double literal, so d will be deduced as a double
    [[maybe_unused]] auto i{1 + 2}; // 1 + 2 evaluates to an int, so i will be deduced as an int
    [[maybe_unused]] auto x{i};     // i is an int, so x will be deduced as an int

    [[maybe_unused]] auto sum{add(5, 6)};

    [[maybe_unused]] const int a{5}; // a has type const int
    // auto b{a};      // b has type int (const dropped)
    [[maybe_unused]] const auto b{a}; // b has type const int (const dropped but reapplied);

    /// STRINGS
    using namespace std::literals; // easiest way to access the s and sv suffixes

    [[maybe_unused]] auto s{"Hello, world"}; // s will be type const char*, not std::string
    [[maybe_unused]] auto s1{"goo"s};        // "goo"s is a std::string literal, so s1 will be deduced as a std::string
    [[maybe_unused]] auto s2{"moo"sv};       // "moo"sv is a std::string_view literal, so s2 will be deduced as a std::string_view

    return 0;
}
