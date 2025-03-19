#include "Square.h"

#include <iostream>

double Square::getSide() const{
    return side_;
}

Point Square::getCenter() const{
    return center_;
}

void Square::accept( ShapeVisitor const& v )
{ 
    v.visit( *this ); 
};