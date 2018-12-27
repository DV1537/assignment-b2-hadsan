#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include "Shape.h"
#include "Point.h"
#include "Line.h"
#include "Polygon.h"
#include "Coords.h"




/*I opted to create  a new headerfile named Coords containing a struct. This is in 
order for me to display my knowledge regarding structs.
Therefor, the xCoord and yCoord are derived from the Coords.h rather than Polygon.h*/

int main(int argc, const char * argv[])
{

    Coords *pPtr = nullptr;
    std::ifstream file;
    std::stringstream sstream;
    std::string line; //One line represents a shape.
    int nrCoords = 0;
    int nrVerts;
    int Shapes=0; //Current number of shapes
    int SIZE = 1;
    double *ptr = new double[SIZE];
    int numberOfShapes = 1; //The capacity size for the polygon pointer. 
    Polygon *polygon = new Polygon[numberOfShapes];
    
    file.open(argv[1]);
    

    //Error check: reading from file.
    if(file)
    {
        //Read from file while the end of file has not been reached. 
        while(!file.eof())
        {
                                              
            sstream.clear();
            std::getline(file, line);
            
            sstream << line;

            //Storing the elements in the ptr
            while(sstream >> ptr[nrVerts])
            {           
                nrVerts++; // counting the number of elements
                if(nrVerts >= SIZE )       //expand
                {
                    SIZE += 1;
                    double *tempptr = new double[SIZE];
                    for(int i = 0; i < SIZE - 1; i++)   
                    {
                        tempptr[i] = ptr[i];
                    }
                               
                    ptr = tempptr;               
                    tempptr = nullptr;
                }
            }
                
            /*Errorheck: numeric values, line containing values, line containing an 
            even number of elements*/
            if(nrVerts == 0 || !sstream.eof())
            {
                std::cout << "Line " << Shapes + 1 << " has no/non-numeric input.\n";
                
                exit(EXIT_FAILURE);
            }
            else if(!(nrVerts % 2 == 0))
            {
                std::cout << "Line " << Shapes + 1 << " contains an uneven number of elements.\n";
                exit(EXIT_FAILURE);
            }
            else{
                
                
                nrCoords = nrVerts / 2;
                pPtr = new Coords[nrCoords];
                for(int i = 0; i < nrCoords; i++)
                {
                    pPtr[i].xCoord = ptr[2 * i];  // distribute the elements into pPtr.
                    pPtr[i].yCoord = ptr[2 * i + 1];
                }

                //Object created to display the shapes vertices and type. 
                Polygon shape(pPtr, nrCoords);
                std::cout<<shape;
                

                
                if(Shapes >= numberOfShapes)
                {
                    numberOfShapes += 1;
                    Polygon *temp = new Polygon[numberOfShapes];  
                    for(int i = 0; i < numberOfShapes - 1; i++)      
                    {
                        temp[i] = polygon[i];
                    }
                    
                    delete []polygon;                //delete old content
                    polygon = temp;               //make pointer point to new array
                    temp = nullptr;
                }
                // byt polygon
                polygon[Shapes] = shape;
                Shapes++;
                nrVerts = 0;
                
                
            }
            //Start over with next line in file
        }
        
    }
    else
    {
        std::cout << "Error opening file\n";
        exit(EXIT_FAILURE);
    }
    

    file.close();
    
    //Add all read polygons together
    Polygon newPolygon;
    for(int i = 0; i < Shapes; i++)
    {
        
        newPolygon = newPolygon + polygon[i];
       
    }
    
    //Print area with 3 decimal digits
    double area = newPolygon.area();
    
    area = round(area * 1000) / 1000;
    std::string type = newPolygon.getType();
   
   std::cout<<"\n New Shape = Shape1 + Shape2";
   std::cout<<"\n--------------------------------";
    std::cout <<"\n type: " << type << std::endl;
    std::cout <<" area: " <<area << std::endl;

    // deallocate all memory
    delete []ptr;
    ptr = nullptr;
    
    delete []pPtr;
    pPtr = nullptr;
    
    delete []polygon;
    polygon = nullptr;

    return 0;
}