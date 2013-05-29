#include "Point.h"

#include <iostream>

Point::Point(double x, double y, double z):
    x(x),
    y(y),
    z(z)
{
}

Point* Point::addVectorToPoint(Vector* v)
{
    x += v->getX();
    y += v->getY();
    z += v->getZ();

    return this;
}

Point* Point::subtractVectorFromPoint(Vector* v)
{
    x -= v->getX();
    y -= v->getY();
    z -= v->getZ();

    return this;
}

Vector* Point::subtractPointFromPoint(Point* p)
{
    return new Vector(x-p->getX(),
            y-p->getY(),
            z-p->getZ());
}

void Point::drawPoint()
{
    std::cout << "(" << x << "," << y << "," << z << ")" << std::endl;
}

double Point::getX() { return x; }
double Point::getY() { return y; }
double Point::getZ() { return z; }
