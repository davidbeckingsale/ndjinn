#include "Vector.h"

#include <cmath>

#define PI 3.14159265

Vector::Vector(double x, double y, double z):
    x(x),
    y(y),
    z(z)
{
}

Vector Vector::operator+(const Vector& v)
{
    return Vector(x + v.x, y + v.y, z + v.z);
}

Vector Vector::operator-(const Vector& v)
{
    return Vector(x - v.x, y - v.y, z - v.z);
}

void Vector::rotateXY(double degrees)
{
    double r = degrees * PI/180.0;

    x = x*cos(r) - y*sin(r);
    y = x*sin(r) + y*cos(r);
}

void Vector::rotateYZ(double degrees)
{
    double r = degrees * PI/180.0;

    y = y*cos(r) - z*sin(r);
    z = y*sin(r) + z*cos(r);
}

void Vector::rotateXZ(double degrees)
{
    double r = degrees * PI/180.0;

    x = x*cos(r) + y*sin(r);
    z = -x*sin(r) + z*cos(r);
}

void Vector::scale(double s0, double s1, double s2)
{
    x = x*s0;
    y = y*s1;
    z = z*s2;
}

double Vector::getX() { return x; }
double Vector::getY() { return y; }
double Vector::getZ() { return z; }
