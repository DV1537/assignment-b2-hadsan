#include "Func.h"

// Function storing displaying digits
void displayInput(int*arr)
{
   
    std::ifstream InputFile;
    InputFile.open("Input.txt");
    int sum;
    int average;
    int SIZE; 
    int nrOfElements; 
    std::string line;
    
    
    while (std::getline(InputFile,line))
    {
        arr=new int [SIZE];
        SIZE = line.size();
        
        nrOfElements = (SIZE +1) /2; 
    

        for(int i=0;i<SIZE;i++)
        {
    
            if(isdigit(line[i]))
            {
                 sum+=line[i];
    
            }
 
        }
        average = sum/((line.size() +1) /2);
        
        int x=0;
        for(int i=0;i<SIZE;i++)
        {
          
            if(line[i]>average)
            {
                arr[i-x]=line[i]<<'\n';

            }  
            x++;
        }
        std::cout << "Input: " << line << '\n';
        std::cout << "Output: " << " ";
        for(int i=0; i<nrOfElements;i++)
        {
            std::cout<< arr[i] << " ";
        }
        std::cout << '\n';
        delete [] arr;
        arr = 0;
       
    }
 

    InputFile.close();

}