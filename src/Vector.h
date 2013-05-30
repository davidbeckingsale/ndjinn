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

        double getX();
        double getY();
        double getZ();
};

#endif
