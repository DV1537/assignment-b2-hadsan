#include <iostream>
#include <string>
#include <fstream>
#include "Point.h"
#include "Line.h"
#include "Triangle.h"
#include "Polygon.h"
#include "Shape.h"


using namespace std;

int getPoints(std::string,double*&);
int getPoints(string filename,double *&points)
{
    double num;
    int SIZE = 0;
    ifstream input;
    input.open(filename);
    
    if(input.is_open())
    { 
        //get size
        while (input >> num)
        {
            SIZE++;
        } 
        input.close();
        
        points = new double[SIZE];
        input.open(filename);
        if(input.is_open())
        {
            int i = 0;
            while (input >> points[i])
            {
                i++;
            } 
            input.close();
        
        }
    }
    else
    {
        std::cout << "ERROR" << std::endl;
    }
    return SIZE;
}

void getShape(Shape*);
void getShape(Shape *pointer)
{
    /* Test shape for distance calculation*/
    Shape *pointer1;
    double* testpoint = new double[2];
    testpoint[0] =0;
    testpoint[1] = 0;
    pointer1 = new Point(testpoint);
    
    cout<<" -Shape type: "<< pointer->getType()<<endl;
    cout<<" -Convex: "<<pointer->isConvex()<<endl;
    cout<<" -Circumference: "<<pointer->circumference()<<endl;
    cout<<" -Area: "<<pointer->area()<<endl;
    cout<<" -Center point:  ("<<pointer->position()[0]<<","<<pointer->position()[1]<<")"<<endl;
    cout<<" -Distance from test point ("<<testpoint[0]<<","<<testpoint[1]<<"):  is "<<pointer->distance(pointer1)<<endl;
    
    
}