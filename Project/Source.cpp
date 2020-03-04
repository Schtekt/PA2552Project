#include <iostream>
#include "Shape.h"
#include <cassert>
int main()
{
    Shape tst(5);
    int area = tst.getVol();
	assert(area == 5);
    std::cout << "Hello world! " << area;

    return 0;
}