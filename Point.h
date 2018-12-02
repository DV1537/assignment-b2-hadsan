#ifndef POINT_H
#define POINT_H
#include "Shape.h"


class Point : public Shape 
{
private:
    double* points;


public:
    Point(double* points);
    ~Point();
    std::string getType();
    double area();
    double circumference();
    double* position();
    bool isConvex();
    double distance(Shape *pointer);

};
#endif /* POINT_H */