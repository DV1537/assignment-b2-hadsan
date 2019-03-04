#ifndef POLYGON_H
#define POLYGON_H
#include "Shape.h"
#include "BoundingBox.h"




class Polygon : public Shape 
{
protected:
    double* points;
    double x;
    double y;
    int pointNum;
    std::string type;
    Position *ptr;
    

public: 
double* xCoord;
double* yCoord;

     Polygon();
    Polygon(Position *position, int pointNum);
    Polygon(double xcoord, double ycoord);
    ~Polygon();
    std::string getType();
    double area();
    double circumference();
    double* position();
    bool isConvex();
    double distance(Shape *pointer);
    BoundingBox getBoundingBox(); 

    Polygon& operator=(const Polygon &p);

    friend Polygon operator+(const Polygon &p1, const Polygon &p2);

    friend std::ostream &operator<<(std::ostream &stream, const Polygon &p);

};

#endif /* POLYGON_H */