#ifndef SHAPE_H
#define SHAPE_H
#include <string>


struct Cords
{
    double x, y;
};

class Shape
{
    protected:
    double *xCoord;
    double *yCoord;
    int pointCount;

    public:
    virtual std::string getType() = 0;
    virtual double area();
    virtual double circumference();
    virtual bool isConvex() = 0;
    virtual Cords position() = 0;
    double distance(Shape* s);
   

};

#endif // !SHAPE_H