#ifndef LINE_SEGMENT_H_
#define LINE_SEGMENT_H_

#include "Point.h"

#include <vector>

class LineSegment {
    private:
        double start_x;
        double end_x;
        double start_y;
        double end_y;
    public:
        std::vector<Point*> pointsInSegment();
};

#endif
