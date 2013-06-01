#ifndef CAMERA_H_
#define CAMERA_H_

#include "Entity.h"
#include "Renderer.h"

#include <vector>

class Camera {
    private:
        int minX, minY, minZ;
        int maxX, maxY, maxZ; 

        std::vector<Entity*> entities;

        Renderer* r;
    public:
        Camera();

        void setViewMin(double x, double y, double z);
        void setViewMax(double x, double y, double z);

        void addToWorld(Entity* e);

        void drawScene();
};

#endif
