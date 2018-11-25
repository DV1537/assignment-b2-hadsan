#include "Shape.h"
#include "Triangle.h"
#include "Polygon.h"
#include "Point.h"
#include "Line.h"

#include <iostream>
#include <cmath>
#include <fstream>

int main(int argc, const char * argv[])
{
    int SIZE = 2;
    double *arr = new double [SIZE];
    int nrCoords;
    double input;
    
    std::ifstream myReadFile;
    
    myReadFile.open(argv[1]);

    //If file opens - otherwise display error message and exit
    if(myReadFile)
    {
        while (myReadFile >> input)
        {
           // Dynamically allocate new space by x2 array size
            if(nrCoords == SIZE) 
            {
                double *tempArr = new double[SIZE * 2];
                for(int i = 0; i < SIZE; i++)
                {
                    tempArr[i] = arr[i];
                }
                SIZE = SIZE * 2;
                delete [] arr;
                arr = tempArr; 
                tempArr = NULL;
            }
            arr[nrCoords] = input;
            nrCoords++;
        }
        
        if (myReadFile.fail() && !(myReadFile.eof()))
        {
            std::cout << "ERROR." << std::endl;
            exit(EXIT_FAILURE);
        }
        myReadFile.close();
    }
    else
    {
        std::cout << "ERROR.\n"; 
        exit(EXIT_FAILURE);
    }

    double *xCoord = new double[nrCoords/2];
    double *yCoord = new double[nrCoords/2];


    for(int count = 0; count < nrCoords; count++) 
    {
        int coordIndex = count / 2;
        if(count % 2 == 0)
            xCoord[coordIndex] = arr[count];
        else
            yCoord[coordIndex] = arr[count];
    }


    if(nrCoords > 6)
    {
        if(nrCoords % 2 == 0)
        {    
            int verts = (nrCoords / 2);

            Polygon polygon(xCoord, yCoord, verts);

            double Area = polygon.area();

            std::cout << Area << '\n';
        }
    }
    else if(nrCoords == 6)
    {
        Triangle triangle(xCoord, yCoord);
        double Area = triangle.area();
        std::cout << Area << '\n';
    }
    else if(nrCoords == 4)
    {
        Line line(xCoord, yCoord);
        double Area = line.area();
        std::cout << Area << '\n';
    }
    else if(nrCoords == 2) 
    {
        Point point(xCoord, yCoord);
        double Area = point.area();
        std::cout << Area << '\n';
    }
    else
        std::cout << "ERROR" << std::endl; // if not a shape. 


    return 0;

}