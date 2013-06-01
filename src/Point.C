#include "Point.h"

#include <iostream>

#include "GL/glfw.h"


Point::Point(double x, double y, double z):
    x(x),
    y(y),
    z(z)
{
}

Point* Point::addVectorToPoint(Vector* v)
{
    return new Point(x + v->getX(), y + v->getY(), z + v->getZ());
}

Point* Point::subtractVectorFromPoint(Vector* v)
{
    return new Point(x - v->getX(), y - v->getY(), z - v->getZ());
}

Vector* Point::subtractPointFromPoint(Point* p)
{
    return new Vector(x - p->getX(), y - p->getY(), z - p->getZ());
}

void Point::setPointToPoint(Point* p)
{
    x = p->getX();
    y = p->getY();
    z = p->getZ();
}

void Point::drawPoint()
{
    glBegin(GL_POINTS);
        glVertex3f(x,y,z);
    glEnd();
}

double Point::getX() { return x; }
double Point::getY() { return y; }
double Point::getZ() { return z; }
