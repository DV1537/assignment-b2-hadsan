#ifndef LINE_H
#define LINE_H
#include "Shape.h"


class Line  : public Shape {

private:
    double* points;

public:
    Line(double* points);
    
    std::string getType();
    double area();
    double circumference();
    double* position();
    bool isConvex();
    double distance(Shape *pointer);

};

#endif /* LINE_H */
