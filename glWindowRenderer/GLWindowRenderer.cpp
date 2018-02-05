#include <iostream>

#define GLEW_STATIC
#include <GL/glew.h>

#include "GLWindowRenderer.h"

namespace KGVR {

GLWindowRenderer::GLWindowRenderer(int width, int height)
    : m_windowWidth(width)
    , m_windowHeight(height)
    , m_window(nullptr)
{
    std::cout << "Initializing OpenGL stuff and window." << std::endl;
    if (!glfwInit())
        throw std::logic_error("glfwInit failed, aborting.");

    /* Create a windowed mode window and its OpenGL context */
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_window = glfwCreateWindow(m_windowWidth, m_windowHeight, "VRayTracing", NULL, NULL);
    if (!m_window)
    {
        glfwTerminate();
        throw std::logic_error("Could not create window. Probably too old OpenGL version.");
    }

    glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwGetCursorPos(m_window, &m_mouseX, &m_mouseY);
    m_monitorWidth = glfwGetVideoMode(glfwGetPrimaryMonitor())->width;
    m_monitorHeight = glfwGetVideoMode(glfwGetPrimaryMonitor())->height;

    /* Make the window's context current */
    glfwMakeContextCurrent(m_window);

    glewExperimental=GL_TRUE;
    GLenum err=glewInit();
    if(err!=GLEW_OK)
        throw std::logic_error("glewInit failed, aborting.");
    const GLubyte* renderer = glGetString(GL_RENDERER); // get renderer string
    const GLubyte* version = glGetString(GL_VERSION); // version as a string
    std::cout << "Renderer: " << renderer << std::endl;
    std::cout << "OpenGL version supported: " << version << std::endl;

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    float points[] = {
        -1.0f,  1.0f,  0.0f, 0.0f, 1.0f,
        -1.0f, -1.0f,  0.0f, 0.0f, 0.0f,
        1.0f, -1.0f,  0.0f, 1.0f, 0.0f,
        1.0f, -1.0f,  0.0f, 1.0f, 0.0f,
        1.0f, 1.0f,  0.0f, 1.0f, 1.0f,
        -1.0f,  1.0f,  0.0f, 0.0f, 1.0f,
    };

    m_shaderProgram = glCreateProgram();
    const char* vertex_shader =
            "#version 400\n"
            "in vec3 vert;\n"
            "in vec2 vertTexCoord;\n"
            "out vec2 fragTexCoord;\n"
            "void main() {\n"
            "    // Pass the tex coord straight through to the fragment shader\n"
            "    fragTexCoord = vertTexCoord;\n"
            "    gl_Position = vec4(vert, 1);\n"
            "}\n";

    const char* fragment_shader =
            "#version 400\n"
            "uniform sampler2D tex;\n"
            "in vec2 fragTexCoord;\n"
            "out vec4 finalColor;\n"
            "void main() {\n"
            "    finalColor = texture(tex, fragTexCoord);\n"
            "}\n";

    GLuint vs = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs, 1, &vertex_shader, NULL);
    glCompileShader(vs);
    GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs, 1, &fragment_shader, NULL);
    glCompileShader(fs);

    glAttachShader(m_shaderProgram, fs);
    glAttachShader(m_shaderProgram, vs);
    glLinkProgram(m_shaderProgram);

    //throw exception if linking failed
    GLint status;
    glGetProgramiv(m_shaderProgram, GL_LINK_STATUS, &status);
    if (status == GL_FALSE) {
        std::string msg("Program linking failure: ");

        GLint infoLogLength;
        glGetProgramiv(m_shaderProgram, GL_INFO_LOG_LENGTH, &infoLogLength);
        char* strInfoLog = new char[infoLogLength + 1];
        glGetProgramInfoLog(m_shaderProgram, infoLogLength, NULL, strInfoLog);
        msg += strInfoLog;
        delete[] strInfoLog;

        glDeleteProgram(m_shaderProgram); m_shaderProgram = 0;
        std::cout << msg.c_str() << std::endl;
    }

    glGenTextures(1, &m_textureObject);
    glBindTexture(GL_TEXTURE_2D, m_textureObject);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    m_vao = 0;
    glGenVertexArrays(1, &m_vao);
    glBindVertexArray(m_vao);

    m_vbo = 0;
    glGenBuffers(1, &m_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);

    glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);

    glEnableVertexAttribArray(glGetAttribLocation(m_shaderProgram, "vert"));
    glVertexAttribPointer(glGetAttribLocation(m_shaderProgram, "vert"), 3, GL_FLOAT, GL_FALSE, 5*sizeof(GLfloat), NULL);

    glEnableVertexAttribArray(glGetAttribLocation(m_shaderProgram, "vertTexCoord"));
    glVertexAttribPointer(glGetAttribLocation(m_shaderProgram, "vertTexCoord"), 2, GL_FLOAT, GL_TRUE, 5*sizeof(GLfloat), (const GLvoid*)(3 * sizeof(GLfloat)));

    glUseProgram(m_shaderProgram);
    glActiveTexture(GL_TEXTURE0);
}

void GLWindowRenderer::pollEvents() const
{
    glfwPollEvents();
}

void GLWindowRenderer::render(float* pixels)
{
    glTexImage2D(GL_TEXTURE_2D,
                 0,
                 GL_RGBA8,
                 m_windowWidth,
                 m_windowHeight,
                 0,
                 GL_BGRA,
                 GL_FLOAT,
                 pixels);
    glUniform1f(glGetUniformLocation(m_shaderProgram, "tex"), 0);

    glDrawArrays(GL_TRIANGLES, 0, 6);
    glfwSwapBuffers(m_window);
}

std::tuple<double, double> GLWindowRenderer::getMouseDelta()
{
    double currentXpos;
    double currentYpos;
    glfwGetCursorPos(m_window, &currentXpos, &currentYpos);
    auto result = std::tuple<double, double>((currentXpos - m_mouseX) / m_monitorWidth, (currentYpos - m_mouseY) / m_monitorWidth);
    m_mouseX = currentXpos;
    m_mouseY = currentYpos;
    return result;
}

GLFWwindow* GLWindowRenderer::getWindow() const
{
    return m_window;
}

bool GLWindowRenderer::shouldClose()
{
    return glfwWindowShouldClose(m_window);
}

void GLWindowRenderer::terminate()
{
    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D, 0);
    glUseProgram(0);
    glfwTerminate();
}

} // KGVR
