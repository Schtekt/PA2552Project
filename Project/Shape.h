#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
private:
    int volume;
public:
    Shape(int vol = 1);
    int getVol();
};

#endif