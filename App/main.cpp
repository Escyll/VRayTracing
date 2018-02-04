#define _USE_MATH_DEFINES
#include <cmath>

#include <iostream>
#include <algorithm>

#include "RayTracer.h"
#include "GLWindowRenderer.h"

int main(void)
{
    int dim = 768;
    KGVR::GLWindowRenderer glWindowRenderer(dim, dim);

    float* pixelData = new float[dim*dim*4];
    std::fill_n(pixelData, dim*dim*4, 1.f);
    KGVR::RayTracer tracer(dim, dim);

    /* Loop until the user closes the window */
    while (!glWindowRenderer.shouldClose())
    {
        double deltaX, deltaY;
        std::tie(deltaX, deltaY) = glWindowRenderer.getMouseDelta();
        auto turnValue = 2.0*M_PI * deltaX / 6000.0;
        tracer.getCamera()->turn(static_cast<float>(turnValue));
        auto pitchValue = 2.0*M_PI * deltaY / 6000.0;
        tracer.getCamera()->pitch(static_cast<float>(pitchValue));
        tracer.render(pixelData);
        glWindowRenderer.render(pixelData);
    }

    glWindowRenderer.terminate();

    delete[] pixelData;
    return 0;
}
