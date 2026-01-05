#include <iostream>

class Storage
{
  private:
    int m_nValue {};
    double m_dValue {};

  public:
    Storage(int nValue, double dValue)
        : m_nValue { nValue }, m_dValue { dValue }
    {
    }

    // Make the Display class a friend of Storage
    friend class Display;
};

class Display
{
  private:
    bool m_displayIntFirst {};

  public:
    Display(bool displayIntFirst)
        : m_displayIntFirst { displayIntFirst }
    {
    }

    // Because Display is a friend of Storage, Display members can access the private members of Storage
    void displayStorage(const Storage& storage)
    {
        if (m_displayIntFirst)
            std::cout << storage.m_nValue << ' ' << storage.m_dValue << '\n';
        else // display double first
            std::cout << storage.m_dValue << ' ' << storage.m_nValue << '\n';
    }

    void setDisplayIntFirst(bool b)
    {
        m_displayIntFirst = b;
    }
};

int main0()
{
    Storage storage { 5, 6.7 };
    Display display { false };

    display.displayStorage(storage);

    display.setDisplayIntFirst(true);
    display.displayStorage(storage);

    return 0;
}

/// EXERCISE

/*
// forward declaration of the Vector3d class
class Vector3d;

class Point3d
{
  private:
    double m_x {};
    double m_y {};
    double m_z {};

  public:
    Point3d(double x, double y, double z)
        : m_x { x }, m_y { y }, m_z { z }
    {
    }

    void print() const
    {
        std::cout << "Point(" << m_x << ", " << m_y << ", " << m_z << ")\n";
    }

    // forward declaration of the moveByVector
    // we can use the type Vector3d since we have declared it
    void moveByVector(const Vector3d& v);
};

class Vector3d
{
  private:
    double m_x {};
    double m_y {};
    double m_z {};

  public:
    Vector3d(double x, double y, double z)
        : m_x { x }, m_y { y }, m_z { z }
    {
    }

    void print() const
    {
        std::cout << "Vector(" << m_x << ", " << m_y << ", " << m_z << ")\n";
    }

    // make Point3d::moveByVector a friend function member of Vector3d
    // we can't put the full definition here since we have still not seen the full definition of Vector3d
    friend void Point3d::moveByVector(const Vector3d& v);
};

// now we have the full implementation of Point3d::moveByVector
// we can since we have seen the full definition of Vector3d
void Point3d::moveByVector(const Vector3d& v)
{
    m_x += v.m_x;
    m_y += v.m_y;
    m_z += v.m_z;
}

*/

#include "Point3d.h"
#include "Vector3d.h"

int main()
{
    Point3d p { 1.0, 2.0, 3.0 };
    Vector3d v { 2.0, 2.0, -3.0 };

    p.print();
    p.moveByVector(v);
    p.print();

    return 0;
}
