struct Something
{
    int x;       // no default initialization value (bad)
    int y {};    // value-initialized by default
    int z { 2 }; // explicit default value
};

struct Fraction
{
    int numerator {}; // we should use { 0 } here, but for the sake of example we'll use value initialization instead
    int denominator { 1 };
};

int main()
{
    Something s1;             // No initializer list: s1.x is uninitialized, s1.y and s1.z use defaults
    Something s2 { 5, 6, 7 }; // Explicit initializers: s2.x, s2.y, and s2.z use explicit values (no default values are used)
    Something s3 {};          // Missing initializers: s3.x is value initialized, s3.y and s3.z use defaults

    Fraction f1;          // f1.numerator value initialized to 0, f1.denominator defaulted to 1
    Fraction f2 {};       // f2.numerator value initialized to 0, f2.denominator defaulted to 1
    Fraction f3 { 6 };    // f3.numerator initialized to 6, f3.denominator defaulted to 1
    Fraction f4 { 5, 8 }; // f4.numerator initialized to 5, f4.denominator initialized to 8

    return 0;
}
