#ifndef POINT_H_
#define POINT_H_

#include "Vector.h"

class Point {
    private:
        double x;
        double y;
        double z;
    public:
        Point(double x, double y, double z);

        void addVectorToPoint(Vector& v);
        void subtractVectorFromPoint(Vector& v);
        Vector subtractPointFromPoint(Point& p);

        void setPointToPoint(Point& p);

        double getX();
        double getY();
        double getZ();

        void drawPoint();
};

#endif
