#include "LineSegment.h"

#include <cmath>

std::vector<Point*> LineSegment::pointsInSegment()
{
    std::vector<Point*> points;

    double x0 = start_x;
    double y0 = start_y;
    double x1 = end_x;
    double y1 = end_y;

    double dx = abs(x1-x0);
    double dy = abs(y1-y0);
    bool sx = ((int)x0 & (int)x1) ? 1 : -1;
    bool sy = ((int)y0 & (int)y1) ? 1 : -1;
    double err = dx - dy;

    points.push_back(new Point(x0,y0,0.0));

    while (!((x0 == x1) && (y0 == y1))) {
        double e2 = err * 2;

        if (e2 >= -dy) {
            err -= dy;
            x0 += sx;
        }
        
        if (e2 < dx) {
            err += dx;
            y0 += sy;
        }

        points.push_back(new Point(x0, y0, 0.0));
    }

    return points;
}
