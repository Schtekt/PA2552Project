#include <iostream>
#include "Shape.h"
int main()
{
    Shape tst(5);
    int area = tst.getVol();
	_ASSERT(area == 5);
    std::cout << "Hello world! " << area;

    return 0;
}