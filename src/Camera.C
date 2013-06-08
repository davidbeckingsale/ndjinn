#include "Camera.h"

#include "LineSegment.h"
#include "Circle.h"

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

        if(typeid(*e) == typeid(LineSegment)) {
            LineSegment* ls = dynamic_cast<LineSegment*>(e);
            std::vector<Point*> points = ls->pointsInSegment();

            for(std::vector<Point*>::iterator lsit = points.begin(); lsit != points.end(); ++lsit) {
                Point* p = *lsit;

                if(p->getX() >= minX && p->getX() <= maxX
                        && p->getY() >= minY && p->getY() <= maxY
                        && p->getZ() >= minZ && p->getZ() <= maxZ) {
                    culled_entities.push_back(p);
                }
            }
        } else if(typeid(*e) == typeid(Circle)) {
            Circle* c = dynamic_cast<Circle*>(e);
            std::vector<Point*> points = c->pointsInCircle();

            for(std::vector<Point*>::iterator lsit = points.begin(); lsit != points.end(); ++lsit) {
                Point* p = *lsit;
                if(p->getX() >= minX && p->getX() <= maxX
                        && p->getY() >= minY && p->getY() <= maxY
                        && p->getZ() >= minZ && p->getZ() <= maxZ) {
                    culled_entities.push_back(p);
                }
            }
        } else {
            if(e->getX() >= minX && e->getX() <= maxX
                    && e->getY() >= minY && e->getY() <= maxY
                    && e->getZ() >= minZ && e->getZ() <= maxZ) {
                culled_entities.push_back(e);
                drawn++;
            }
        }
    }

    r->drawScene(culled_entities);
}

