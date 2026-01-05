
// Header file that defines the Point3d class

#ifndef POINT3D
#define POINT3D

// forward declaration of the Vector3d class
class Vector3d;

class Point3d
{
  private:
    double m_x {};
    double m_y {};
    double m_z {};

  public:
    Point3d(double x, double y, double z);

    void print() const;

    // forward declaration of the moveByVector
    // we can use the type Vector3d since we have declared it
    void moveByVector(const Vector3d& v);
};

#endif
