#include "Shape.h"

Shape::Shape(int vol)
{
    volume = vol;
}

int Shape::getVol() const
{
    return volume;
}