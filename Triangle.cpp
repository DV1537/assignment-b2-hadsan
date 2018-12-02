#include<string>
#include <cmath>
#include "Shape.h"
#include "Triangle.h"

Triangle::Triangle(double* points) 
{
    this->points = points;
}

double Triangle::area(){
    double X1 = points[0];
    double Y1 = points[1];
    double X2 = points[2];
    double Y2 = points[3];
    double X3 = points[4];
    double Y3 = points[5];
    
    double side1= sqrt(pow(X1 - X2, 2) + pow(Y1 - Y2, 2));
    double side2 = sqrt(pow(X2 - X3, 2) + pow(Y2 - Y3, 2));
    double side3 = sqrt(pow(X1 - X3, 2) + pow(Y1 - Y3, 2));
    double r=(side1+side2+side3)/2;
	double area=sqrt(r*(r-side1)*(r-side2)*(r-side3));
    
    area = fabs(area);
    area = roundf(area * 1000) / 1000;
    return area;
}
std::string Triangle::getType()
{
    return "Triangle";
}

double Triangle::circumference()
{
    double side1 = sqrt(pow(points[0] - points[2], 2) + pow(points[1] - points[3], 2));
    double side2 = sqrt(pow(points[2] - points[4], 2) + pow(points[3] - points[5], 2));
    double side3 = sqrt(pow(points[4] - points[0], 2) + pow(points[5] - points[1], 2));
    
    double circumference = side1+side2+side3;
    circumference = roundf(circumference * 1000) / 1000;
    return circumference;
}

bool Triangle::isConvex()
{
    
    return true;
}

double* Triangle::position()
{
    double X1 = points[0];
    double Y1 = points[1];
    double X2 = points[2];
    double Y2 = points[3];
    double X3 = points[4];
    double Y3 = points[5];
    
    double *position = new double[2];
    position[0] = (X1+X2+X3)/3;
    position[1] = (Y1+Y2+Y3)/3;
    position[0] = roundf(position[0] * 1000) / 1000;
    position[1] = roundf(position[1] * 1000) / 1000;
    return position;
}

double Triangle::distance(Shape *pointer)
{
    double X1 = this->position()[0];
    double Y1 = this->position()[1];
    double X2 = pointer->position()[0];
    double Y2 = pointer->position()[1];
    double distance = sqrt(pow(X1 - X2, 2) + pow(Y1 - Y2, 2));
    distance = roundf(distance * 1000) / 1000;
    return distance;
}