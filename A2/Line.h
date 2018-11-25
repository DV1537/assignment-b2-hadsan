#ifndef LINE_H
#define LINE_H
#include "Shape.h"

class Line : public Shape
{
    public:
    Line(double *xCoord, double *yCoord);
    std::string getType();
    Cords position();
};

#endif // !LINE_H