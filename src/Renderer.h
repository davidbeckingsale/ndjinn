#ifndef RENDERER_H_
#define RENDERER_H_

#include "Entity.h"

#include <vector>

class Renderer {
    public: 
        Renderer();
        void drawScene(std::vector<Entity*> objects);
};

#endif
