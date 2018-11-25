#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Shape.h"

class Triangle : public Shape
{
    public: 
    Triangle(double *xCoord, double *yCoord);
    std::string getType();
    double area();
    double circumference();
    Cords position();
    bool isConvex();
};

#endif // !TRIANGLE_H