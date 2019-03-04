#include<string>
#include <cmath>
#include "Shape.h"
#include "Line.h"

Line::Line(double* points) 
{
    this->points = points;
}

double Line::area()
{
    double area = sqrt(pow(points[0] - points[2], 2) + pow(points[1] - points[3], 2));
    area = roundf(area * 1000) / 1000;
    return area;
}

std::string Line::getType()
{
    return "Line";
}

double Line::circumference()
{
    return this->area();
}

bool Line::isConvex()
{
    
    return true;
}

double* Line::position()
{
    double *position = new double[2];
    position[0] = (points[0]+points[2])/2;
    position[1] = (points[1]+points[3])/2;
    position[0] = roundf(position[0] * 1000) / 1000;
    position[1] = roundf(position[1] * 1000) / 1000;
    return position;
}

double Line::distance(Shape *pointer){
    double X1 = this->position()[0];
    double Y1 = this->position()[1];
    double X2 = pointer->position()[0];
    double Y2 = pointer->position()[1];
    double distance = sqrt(pow(X1 - X2, 2) + pow(Y1 - Y2, 2));
    distance = roundf(distance * 1000) / 1000;
    return distance;
}
