#include "Renderer.h"

Renderer::Renderer()
{
}

void Renderer::drawScene(std::vector<Entity*> objects)
{
    for(std::vector<Entity*>::iterator it = objects.begin(); it != objects.end(); ++it) {
        Entity* e = *it;
            e->draw();
    }
}
