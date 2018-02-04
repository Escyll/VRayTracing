#define _USE_MATH_DEFINES
#include <cmath>

#include <iostream>
#include <algorithm>

#include <InputHandler.h>
#include "RayTracer.h"
#include "GLWindowRenderer.h"

int main(void)
{
    int dim = 768;
    KGVR::GLWindowRenderer glWindowRenderer(dim, dim);

    const int channels = 4;
    const int bufferSize = dim*dim*channels;
    float* pixelData = new float[bufferSize];
    std::fill_n(pixelData, bufferSize, 1.f);
    KGVR::RayTracer tracer(dim, dim);
    KGVR::InputHandler inputHandler(glWindowRenderer.getWindow());

    /* Loop until the user closes the window */
    while (!glWindowRenderer.shouldClose())
    {
        // TODO => Timings, don't base movements on framerate
        glWindowRenderer.pollEvents();
        if (inputHandler.getKeyAction(KGVR::InputHandler::Key::LeftShift, KGVR::InputHandler::KeyAction::Pressed))
        {
            float turnDelta, pitchDelta;
            std::tie(turnDelta, pitchDelta) = inputHandler.getMouseDelta();
            tracer.getCamera()->turn(turnDelta);
            tracer.getCamera()->pitch(pitchDelta);
        }
        const float movementSpeed = 0.033f;
        if (inputHandler.getKeyAction(KGVR::InputHandler::Key::W, KGVR::InputHandler::KeyAction::Pressed))
            tracer.getCamera()->moveForward(movementSpeed);
        if (inputHandler.getKeyAction(KGVR::InputHandler::Key::S, KGVR::InputHandler::KeyAction::Pressed))
            tracer.getCamera()->moveBackward(movementSpeed);
        if (inputHandler.getKeyAction(KGVR::InputHandler::Key::A, KGVR::InputHandler::KeyAction::Pressed))
            tracer.getCamera()->strafeLeft(movementSpeed);
        if (inputHandler.getKeyAction(KGVR::InputHandler::Key::D, KGVR::InputHandler::KeyAction::Pressed))
            tracer.getCamera()->strafeRight(movementSpeed);
        if (inputHandler.getKeyAction(KGVR::InputHandler::Key::R, KGVR::InputHandler::KeyAction::Pressed))
            tracer.restartSampling();
        if (inputHandler.getKeyAction(KGVR::InputHandler::Key::Spacebar, KGVR::InputHandler::KeyAction::Pressed))
            tracer.getCamera()->moveUp(movementSpeed);
        if (inputHandler.getKeyAction(KGVR::InputHandler::Key::LeftControl, KGVR::InputHandler::KeyAction::Pressed))
            tracer.getCamera()->moveDown(movementSpeed);
        tracer.render(pixelData);
        glWindowRenderer.render(pixelData);
    }

    glWindowRenderer.terminate();

    delete[] pixelData;
    return 0;
}
