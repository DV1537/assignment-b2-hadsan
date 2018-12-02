

#include<string>
#include <cmath>
using namespace std;
#include "Shape.h"
#include "Point.h"

Point::Point(double* points) 
{
    this->points = points;
}

double Point::area()
{
    return -1;
}

std::string Point::getType()
{
    return "Point";
}

double Point::circumference()
{
    return 0;
}

bool Point::isConvex()
{
    //any shape less than 3 vertices is convex
    return false;
}

double* Point::position()
{
    return points;
}

double Point::distance(Shape *pointer)
{
    double X1 = this->position()[0];
    double Y1 = this->position()[1];
    double X2 = pointer->position()[0];
    double Y2 = pointer->position()[1];
    double distance = sqrt(pow(X1 - X2, 2) + pow(Y1 - Y2, 2));
    distance = roundf(distance * 1000) / 1000;
    return distance;
}