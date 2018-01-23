#include <RayTracer.h>
#include <random>

#include "GLWindowRenderer.h"

int main(void)
{
    int dim = 768;
    KGVR::GLWindowRenderer glWindowRenderer(dim, dim);
    if (glWindowRenderer.init() != 0)
        return -1;
    float* pixelData = new float[dim*dim*3];
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
