#ifndef GLWINDOWRENDERER_H
#define GLWINDOWRENDERER_H

#include <GLFW/glfw3.h>
#include <tuple>

namespace KGVR {

class GLWindowRenderer
{

public:
    GLWindowRenderer(int width, int height);
    void pollEvents() const;
    bool shouldClose();
    void render(float* pixels);
    void terminate();
    std::tuple<double, double> getMouseDelta();
    GLFWwindow* getWindow() const;

private:
    int m_monitorWidth, m_monitorHeight;
    int m_windowWidth, m_windowHeight;
    double m_mouseX, m_mouseY;
    GLFWwindow* m_window;
    GLuint m_textureObject;
    GLuint m_vao;
    GLuint m_vbo;
    GLuint m_shaderProgram;
};

} // KGVR

#endif // GLWINDOWRENDERER_H
