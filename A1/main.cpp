#include <iostream>
#include <fstream>
#include <cmath>

/**
 * The program reads numbers from a file and prints the sum of them
 * Example: main.exe ./tests/input.in
 * @param  argc [description]
 * @param  argv [description]
 * @return      [description]
 */
int main(int argc, const char* argv[])
{
    int space = 1;
    int sub = 0;
    double sum = 0;
    double average = 0;
    double nums = 0;
    double *arr;
    arr = new double[space];
    double *temparr;
    temparr= new double[space];

    std::ifstream inputFile;

    inputFile.open(argv[1]);

    // To test if file was actually opened, otherwise return 1.
    if(inputFile) 
    {

        while ((inputFile >> nums)) 
        {
            // Testing if input is a number and not a char. Otherwise return 1.
            if(isdigit(nums))
            {
                // Dynamically allocate new subscript one by one if the array is filled. 
                if (sub == space)
                {
                    space++;

                    for (int i = 0; i < sub; i++)
                    {
                        temparr[i] = arr[i];
                    }

                    delete[] arr;
                    arr = 0;
                    arr = new double[space];

                    for (int i = 0; i < sub; i++)
                    {
                        arr[i] = temparr[i];
                    }

                    delete[] temparr;
                    temparr = 0;
                    temparr = new double[space];
                }
            
                for(int i=0; i<space;i++)
                {
                    arr[i] = nums;
                }
            
                sub++;
            }

            else 
                return 1;
        }

   }

    else
        return 1;
   
    
    inputFile.close();
  

    
    for (int i = 1; i < sub; i++)
    {
        sum += arr[i];
    }

   

    for(int i=1; i<=space;i++)
    {
        std::cout << "\nInput: " << arr[i] << " ";
    }

    average = sum / sub;
     
    std::cout << "\nOutput: ";

    for (int i = 0; i < sub; i++)
    {
        if (arr[i] > average)
        {
            std::cout << arr[i] << " ";
        }
    }
    
    delete[] arr;
    delete [] temparr;

    temparr = 0;
     arr = 0;

    return 0;


}