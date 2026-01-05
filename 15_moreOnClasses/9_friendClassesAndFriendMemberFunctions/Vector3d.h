// Header file that defines the Vector3d class

#ifndef VECTOR3D
#define VECTOR3D

#include "Point3d.h" // for declaring Point3d::moveByVector() as a friend

class Vector3d
{
  private:
    double m_x {};
    double m_y {};
    double m_z {};

  public:
    Vector3d(double x, double y, double z);

    void print() const;

    // make Point3d::moveByVector a friend function member of Vector3d
    // we can't put the full definition here since we have still not seen the full definition of Vector3d
    friend void Point3d::moveByVector(const Vector3d& v);
};

#endif
