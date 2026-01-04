#include <iostream>
#include <string>
#include <string_view>

class Employee
{
  private:
    std::string m_name { "???" };
    int m_id { 0 };

  public:
    Employee(std::string_view name, int id)
        // delegate initialization to Employee(std::string_view, int) constructor
        : m_name { name }, m_id { id } // actually initializes the members
    {
        std::cout << "Employee(" << name << ", " << id << ")\n";
    }

    Employee(std::string_view name)
        : Employee { name, 0 }
    {
    }
};

class Employee2
{
  private:
    std::string m_name {};
    int m_id { 0 }; // default member initializer

  public:
    Employee2(std::string_view name, int id = 0) // default argument for id
        : m_name { name }, m_id { id }
    {
        std::cout << "Employee(" << name << ", " << id << ")\n";
    }
};

/// EXERCISE
class Ball
{
    std::string m_color { "black" };
    double m_radius { 10.0 };

  public:
    // handle (color, radius) , (color) , ()
    Ball(std::string_view color = "black", double radius = 10.0)
        : m_color { color }, m_radius { radius }
    {
        print();
    }

    // handle (radius)
    Ball(double radius)
        : Ball { "black", radius }
    {
        // delegate to the default constructor
    }

    void print() const
    {
        std::cout << "Ball(" << m_color << ", " << m_radius << ")\n";
    }
};

int main()
{
    Employee e1 { "James" };
    Employee e2 { "Dave", 42 };
    Employee2 e3 { "James" };
    Employee2 e4 { "Dave", 42 };

    Ball def {};
    Ball blue { "blue" };
    Ball twenty { 20.0 };
    Ball blueTwenty { "blue", 20.0 };

    return 0;
}
