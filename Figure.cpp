#include <iostream>
#include "Figure.h"
#include "Polygon.h"
#include "functions.h"

// Without it, a bad_array length error occurs. 
Figure::Figure()
{
    pPtr= nullptr;
     Shapes= 0;
      capacity = 0;

}

// Get the  first shape.  
Polygon Figure::getFirstShape()
{
    return pPtr[0];
}


void Figure::addShape(Polygon *polygon)
{
    if(Shapes >= capacity)
    {
        capacity += 1;
        Polygon *tempPtr = new Polygon[capacity];
        for(int i = 0; i < Shapes; i++)
        {
            tempPtr[i] = pPtr[i];
        }
        delete[] pPtr;
        pPtr = tempPtr;
        tempPtr = nullptr;
    }
    pPtr[Shapes] = *polygon;
    Shapes++;
}

// Get the top left corner and bottom right corner. 
BoundingBox Figure::getBoundingBox()
{
    double minimumX = 0.0, maximumX = 0.0, minimumY = 0.0, maximumY = 0.0;

   
    for(int i = 0; i < Shapes; i++)
    {
        BoundingBox minimumRect;
		minimumRect = pPtr[i].getBoundingBox();
         //Go through all the shapes in the totalfigure.
        if(minimumRect.tLCorner.xCoord < minimumX)
        {
            minimumX = minimumRect.tLCorner.xCoord;  
        }
        if(minimumRect.bRCorner.xCoord > maximumX)
        {
           maximumX = minimumRect.bRCorner.xCoord;      
        }
        if(minimumRect.bRCorner.yCoord < minimumY)
        {
			minimumY = minimumRect.bRCorner.yCoord;         
        }
        if(minimumRect.tLCorner.yCoord > maximumY)
        {
            maximumY = minimumRect.tLCorner.yCoord;    
        }

    }
    //Divide the points into the tl vertex and br vertex.
    Coords tl(minimumX, maximumY);
    Coords br(maximumX, minimumY);
    
	BoundingBox minimumRect;
	minimumRect.tLCorner = tl;
	minimumRect.bRCorner = br;

    return minimumRect;
    
}


// Extention of Figure Class. 
//Returns the nearest shapes.  (s = location in my method!)
void Figure::getClosest(Polygon *closestShapes, Polygon &s, int n)
{
    
    // recursive sorting algorithm.
    quickSort(pPtr, 0, Shapes - 1, s);

//    saves the nearest shapes in order. 
    for(int i = 0; i < n; i++)
    {
        closestShapes[i] = pPtr[i + 1];
    }

}


// Destructor
Figure::~Figure()
{
    if(pPtr)
    {
        delete[] pPtr;
        pPtr = nullptr;
    }
}
