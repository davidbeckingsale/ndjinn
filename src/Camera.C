#include "Camera.h"

#include <iostream>

Camera::Camera()
{
    r = new Renderer();
}

void Camera::setViewMin(double x, double y, double z)
{
    minX = x;
    minY = y;
    minZ = z;
}

void Camera::setViewMax(double x, double y, double z)
{
    maxX = x;
    maxY = y;
    maxZ = z;
}

void Camera::addToWorld(Entity* e)
{
    entities.push_back(e);
}

void Camera::drawScene()
{
    int drawn = 0;
    std::vector<Entity*> culled_entities;

    for(std::vector<Entity*>::iterator it = entities.begin(); it != entities.end(); ++it) {
        Entity* e = *it;
        if(e->getX() >= minX && e->getX() <= maxX
                && e->getY() >= minY && e->getY() <= maxY
                && e->getZ() >= minZ && e->getZ() <= maxZ) {
            culled_entities.push_back(e);
            drawn++;
        }
    }

    r->drawScene(culled_entities);
}

