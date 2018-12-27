#ifndef POLYGON_H
#define POLYGON_H
#include "Shape.h"
#include "Triangle.h"


class Polygon : public Shape 
{
private:
    double* points;
    double* xCoords;
    double* yCoords;
    int pointNum;
    int nrOfPositions;
    std::string type;
    Coords *ptr;

public: 
     Polygon();
    Polygon(Coords *position, int pointNum);
    ~Polygon();
    std::string getType();
    double area();
    double circumference();
    double* position();
    bool isConvex();
    double distance(Shape *pointer);

    Polygon& operator=(const Polygon &p);

    friend Polygon operator+(const Polygon &p1, const Polygon &p2);

    friend std::ostream &operator<<(std::ostream &stream, const Polygon &p);



};

#endif /* POLYGON_H */