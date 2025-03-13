#include "DrawCircle.h"
#include "Circle.h"

#include <iostream>

// The pointer to the Circle class is constat ( with const after the type )
// Otherwise, (const before the type) the value of the object is constant
void draw( Circle const& c ){
    std::cout << "Draw Circle" << std::endl;
}