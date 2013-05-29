#include "Vector.h"

Vector::Vector(double x, double y, double z)
{
   tuple[0] = x; 
   tuple[1] = y; 
   tuple[2] = z; 
}

Vector* Vector::addVectorToVector(Vector* v)
{
    return new Vector(x()+v->x(),
            y()+v->y(),
            z()+v->z());
}

Vector* Vector::subtractVectorFromVector(Vector* v)
{
    return new Vector(x()-v->x(),
            y()-v->y(),
            z()-v->z());
}

double Vector::x() { return tuple[0]; }
double Vector::y() { return tuple[1]; }
double Vector::z() { return tuple[2]; }
