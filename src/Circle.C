#include "Circle.h"

Circle::Circle(double x, double y, double r) :
    center_x(x),
    center_y(y),
    radius(r)
{
}

std::vector<Point*> Circle::pointsInCircle()
{
    std::vector<Point*> points;

    double f = 1 - radius;
    double ddFx = 1;
    double ddFy = -2 * radius;
    int x = 0;
    int y = radius;

    points.push_back(new Point(center_x, center_y + radius, 0.0));
    points.push_back(new Point(center_x, center_y - radius, 0.0));
    points.push_back(new Point(center_x + radius, center_y, 0.0));
    points.push_back(new Point(center_x - radius, center_y, 0.0));

    while(x < y) {
        if (f >= 0.0) {
            y--;
            ddFy += 2;
            f += ddFy;
        }
        x++;
        ddFx += 2;
        f += ddFx;

        points.push_back(new Point(center_x + x, center_y + y, 0.0));
        points.push_back(new Point(center_x - x, center_y + y, 0.0));
        points.push_back(new Point(center_x + x, center_y - y, 0.0));
        points.push_back(new Point(center_x - x, center_y - y, 0.0));
        points.push_back(new Point(center_x + y, center_y + x, 0.0));
        points.push_back(new Point(center_x - y, center_y + x, 0.0));
        points.push_back(new Point(center_x + y, center_y - x, 0.0));
        points.push_back(new Point(center_x - y, center_y - x, 0.0));
    }

    return points;
}

void Circle::draw()
{
}

double Circle::getX()
{
    return center_x;
}

double Circle::getY()
{
    return center_y;
}

double Circle::getZ()
{
    return 0.0;
}
