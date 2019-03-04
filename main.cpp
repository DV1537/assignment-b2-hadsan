#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include "Shape.h"
#include "Point.h"
#include "Line.h"
#include "Polygon.h"
#include "Figure.h"
#include "BoundingBox.h"
#include "Coords.h"





/*I opted to create  a new headerfile named Coords containing a struct. This is in 
order for me to display my knowledge regarding structs.
Therefor, the xCoord and yCoord are derived from the Coords.h rather than Polygon.h*/

int main(int argc, const char * argv[])
{
    //_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

     int SIZE = 1;
    double *ptr = new double[SIZE];
    Position *pPtr = nullptr;
   std::ifstream file;
    std::stringstream sstream;
    std::string line = "";
    int nrCoords = 0;
    int nrVerts = 0;
    int Shapes = 0;
    Figure figure;
    double xCoord;
    double yCoord;
    Polygon firstShape; 
   
    
    file.open(argv[1]);
    

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
                    delete []ptr;              
                    ptr = tempptr;              
                    tempptr = nullptr;
                }
            }

            /*Errorheck: numeric values, line containing values, non-negative numbers, line containing an 
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
            else
            {
                nrCoords = nrVerts / 2;
                pPtr = new Position[nrCoords];
                for(int i = 0; i < nrCoords; i++)
                {
                    pPtr[i].xCoord = ptr[2 * i];  // distribute the elements into pPtr.
                    pPtr[i].yCoord = ptr[2 * i + 1];
                }

                
                Polygon *polygonObj = new Polygon(pPtr, nrCoords);

				delete[]pPtr;
				pPtr = nullptr;
				
				
				if (Shapes == 0)
				{
					firstShape = *polygonObj;
				}


                figure.addShape(polygonObj);
                delete polygonObj;
                polygonObj = nullptr;
				delete pPtr;
				pPtr = nullptr;

                Shapes++;

                nrVerts = 0;
            }
            //Start over with next line in file
        }
    

    file.close();
  

  
	const int n = 3;
	Polygon closestShapes[n];   // the number of shapes to display 
  
	figure.getClosest(closestShapes, firstShape, n);

    std::cout << " Closest shape:\n";

	for (int i = 0; i < n; i++)
	{
		std::cout << "\n#" << i + 1 << " " << closestShapes[i] << std::endl;
	}

    //Free memory
    delete []ptr;

    return 0;
}
