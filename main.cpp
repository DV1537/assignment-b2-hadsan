#include "Functions.cpp"

// MAIN
int main(int argc, char const *argv[])
{ 
    Shape *pointer;
    double* points;
    int SIZE = getPoints(argv[1],points);
    cout<<"The points are: ";
    for(int i =0;i<SIZE;i+=2){
        cout<<"("<<points[i]<<","<<points[i+1]<<") ";
    }
    cout<<endl<<endl;
    if(SIZE%2==0 && SIZE > 0){
        if(SIZE==2){ // A point = 2 coordinates
            pointer = new Point(points);
        }
        else if(SIZE==4){ // A Line = 4 coordinates
            pointer = new Line(points);
        }
        else if(SIZE==6){ // A Triangle = 6 coordinates
            pointer = new Triangle(points);
        }
        else{ // A Polygon = more than 6 coordinates
            pointer = new Polygon(points,SIZE/2);
        }
        getShape(pointer);
    }
    else{
        std::cout<<"Error! Provide even numbers in order to create points.";
    }
     
    return 0;
}


// FUNCTIONS
