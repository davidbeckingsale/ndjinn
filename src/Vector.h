#ifndef VECTOR_H_
#define VECTOR_H_

class Vector {
    private:
        double x;
        double y;
        double z;
    public:
        Vector(double x, double y, double z);

        Vector* addVectorToVector(Vector* v);
        Vector* subtractVectorFromVector(Vector* v);

        Vector* rotateXY(double degrees);
        Vector* rotateYZ(double degrees);
        Vector* rotateXZ(double degrees);

        Vector* scale(double s0, double s1, double s2);

        double getX();
        double getY();
        double getZ();
};

#endif
