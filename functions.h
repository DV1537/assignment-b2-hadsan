#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "Figure.h"

void quickSort(Polygon *sort, int low, int high, Polygon &location);

int partition(Polygon *arr, int low, int high, Polygon &location);

#endif