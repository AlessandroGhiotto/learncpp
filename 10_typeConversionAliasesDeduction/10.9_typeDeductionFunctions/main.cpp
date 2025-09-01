auto add1(int x, int y)
{
    return x + y;
}

// let compiler determine the return type of unsigned short + char
auto add2(unsigned short x, char y)
{
    return x + y;
}

// a forward declaration is not enough
// auto foo();

// TRAILING return syntax
// int add(int x, int y) is equal to:
auto add3(int x, int y) -> int
{
    return (x + y);
}

// can be used for gaining readability
// std::common_type_t<int, double> compare(int, double);         // harder to read (where is the name of the function in this mess?)
// auto compare(int, double) -> std::common_type_t<int, double>; // easier to read (we don't have to read the return type unless we care)

int main()
{
    return 0;
}
