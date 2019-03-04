#ifndef FIGURE_H
#define FIGURE_H
#include <string>
#include <iostream>
#include "Polygon.h"
#include "BoundingBox.h"

class Figure
{
    private:
        int Shapes;
        int capacity;
        Polygon *pPtr;
    public:
        Figure();
        ~Figure();
        void addShape(Polygon *polygon);
        Polygon getFirstShape();
        void getClosest(Polygon *closestShapes, Polygon &s, int n);
        BoundingBox getBoundingBox();
};

#endif