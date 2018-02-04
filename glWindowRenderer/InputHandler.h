#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <map>
#include "GLFW/glfw3.h"

namespace KGVR {

class InputHandler
{
public:
    enum class KeyAction
    {
        Pressed,
        Released,
        Repeated
    };

    enum class Key
    {
        A,
        D,
        S,
        W,
        R,
        LeftAlt,
        LeftControl,
        LeftShift,
        Spacebar,
        Unmapped
    };

    InputHandler(GLFWwindow* window);
    static Key mapGLFWToKey(int key);
    static KeyAction mapGLFWToAction(int action);

    bool getKeyAction(Key, KeyAction) const;
    std::tuple<float, float> getMouseDelta();

    void handleKeyAction(InputHandler::Key key, InputHandler::KeyAction action);
    void handleMouseAction(float currentMouseX, float currentMouseY);

private:
    InputHandler();
    float m_mouseSensitivity, m_previousMouseX, m_previousMouseY;
    int m_monitorWidth, m_monitorHeight;
    std::tuple<float, float> m_mouseDelta;
    std::map<Key, bool> m_pressedKeys;
    std::map<Key, bool> m_repeatingKeys;
};

} // KGVR

#endif // INPUTHANDLER_H
