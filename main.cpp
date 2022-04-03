#include <GL/glut.h>
#include "src/primitives/Rect/Rect.h"
#include "src/render/RenderEngine/RenderEngine.h"

RenderEngine renderEngine;

int main(int argc, char **argv) {
   renderEngine = RenderEngine(argc, argv,  1000, 800, "Pujak Engine");
    float* colorMap = new float[3]{1, 0, 0};

    Rect rect = Rect(50, 100, 70, 90, colorMap);
    Rect rect1 = Rect(0.1, 0.5, 0.7, 0.9, colorMap);

    renderEngine.addRectToRenderQueue(rect);
    renderEngine.addRectToRenderQueue(rect1);

    glutReshapeFunc( [](int w, int h){renderEngine.reshape(w, h);});
    glutDisplayFunc( [](){renderEngine.render();});
    glutMainLoop();
    return 0;
}
