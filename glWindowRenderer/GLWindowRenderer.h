#ifndef GLWINDOWRENDERER_H
#define GLWINDOWRENDERER_H

#include <GLFW/glfw3.h>
#include <tuple>

namespace KGVR {

class GLWindowRenderer
{

public:
    GLWindowRenderer(int width, int height);
    bool shouldClose();
    void terminate();
    void render(float* pixels);
    std::tuple<double, double> getMouseDelta();

private:
    int m_width;
    int m_height;
    GLFWwindow* m_window;
    GLuint m_textureObject;
    GLuint m_vao;
    GLuint m_vbo;
    GLuint m_shaderProgram;
    double xpos, ypos;
};

} // KGVR

#endif // GLWINDOWRENDERER_H
