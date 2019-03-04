#ifndef SHAPE_H
#define SHAPE_H
#include<string>


struct Position
{
    double xCoord, yCoord;
};

class Shape 
{
    protected:
        int nrOfPositions=0;
        std::string type;
        Position *Pptr;
        double *xCoord;
        double *yCoord;


    public:
        virtual std::string getType() =0;
        virtual double area()=0;
        virtual double circumference()=0;
        virtual double* position()=0;
        virtual bool isConvex()=0;
        virtual double distance(Shape *pointer)=0;
        void getVertex(Position *ptr) const;  // get the various positions/vertexes for the shapes. 

};
#endif /* SHAPE_H */