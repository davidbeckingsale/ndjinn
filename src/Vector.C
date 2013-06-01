#include "Vector.h"

#include <cmath>

#define PI 3.14159265

Vector::Vector(double x, double y, double z):
    x(x),
    y(y),
    z(z)
{
}

Vector* Vector::addVectorToVector(Vector* v)
{
    return new Vector(x + v->getX(), y + v->getY(), z + v->getZ());
}

Vector* Vector::subtractVectorFromVector(Vector* v)
{
    return new Vector(x - v->getX(), y - v->getY(), z - v->getZ());
}

Vector* Vector::rotateXY(double degrees)
{
    double rx, ry, rz;
    double r = degrees * PI/180.0;

    rx = x*cos(r) - y*sin(r);
    ry = x*sin(r) + y*cos(r);
    rz = z;

    return new Vector(rx,ry,rz);

}

Vector* Vector::rotateYZ(double degrees)
{
    double rx, ry, rz;
    double r = degrees * PI/180.0;

    rx = x;
    ry = y*cos(r) - z*sin(r);
    rz = y*sin(r) + z*cos(r);

    return new Vector(rx,ry,rz);
}

Vector* Vector::rotateXZ(double degrees)
{
    double rx, ry, rz;
    double r = degrees * PI/180.0;

    rx = x*cos(r) + y*sin(r);
    ry = y;
    rz = -x*sin(r) + z*cos(r);

    return new Vector(rx,ry,rz);
}

Vector* Vector::scale(double s0, double s1, double s2)
{
    double sx, sy, sz;

    sx = x*s0;
    sy = y*s1;
    sz = z*s2;

    return new Vector(sx,sy,sz);
}

double Vector::getX() { return x; }
double Vector::getY() { return y; }
double Vector::getZ() { return z; }
