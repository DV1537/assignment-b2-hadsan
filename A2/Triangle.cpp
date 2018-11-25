#include "Triangle.h"
#include <iostream>
#include <cmath>

Triangle::Triangle(double *xCoord, double *yCoord)
{
    this -> xCoord = xCoord;
    this -> yCoord = yCoord;
}

std::string Triangle::getType()
{
    std::string type = "Triangle";
    return type;
}

double Triangle::area()
{
    //Calulate the distance from point 1 to point 2 
    double x1tox2 = pow(xCoord[0] - xCoord[1], 2);
    double y1toy2 = pow(yCoord[0] - yCoord[1], 2);
    double distance1to2 = sqrt(x1tox2 + y1toy2);

    //Calulate the distance from point 2 to point 3 
    double x2tox3 = pow(xCoord[1] - xCoord[2], 2);
    double y2toy3 = pow(yCoord[1] - yCoord[2], 2);
    double distance2to3 = sqrt(x2tox3 + y2toy3);

    //Calulate the distance from point 3 to point 1
    double x3tox1 = pow(xCoord[2] - xCoord[0], 2);
    double y3toy1 = pow(yCoord[2] - yCoord[0], 2);
    double distance3to1 = sqrt(x3tox1 + y3toy1);

    double s = (distance1to2 + distance2to3 + distance3to1) / 2.0;
    double area = sqrt(s * (s - distance1to2) * (s - distance2to3) * (s - distance3to1));

    return area;
}

double Triangle::circumference()
{
    //Calulate the distance from point A to point B 
    double x1tox2 = pow(xCoord[0] - xCoord[1], 2);
    double y1toy2 = pow(yCoord[0] - yCoord[1], 2);
    double distance1to2 = sqrt(x1tox2 + y1toy2);

    //Calulate the distance from point B to point C 
    double x2to3 = pow(xCoord[1] - xCoord[2], 2);
    double y2toy3 = pow(yCoord[1] - yCoord[2], 2);
    double distance2to3 = sqrt(x2to3 + y2toy3);

    //Calulate the distance from point C to point A
    double x3tox1 = pow(xCoord[2] - xCoord[0], 2);
    double y3toy1 = pow(yCoord[2] - yCoord[0], 2);
    double distance3to1 = sqrt(x3tox1 + y3toy1);

    double circumference = (distance1to2 + distance2to3 + distance3to1);

    return circumference;
}

Cords Triangle::position()
{
    double centerX = (xCoord[0] + xCoord[1] + xCoord[2]) / 3;
    double centerY = (yCoord[0] + yCoord[1] + yCoord[2]) / 3;

    Cords position;
    position.x = centerX;
    position.y = centerY;

    return position;
}

bool Triangle::isConvex()
{
    return true;
}