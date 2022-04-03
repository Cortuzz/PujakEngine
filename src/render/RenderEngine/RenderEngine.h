//
// Created by cortuzz on 4/1/22.
//

#include <GL/glut.h>
#include <string>
#include "../../primitives/Rect/Rect.h"
#include <iostream>

#ifndef PUJAKENGINE_RENDERENGINE_H
#define PUJAKENGINE_RENDERENGINE_H

using namespace std;


class RenderEngine {
    Rect* rectDrawable = (Rect*) malloc(100);
    int queueSIze = 0;

public:
    RenderEngine() = default;

    RenderEngine(int argc, char **argv,  int width, int height, char* title) {
        glutInit(&argc, argv);
        glutInitWindowSize(width, height);
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
        glutCreateWindow(title);
    }

    void addRectToRenderQueue(Rect rect) {
        rectDrawable[queueSIze] = rect;
        queueSIze++;
    }

    void reshape(int w, int h) {
        glViewport(0, 0, w, h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();

        gluOrtho2D(0, w, 0, h);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
    }

    void render() {
        glClear(GL_COLOR_BUFFER_BIT);

        for (int i = 0; i < queueSIze; i++) {
            Rect rect = rectDrawable[i];
            Point* points = rect.getPoints();
            float* colors = rect.getColorMap();

            glColor3f(colors[0], colors[1], colors[2]);

            glBegin(GL_TRIANGLE_FAN);
                glVertex2d(points[0].x, points[0].y);
                glVertex2d(points[1].x, points[1].y);
                glVertex2d(points[2].x, points[2].y);
                glVertex2d(points[3].x, points[3].y);
            glEnd();
        }

        glutSwapBuffers();
    }
};


#endif //PUJAKENGINE_RENDERENGINE_H
