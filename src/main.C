#include "Point.h"
#include "Circle.h"
#include "math/Vector.h"
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

extern "C" void GLFWCALL mouse_callback(int button, int action) {
    int x, y;

    if (action == GLFW_PRESS) {
        glfwGetMousePos(&x, &y);

        int r = rand() % 20 + 10;
        std::cout << "Adding new Circle @ " << x << "," << y << " with radius: " << r << std::endl;

        Circle* c = new Circle(x,y,r);
        camera->addToWorld(c);
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

    glfwSetMouseButtonCallback(mouse_callback);

    camera = new Camera();
    camera->setViewMin(0.0, 0.0, 0.0);
    camera->setViewMax(640.0, 480.0, 1.0);

    glPointSize(1.0);

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
