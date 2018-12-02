#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Shape.h"


class Triangle : public Shape 
{
private:
    double* points;

public:
    Triangle(double* points);
    double area();
    double circumference();
    double distance(Shape *pointer);
    std::string getType();
     double* position();
    bool isConvex();
};

#endif /* TRIANGLE_H */