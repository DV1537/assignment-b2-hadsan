#include "Point.h"
#include <iostream>
#include <string>


Point::Point(double *xCoord, double *yCoord)
{
    this -> xCoord = xCoord;
    this -> yCoord = yCoord;
}

std::string Point::getType()
{
    std::string type = "Point";
    return type;
}

Cords Point::position()
{

    Cords mposition(*xCord, *yCord);
    return mposition;
}