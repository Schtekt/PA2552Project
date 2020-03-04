#include <iostream>
#include "Shape.h"
int main()
{
    Shape tst(5);
    int area = tst.getVol();
    std::cout << "Hello world! " << area;

    return 0;
}