#include "Point.h"
#include "Vector.h"
#include "Camera.h"

#include "GL/glfw.h"

#include <cstdlib>
#include <iostream>
#include <vector>

std::vector<Point*> points;
Camera* camera;

static void error_callback(int error, const char* description)
{
    std::cerr << description << std::endl;
}

extern "C" void GLFWCALL keyCallback(int key, int action) {
    if (key == 'S' && action == GLFW_PRESS) {
        Point origin(0.0,0.0,0.0);

        for(std::vector<int>::size_type i = 0; i != points.size(); i++) {
            Vector v = points[i]->subtractPointFromPoint(origin);
            points[i]->setPointToPoint(origin);
            v.scale(2.0,2.0,1.0);
            points[i]->addVectorToPoint(v);
        }
    }

    if (key == 'A' && action == GLFW_PRESS) {
        Point origin(0.0,0.0,0.0);

        for(std::vector<int>::size_type i = 0; i != points.size(); i++) {
            Vector v = points[i]->subtractPointFromPoint(origin);
            points[i]->setPointToPoint(origin);
            v.scale(0.5,0.5,1.0);
            points[i]->addVectorToPoint(v);

        }
    }

    if (key == 'R' && action == GLFW_PRESS) {
        Point origin(0.0,0.0,0.0);

        for(std::vector<int>::size_type i = 0; i != points.size(); i++) {
            Vector v = points[i]->subtractPointFromPoint(origin);
            points[i]->setPointToPoint(origin);
            v.rotateXY(15);
            points[i]->addVectorToPoint(v);
        }
    }
}

int main(int argc, char* argv[]) {
    int running = GL_TRUE;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    if (!glfwOpenWindow(640, 480, 8, 8, 8, 0, 24, 0, GLFW_WINDOW))
        return -1;

    glfwSetKeyCallback(keyCallback);

    camera = new Camera();
    camera->setViewMin(0.0, 0.0, 0.0);
    camera->setViewMax(640.0, 480.0, 1.0);

    for(int i = 0; i < 100; i++) {
        Point* p = new Point( (double) (rand() % 641),
                (double) (rand() % 481),
                (double) (rand() % 2));

        points.push_back(p);
        camera->addToWorld(p);
    }

    glPointSize(5.0);

    glViewport(0, 0, 640, 480);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.f, 640.f, 480.f, 0.f, 0.f, 1.f);
    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

    while(running) {

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        camera->drawScene();
        glfwSwapBuffers();

        running = !glfwGetKey(GLFW_KEY_ESC) && glfwGetWindowParam(GLFW_OPENED);
    }

    glfwTerminate();
    exit(EXIT_SUCCESS); 
}
