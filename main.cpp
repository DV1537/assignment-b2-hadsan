#include "Functions.cpp"


int main(int argc, char const *argv[])
{ 
    Shape *pointer;
    double* points;
    int totalSize;
    int nrofshapes =   nrOfShapes("A2.txt");
    int SIZE = getFirstPoints("A2.txt",points);
    
// Draw the two different shapes.
    for(int i=0;i<nrofshapes;i++)
    {
        totalSize+=SIZE;
        cout<<"\n***********************************\n";
        cout<<"The points are: ";
        for(int i =0;i<SIZE;i+=2)
        {
            cout<<"("<<points[i]<<","<<points[i+1]<<") ";
        }
        cout<<endl<<endl;       
        if(SIZE%2==0 && SIZE > 0)
        {
            if(SIZE==2)
            { // A point = 2 coordinates
                pointer = new Point(points);
            }
            else if(SIZE==4)
            { // A Line = 4 coordinates
                pointer = new Line(points);
            }
            else if(SIZE==6)
            { // A Triangle = 6 coordinates
                pointer = new Triangle(points);
            }
            else
            { // A Polygon = more than 6 coordinates
                pointer = new Polygon(points,SIZE/2);
            }
            getShape(pointer);
        }
        else
        {
            std::cout<<"Error! Provide even numbers in order to create points.";
            exit (EXIT_FAILURE);
        }
    
        SIZE = getSecondPoints("A2.txt",points);
    }
 

    // Create the combined shape
    getTotalPoints("A2.txt",totalSize,pointer,points);
    // Display shape-type and area
    getShape(pointer);

    return 0;
}



