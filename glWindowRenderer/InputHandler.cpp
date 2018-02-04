#include "InputHandler.h"

namespace KGVR {

InputHandler::InputHandler()
    : m_mouseSensitivity(2.f)
    , m_previousMouseX(0.f)
    , m_previousMouseY(0.f)
    , m_mouseDelta(0.f, 0.f)
{
    m_pressedKeys[Key::A] = false;
    m_pressedKeys[Key::D] = false;
    m_pressedKeys[Key::S] = false;
    m_pressedKeys[Key::W] = false;
    m_pressedKeys[Key::R] = false;
    m_pressedKeys[Key::LeftAlt] = false;
    m_pressedKeys[Key::LeftControl] = false;
    m_pressedKeys[Key::LeftShift] = false;
    m_pressedKeys[Key::Spacebar] = false;

    m_repeatingKeys[Key::A] = false;
    m_repeatingKeys[Key::D] = false;
    m_repeatingKeys[Key::S] = false;
    m_repeatingKeys[Key::W] = false;
    m_repeatingKeys[Key::R] = false;
    m_repeatingKeys[Key::LeftAlt] = false;
    m_repeatingKeys[Key::LeftControl] = false;
    m_repeatingKeys[Key::LeftShift] = false;
    m_repeatingKeys[Key::Spacebar] = false;
}

std::tuple<float, float> InputHandler::getMouseDelta()
{
    auto result = m_mouseDelta;
    m_mouseDelta = std::tuple<float, float>(0.f, 0.f);
    return result;
}

InputHandler::InputHandler(GLFWwindow* window)
    : InputHandler()
{
    m_monitorWidth = glfwGetVideoMode(glfwGetPrimaryMonitor())->width;
    m_monitorHeight = glfwGetVideoMode(glfwGetPrimaryMonitor())->height;
    glfwSetWindowUserPointer(window, this);
    glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        auto inputHandler = static_cast<InputHandler*>(glfwGetWindowUserPointer(window));
        inputHandler->handleKeyAction(mapGLFWToKey(key), mapGLFWToAction(action));
    });
    glfwSetCursorPosCallback(window, [](GLFWwindow* window, double xpos, double ypos)
    {
        auto inputHandler = static_cast<InputHandler*>(glfwGetWindowUserPointer(window));
        inputHandler->handleMouseAction(static_cast<float>(xpos), static_cast<float>(ypos));
    });
}

void InputHandler::handleKeyAction(InputHandler::Key key, InputHandler::KeyAction action)
{
    switch (action) {
    case KeyAction::Pressed:
        m_pressedKeys[key] = true;
        break;
    case KeyAction::Released:
        m_pressedKeys[key] = false;
        m_repeatingKeys[key] = false;
        break;
    case KeyAction::Repeated:
        m_repeatingKeys[key] = true;
        break;
    }
}

void InputHandler::handleMouseAction(float currentMouseX, float currentMouseY)
{
    m_mouseDelta = std::tuple<float, float>(m_mouseSensitivity*(currentMouseX - m_previousMouseX) / m_monitorWidth,
                                            m_mouseSensitivity*(currentMouseY - m_previousMouseY) / m_monitorWidth);
    m_previousMouseX = currentMouseX;
    m_previousMouseY = currentMouseY;
}

bool InputHandler::getKeyAction(InputHandler::Key key, InputHandler::KeyAction action) const
{
    switch (action) {
    case KeyAction::Pressed:
        return m_pressedKeys.at(key);
    case KeyAction::Released:
        return !m_pressedKeys.at(key);
    case KeyAction::Repeated:
        return m_repeatingKeys.at(key);
    default:
        throw std::exception("Not a valid action");
    }
}

InputHandler::Key InputHandler::mapGLFWToKey(int key)
{
    switch (key) {
    case GLFW_KEY_A:
        return Key::A;
    case GLFW_KEY_D:
        return Key::D;
    case GLFW_KEY_S:
        return Key::S;
    case GLFW_KEY_W:
        return Key::W;
    case GLFW_KEY_R:
        return Key::R;
    case GLFW_KEY_LEFT_ALT:
        return Key::LeftAlt;
    case GLFW_KEY_LEFT_CONTROL:
        return Key::LeftControl;
    case GLFW_KEY_LEFT_SHIFT:
        return Key::LeftShift;
    case GLFW_KEY_SPACE:
        return Key::Spacebar;
    default:
        return Key::Unmapped;
    }
}

InputHandler::KeyAction InputHandler::mapGLFWToAction(int action)
{
    switch (action) {
    case GLFW_PRESS:
        return KeyAction::Pressed;
    case GLFW_RELEASE:
        return KeyAction::Released;
    case GLFW_REPEAT:
        return KeyAction::Repeated;
    default:
        throw std::exception("Not a valid action of GLFW");
    }
}

} // KGVR
