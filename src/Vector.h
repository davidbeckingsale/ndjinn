#ifndef VECTOR_H_
#define VECTOR_H_

class Vector {
    private:
        double x;
        double y;
        double z;
    public:
        Vector(double x, double y, double z);

        void addVectorToVector(Vector& v);
        void subtractVectorFromVector(Vector& v);

        void rotateXY(double degrees);
        void rotateYZ(double degrees);
        void rotateXZ(double degrees);

        void scale(double s0, double s1, double s2);

        double getX();
        double getY();
        double getZ();
};

#endif
