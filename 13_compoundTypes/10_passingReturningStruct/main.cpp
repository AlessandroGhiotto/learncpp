
#include <iostream>

struct Employee
{
    int id {};
    int age {};
    double wage {};
};

void printEmployee(const Employee& employee) // note pass by reference here
{
    std::cout << "ID:   " << employee.id << '\n';
    std::cout << "Age:  " << employee.age << '\n';
    std::cout << "Wage: " << employee.wage << '\n';
}

int main0()
{
    // with initialized object
    Employee joe { 14, 32, 24.15 };
    printEmployee(joe);
    std::cout << '\n';

    // with temp object
    printEmployee(Employee { 15, 28, 18.27 });
    // printEmployee({15, 28, 18.27}); // Works but BAD

    return 0;
}

////////////////////////////////////////////////////
// RETURNING STRUCTS

struct Point3d
{
    double x { 0.0 };
    double y { 0.0 };
    double z { 0.0 };
};

Point3d getZeroPoint()
{
    // We can create a variable and return the variable (we'll improve this below)
    // Point3d temp { 0.0, 0.0, 0.0 };
    // return temp;

    // returning unnamed Point3D
    return Point3d { 0.0, 0.0, 0.0 };

    // We already specified the type at the function declaration
    // so we don't need to do so here again
    // return { 0.0, 0.0, 0.0 };

    // We can use empty curly braces to value-initialize all members
    // return {};
}

int main1()
{
    Point3d zero { getZeroPoint() };

    if (zero.x == 0.0 && zero.y == 0.0 && zero.z == 0.0)
        std::cout << "The point is zero\n";
    else
        std::cout << "The point is not zero\n";

    return 0;
}

///////////////////////////////////////////////
// EXERCISE 1
struct Advertisement
{
    int watchedNum { 0 };
    double clickedPercentage { 0.0 };
    double earningAvg { 0.0 };
};

Advertisement getAdvertisement()
{
    Advertisement ad {};
    std::cout << "Number of watched ads: ";
    std::cin >> ad.watchedNum;
    std::cout << "Percentage of clicked ads: ";
    std::cin >> ad.clickedPercentage;
    std::cout << "Average earning per clicked ad: ";
    std::cin >> ad.earningAvg;
    return ad;
}

void printAdvertisement(const Advertisement& ad)
{
    std::cout << "Watched ads: " << ad.watchedNum << '\n'
              << "Percentage clicks on ads: " << ad.clickedPercentage << '\n'
              << "Average earning per click: " << ad.earningAvg << '\n'
              << "Total earning for the day: " << ad.watchedNum * ad.clickedPercentage * ad.earningAvg << '\n';
}

int main2()
{
    Advertisement ad { getAdvertisement() };
    std::cout << std::endl;
    printAdvertisement(ad);

    return 0;
}

///////////////////////////////////////////////
// EXERCISE 2

struct Fraction
{
    int numerator { 0 };
    int denominator { 1 };
};

Fraction getFraction()
{
    Fraction temp {};
    std::cout << "Enter numerator (int): ";
    std::cin >> temp.numerator;
    std::cout << "Enter denominator (int): ";
    std::cin >> temp.denominator;

    return temp;
}

Fraction multiplyTwoFractions(const Fraction& x, const Fraction& y)
{
    return {
        x.numerator * y.numerator, x.denominator * y.denominator
    };
}

void printFraction(const Fraction& f)
{
    std::cout << f.numerator << '/' << f.denominator;
}

std::ostream& operator<<(std::ostream& out, Fraction f)
{
    out << f.numerator << '/' << f.denominator;
    return out;
}

int main()
{
    Fraction a { getFraction() };
    std::cout << std::endl;
    Fraction b { getFraction() };
    std::cout << std::endl;
    std::cout << "Product: " << multiplyTwoFractions(a, b) << std::endl;

    return 0;
}
