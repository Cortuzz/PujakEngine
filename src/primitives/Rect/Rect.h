//
// Created by cortuzz on 4/1/22.
//

#include "../Point/Point.h"


#ifndef PUJAKENGINE_RECT_H
#define PUJAKENGINE_RECT_H


class Rect {
    Point* points = new Point[4];
    float* colors = new float[3];

public:
    Rect(float x, float y, float width, float height, float* _colors) {
        points[0] = Point(x, y);
        points[1] = Point(x + width, y);
        points[2] = Point(x + width, y + height);
        points[3] = Point(x, y + height);

        colors = _colors;
    }

    Point* getPoints() {
        return points;
    }

    float* getColorMap() {
        return colors;
    }
};


#endif //PUJAKENGINE_RECT_H
