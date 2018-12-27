#include<iostream>
#include<string>
#include <cmath>
#include "Polygon.h"


Polygon::Polygon()
{
  
  
    nrOfPositions = 0;
    ptr = new Coords[nrOfPositions]; 
     type="DEFAULT";
}

Polygon::Polygon(Coords *position,int pointNum) 
{
    // Is used to display the type of the two seperate shapes. 
   if(pointNum == 1)
    {
        type = "Point";
    }
    else if(pointNum == 2)
    {
        type = "Line";
    }
    else if(pointNum == 3)
    {
        type = "Triangle";
    }
    else if(pointNum >= 4)
    {
        type = "Polygon";
    }

    nrOfPositions = pointNum;

    ptr = new Coords[pointNum];
    for(int i = 0; i < pointNum; i++)
    {
        ptr[i] = position[i];
    }
}

Polygon::~Polygon()
{
    if(ptr)
    {
        delete[] ptr;
        ptr = nullptr;
    }
}
// Is used to display type of the newly formed shape.
std::string Polygon::getType()
{
     if(nrOfPositions == 1)
    {
        type = "Point";
    }
    else if(nrOfPositions == 2)
    {
        type = "Line";
    }
    else if(nrOfPositions == 3)
    {
        type = "Triangle";
    }
    else if(nrOfPositions >= 4)
    {
        type = "Polygon";
    }
    return type;
}
// Link: https://stackoverflow.com/questions/29821126/trouble-calculating-perimeter-of-a-polygon-from-reading-x-y-coordinate-input-in
double Polygon::circumference()
{
    double circumference = 0,dx,dy;
    for (int i = 0; i < this->nrOfPositions; ++i)
    {
       int j = (i + 1)%this->nrOfPositions;
       
       dx = pow(ptr[j].xCoord-ptr[i].xCoord,2);
       dy = pow(ptr[j].yCoord-ptr[i].yCoord,2);
       circumference += sqrt(dx + dy);  
    }
    circumference = roundf(circumference * 1000) / 1000;
    return circumference;
}

// link: https://stackoverflow.com/questions/471962/how-do-i-efficiently-determine-if-a-polygon-is-convex-non-convex-or-complex
bool Polygon::isConvex()
{
   
    // will return 0 if convex self-intersecting
    if (this->nrOfPositions < 4)
        return true;

    bool isConvex = false;
 
    for(int i = 0; i < this->nrOfPositions; i++)
    {
        double dx1 = ptr[(i + 2) % this->nrOfPositions].xCoord - ptr[(i + 1) % this->nrOfPositions].xCoord;
        double dy1 = ptr[(i + 2) % this->nrOfPositions].yCoord - ptr[(i + 1) % this->nrOfPositions].yCoord;
        double dx2 = ptr[i].xCoord - ptr[(i + 1) % this->nrOfPositions].xCoord;
        double dy2 = ptr[i].yCoord- ptr[(i + 1) % this->nrOfPositions].yCoord;
        double crossproduct = dx1 * dy2 - dy1 * dx2;

        if (i == 0)
            isConvex = crossproduct > 0;
        else if (isConvex != (crossproduct > 0))
            return false;
    }
    
    return true;
}
// Link: https://www.geeksforgeeks.org/area-of-a-polygon-with-given-n-ordered-vertices/
double Polygon::area()
{
    if(isConvex()==false)
    return -1;

  double area = 0;
  int j = nrOfPositions-1;

  double x[nrOfPositions];
  double y[nrOfPositions];


  for(int i = 0; i < nrOfPositions; i++) 
  {
    x[i] = ptr[i].xCoord;
    y[i] = ptr[i].yCoord;
  }

  for (int i=0; i < nrOfPositions; i++){
    area += (x[j] + x[i]) * (y[j] - y[i]);
    j = i;
  }

   if(area == 0)
    { 
        
        area= -1;
   
    }

   else   
area=std::abs(area/2);

  return area;
 
}

double* Polygon::position()
{
    double *position = new double[2];
    position[0] = 0;
    position[1] = 0;
    for (int i = 0; i < this->nrOfPositions; ++i)
    {
       position[0] += ptr[i].xCoord;
       position[1] += ptr[i].yCoord;
    }
    position[0] /= nrOfPositions;
    position[1] /= nrOfPositions; 
    position[0] = roundf(position[0] * 1000) / 1000;
    position[1] = roundf(position[1] * 1000) / 1000;
    return position;
}

double Polygon::distance(Shape *pointer)
{
    double X1 = this->position()[0];
    double Y1 = this->position()[1];
    double X2 = pointer->position()[0];
    double Y2 = pointer->position()[1];
    double distance = sqrt(pow(X1 - X2, 2) + pow(Y1 - Y2, 2));
    distance = roundf(distance * 1000) / 1000;
    return distance;
}

Polygon &Polygon::operator=(const Polygon &p)
{
    if(this == &p)
    {
        return *this;
    }
    else
    {
        
        this->nrOfPositions = p.nrOfPositions;
        delete[] ptr;
        ptr=nullptr;

        this->ptr=new Coords[p.nrOfPositions];

        for(int i = 0; i < p.nrOfPositions; i++)
        {
           this->ptr[i] = p.ptr[i];
        
        }
        return *this;
    }
   
}

Polygon operator+(const Polygon &p1, const Polygon &p2)
{
    // Total nrofpositions = shape 1 + shape 2
    int nrPos = p1.nrOfPositions + p2.nrOfPositions;   
    // Allocate memory for the sum-shape   
    Coords *pointer = new Coords[nrPos];
    // Add the positions from the first shape   
    for(int i = 0; i < p1.nrOfPositions; i++)                       
    {
        pointer[i] = p1.ptr[i];              
    }
    // Add positions from the second shape
    for(int i = 0; i < p2.nrOfPositions; i++)
    {
        pointer[i + p1.nrOfPositions] = p2.ptr[i]; 
    }
    // Create the new shape containing the sum from the previous two shapes
    Polygon sum(pointer, nrPos);

    delete[] pointer;
    pointer = nullptr;

    return sum;             
}

std::ostream &operator<<(std::ostream &stream, const Polygon &polygon)
{
 

//    Type:
    stream << "Type: "<<polygon.type << "\n";
    
    // Coords:
    for(int i = 0; i < polygon.nrOfPositions; i++)
    {
        
        double xCoord = polygon.ptr[i].xCoord;
        xCoord = round(xCoord * 1000) / 1000;
        double yCoord = polygon.ptr[i].yCoord;
        yCoord = round(yCoord * 1000) / 1000;
        
        stream << "Coord: (" << xCoord << " , " << yCoord << ")" << std::endl;
    }

    stream<<"\n";
    
    return stream;   
}

