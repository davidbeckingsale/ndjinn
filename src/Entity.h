#ifndef ENTITY_H_
#define ENTITY_H_

class Entity {
    public:
        virtual void draw() = 0;
        virtual double getX() = 0;
        virtual double getY() = 0;
        virtual double getZ() = 0;
};

#endif
