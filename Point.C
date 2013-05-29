#include "Point.h"

#include <iostream>

Point::Point(double x, double y, double z)
{
   tuple[0] = x; 
   tuple[1] = y; 
   tuple[2] = z; 
}

void Point::addVectorToPoint(Vector* v)
{

    tuple[0] += v->x();
    tuple[1] += v->y();
    tuple[2] += v->z();

}

void Point::subtractVectorFromPoint(Vector* v)
{
    tuple[0] -= v->x();
    tuple[1] -= v->y();
    tuple[2] -= v->z();
}

Vector* Point::subtractPointFromPoint(Point* p)
{
    return new Vector(x()-p->x(),
            y()-p->y(),
            z()-p->z());
}

void Point::drawPoint()
{
    std::cout << "(" << x() << "," << y() << "," << z() << ")" << std::endl;
}

double Point::x() { return tuple[0]; }
double Point::y() { return tuple[1]; }
double Point::z() { return tuple[2]; }
