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
        tracer.render(pixelData);
        glWindowRenderer.render(pixelData);
    }

    glWindowRenderer.terminate();

    delete[] pixelData;
    return 0;
}
