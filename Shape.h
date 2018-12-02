#ifndef SHAPE_H
#define SHAPE_H
#include<string>

class Shape 
{
    private:


public:
    virtual std::string getType() =0;
    virtual double area()=0;
    virtual double circumference()=0;
    virtual double* position()=0;
    virtual bool isConvex()=0;
    virtual double distance(Shape *pointer)=0;

};
#endif /* SHAPE_H */