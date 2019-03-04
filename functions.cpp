#include "Functions.h"

//Recursive sorting algortihm: quick sort
void quickSort(Polygon *sort, int low, int high, Polygon &location)
{
	if (low < high)
	{
		//gets the pivot point (p)
		int p = partition(sort, low, high, location);

		//Separately sort elements before pivot point and after pivot point 
		quickSort(sort, low, p - 1, location);
		quickSort(sort, p + 1, high, location);
	}
}

int partition(Polygon *arr, int low, int high, Polygon &location)
{
	int pivotValue = arr[low].distance(&location);
	int pivotPosition = low;

	for (int i = low + 1; i <= high; i++)
	{
		if(arr[i].distance(&location) < pivotValue)
		{
			//Swapping.
			Polygon tempptr;
            tempptr = arr[pivotPosition + 1];
			arr[pivotPosition + 1] = arr[i];
			arr[i] = tempptr;

			
			tempptr = arr[pivotPosition];
			arr[pivotPosition] = arr[pivotPosition + 1];
			arr[pivotPosition + 1] = tempptr;
			
			pivotPosition++;
		}
	}
	return pivotPosition;
} 