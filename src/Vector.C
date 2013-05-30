#include "Vector.h"

Vector::Vector(double x, double y, double z):
    x(x),
    y(y),
    z(z)
{
}

Vector* Vector::addVectorToVector(Vector* v)
{
    x += v->getX();
    y += v->getY();
    z += v->getZ();

    return this;
}

Vector* Vector::subtractVectorFromVector(Vector* v)
{
    x -= v->getX();
    y -= v->getY();
    z -= v->getZ();

    return this;
}

double Vector::getX() { return x; }
double Vector::getY() { return y; }
double Vector::getZ() { return z; }
