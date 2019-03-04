#include "Shape.h"

void Shape::getVertex(Position *ptr) const
{
    for (int i = 0; i < nrOfPositions; i++)
    {
        ptr[i] = Pptr[i];
    }
}