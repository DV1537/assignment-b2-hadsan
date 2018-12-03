#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Point.h"
#include "Line.h"
#include "Triangle.h"
#include "Polygon.h"
#include "Shape.h"


using namespace std;

int nrOfShapes(std::string);
int nrOfShapes(string filename)
{
    int shapes;
    ifstream input;
    string line;
    input.open(filename);
    stringstream shape;

    while(getline(input,line))
    shapes++;

    return shapes;

}

int getFirstPoints(std::string,double*&);
int getFirstPoints(string filename,double *&points)
{

    int SIZE = 0;
    ifstream input;
    input.open(filename);

    if(input)
    {
        string line;

        if(getline(input, line))
        {
            istringstream shape(line);

            double coords;

            while(shape>>coords)
            if(!isspace(coords))
            {
                SIZE++;
            }
       
        }

    }

    input.close();

    points = new double[SIZE];
    int i = 0;
    input.open(filename);
    if(input.is_open())
    {
            
        while (input >> points[i] && i<SIZE)
        {
            i++;
        } 
        
        input.close();
    }
    else
    {
        std::cout << "ERROR" << std::endl;
  
    }

     return SIZE; 
}
  
// Second shape
int getSecondPoints(std::string,double*&);
int getSecondPoints(string filename,double *&points)
{
    double num;
    string line;
    int SIZE = 0;
    ifstream input;
    input.open(filename);
    getline(input,line);

    if(input)
    {
        while(input>>num)
        {
            istringstream shape(line);
            if(!isspace(num))
            {
                SIZE++;
            }
        }

    }

    input.close();

    points = new double[SIZE];
    int i = 0;
    input.open(filename);
    getline(input,line);
    if(input.is_open())
    {
            
        while (input >> points[i] && i<SIZE)
        {
            i++;
        } 
        
        input.close();
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
    Shape *pointer1;
  
    cout<<" -Shape type: "<< pointer->getType()<<endl;
    cout<<" -Area: "<<pointer->area()<<endl; 
}

void getTotalPoints(std::string, int&, Shape*&, double *&);  
void getTotalPoints(string filename, int &totalSize, Shape *&pointer, double *&points)
{
    ifstream input;
    points = new double[totalSize];
    int i = 0;
    input.open(filename);
    if(input.is_open())
    {
            
        while (input >> points[i] && i<totalSize)
        {
            i++;
        } 

        input.close();
    }
    else
    {
        std::cout << "ERROR" << std::endl;
    }
   
    cout<<"\n***********************************\n";
    cout<<"The points are: ";
    for(int i =0;i<totalSize;i+=2)
    {
        cout<<"("<<points[i]<<","<<points[i+1]<<") ";
    }
    cout<<endl<<endl;
    if(totalSize%2==0 && totalSize > 0)
    {
        if(totalSize==2)
        { // A point = 2 coordinates
            pointer = new Point(points);
        }
        else if(totalSize==4)
        { // A Line = 4 coordinates
            pointer = new Line(points);
        }
        else if(totalSize==6)
        { // A Triangle = 6 coordinates
            pointer = new Triangle(points);
        }
        else
        { // A Polygon = more than 6 coordinates
            pointer = new Polygon(points,totalSize/2);
        }
                   
    }
    else
    {
        std::cout<<"Error! Provide even numbers in order to create points.";
    }

    input.close();
}