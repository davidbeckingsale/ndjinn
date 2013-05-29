#ifndef VECTOR_H_
#define VECTOR_H_

class Vector {
    private:
        double tuple[3];
    public:
        Vector(double x, double y, double z);

        Vector* addVectorToVector(Vector* v);
        Vector* subtractVectorFromVector(Vector* v);

        double x();
        double y();
        double z();
};

#endif
