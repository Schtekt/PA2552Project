#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
private:
    int area;
public:
    Shape(int ar = 1);
    int GetArea() const;
};

#endif