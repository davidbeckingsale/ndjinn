#ifndef CIRCLE_H_
#define CIRCLE_H_

#include "Point.h"

#include <vector>

class Circle : public Entity{
    public:
        Circle(double x, double y, double r);
        std::vector<Point*> pointsInCircle();
        void draw();
        double getX();
        double getY();
        double getZ();
    private:
        double center_x, center_y;
        double radius;
};

#endif
