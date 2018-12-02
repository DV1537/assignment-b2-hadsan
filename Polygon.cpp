#include<iostream>
#include<string>
#include <cmath>
#include "Shape.h"
#include "Polygon.h"

Polygon::Polygon(double* points,int pointNum) 
{
    this->points = points;
    this->pointNum = pointNum;
    this->xCoords = new double[pointNum];
    this->yCoords = new double[pointNum];
    for(int i =0;i<pointNum*2;i+=2){
        xCoords[i/2] = points[i];
        yCoords[i/2] = points[i+1];
    }
}

Polygon::~Polygon()
{
    delete[] xCoords;
    delete[] yCoords;
}
// https://www.geeksforgeeks.org/area-of-a-polygon-with-given-n-ordered-vertices/
double Polygon::area()
{
    if(isConvex())
    {
          double area = 0;
    int j = this->pointNum -1 ;
    for (int i = 0; i < this->pointNum; ++i)
    {
       
       area += ((xCoords[j]+ xCoords[i] )*  (yCoords[j]-yCoords[i]));
       j = i;
    }
    area = fabs(area/2.0);
    area = roundf(area * 1000) / 1000;
    return area;
    }
  
  else 
  return -1;
}

std::string Polygon::getType()
{
    return "Polygon";
}
// Find link and reference it
double Polygon::circumference(){
    double circumference = 0,dx,dy;
    for (int i = 0; i < this->pointNum; ++i)
    {
       int j = (i + 1)%this->pointNum;
       
       dx = pow(xCoords[j]-xCoords[i],2);
       dy = pow(yCoords[j]-yCoords[i],2);
       circumference += sqrt(dx + dy);  
    }
    circumference = roundf(circumference * 1000) / 1000;
    return circumference;
}
// https://stackoverflow.com/questions/471962/how-do-i-efficiently-determine-if-a-polygon-is-convex-non-convex-or-complex
bool Polygon::isConvex(){
    if (this->pointNum < 4)
        return true;

    bool isConvex = false;

    for(int i = 0; i < this->pointNum; i++)
    {
        double dx1 = xCoords[(i + 2) % this->pointNum] - xCoords[(i + 1) % this->pointNum];
        double dy1 = yCoords[(i + 2) % this->pointNum] - yCoords[(i + 1) % this->pointNum];
        double dx2 = xCoords[i] - xCoords[(i + 1) % this->pointNum];
        double dy2 = yCoords[i]- yCoords[(i + 1) % this->pointNum];
        double crossproduct = dx1 * dy2 - dy1 * dx2;

        if (i == 0)
            isConvex = crossproduct > 0;
        else if (isConvex != (crossproduct > 0))
            return false;
    }
    return true;
}
double* Polygon::position(){
    double *position = new double[2];
    position[0] = 0;
    position[1] = 0;
    for (int i = 0; i < this->pointNum; ++i)
    {
       position[0] += xCoords[i];
       position[1] += yCoords[i];
    }
    position[0] /= pointNum;
    position[1] /= pointNum; 
    position[0] = roundf(position[0] * 1000) / 1000;
    position[1] = roundf(position[1] * 1000) / 1000;
    return position;
}
double Polygon::distance(Shape *pointer){
    double X1 = this->position()[0];
    double Y1 = this->position()[1];
    double X2 = pointer->position()[0];
    double Y2 = pointer->position()[1];
    double distance = sqrt(pow(X1 - X2, 2) + pow(Y1 - Y2, 2));
    distance = roundf(distance * 1000) / 1000;
    return distance;
}






