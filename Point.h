#ifndef POINT_H_
#define POINT_H_

#include "Vector.h"

class Point {
    private:
        double tuple[3];
    public:
        Point(double x, double y, double z);

        void addVectorToPoint(Vector* v);
        void subtractVectorFromPoint(Vector* v);
        Vector* subtractPointFromPoint(Point* p);

        double x();
        double y();
        double z();

        void drawPoint();
};

#endif
