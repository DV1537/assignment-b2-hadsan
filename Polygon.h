#ifndef POLYGON_H
#define POLYGON_H
#include "Shape.h"


class Polygon : public Shape 
{
private:
    double* points;
    double* xCoords;
    double* yCoords;
    int pointNum;

public:
    Polygon(double* points,int pointNum);
    ~Polygon();
    std::string getType();
    double area();
    double circumference();
    double* position();
    bool isConvex();
    double distance(Shape *pointer);

};

#endif /* POLYGON_H */
