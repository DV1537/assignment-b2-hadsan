#include "Line.h"
#include <string>


Line::Line(double *xCoord, double *yCoord)
{
    this -> xCoord = xCoord;
    this -> yCoord = yCoord;
}

std::string Line::getType()
{
    std::string type = "Line";
    return type;
}

Cords Line::position()
{
    double avrg_x = (xCoord[0] + xCoord[1])/2;
    double avrg_y = (yCoord[0] + yCoord[1])/2;
    Cords mPosition(avrg_x, avrg_y);
    return mPosition;
}