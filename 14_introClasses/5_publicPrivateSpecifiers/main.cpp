#include <iostream>

struct Date
{
    // struct members are public by default, can be accessed by anyone
    int year {};  // public by default
    int month {}; // public by default
    int day {};   // public by default

    void print() const // public by default
    {
        // public members can be accessed in member functions of the class type
        std::cout << year << '/' << month << '/' << day << std::endl;
    }
};

/*
class DateC // now a class instead of a struct
{
    // class members are private by default, can only be accessed by other members
    int m_year {};  // private by default
    int m_month {}; // private by default
    int m_day {};   // private by default

    void print() const // private by default
    {
        // private members can be accessed in member functions
        std::cout << m_year << '/' << m_month << '/' << m_day;
    }
};
*/

class DateSpec
{
    // Any members defined here would default to private

  public:              // here's our public access specifier
    void print() const // public due to above public: specifier
    {
        // members can access other private members
        std::cout << m_year << '/' << m_month << '/' << m_day << std::endl;
    }

  private:               // here's our private access specifier
    int m_year { 2020 }; // private due to above private: specifier
    int m_month { 14 };  // private due to above private: specifier
    int m_day { 10 };    // private due to above private: specifier
};

class Person
{
  private:
    std::string_view m_name {};

  public:
    void kisses(const Person& other) const
    {
        // this can see other.m_name
        std::cout << m_name << " kisses " << other.m_name << std::endl;
    }

    void setName(std::string_view name)
    {
        m_name = name;
    }
};

class Point3d
{

  private:
    int m_x {};
    int m_y {};
    int m_z {};

  public:
    void setValues(int x, int y, int z)
    {
        m_x = x;
        m_y = y;
        m_z = z;
    }

    void print() const
    {
        std::cout << "<" << m_x << ", " << m_y << ", " << m_z << ">";
    }

    bool isEqual(const Point3d& other) const
    {
        return m_x == other.m_x && m_y == other.m_y && m_z == other.m_z;
    }
};

int main()
{
    Date today { 2020, 10, 14 }; // aggregate initialize our struct

    // public members can be accessed by the public
    today.day = 16; // okay: the day member is public
    today.print();  // okay: the print() member function is public

    /*
    DateC todayC { 2020, 10, 14 }; // compile error: can no longer use aggregate initialization

    // private members can not be accessed by the public
    todayC.m_day = 16; // compile error: the m_day member is private
    todayC.print();    // compile error: the print() member function is private
    */

    DateSpec todaySpec;
    // private members can not be accessed by the public
    // todaySpec.m_day = 16; // compile error: the m_day member is private
    todaySpec.print(); // OK: the print() member function is public

    // ACCES LEVELS ARE DEFINED PER CLASS (NOT PER OBJECT)
    Person alice;
    alice.setName("alice");
    Person bob;
    bob.setName("bob");
    alice.kisses(bob);

    // EXERCISE:
    Point3d point1 {};
    point1.setValues(1, 2, 3);
    point1.print();
    std::cout << '\n';
    Point3d point2 {};
    point2.setValues(1, 2, 3);

    std::cout << "point 1 and point 2 are" << (point1.isEqual(point2) ? "" : " not") << " equal\n";

    Point3d point3 {};
    point3.setValues(3, 4, 5);

    std::cout << "point 1 and point 3 are" << (point1.isEqual(point3) ? "" : " not") << " equal\n";

    return 0;
}
