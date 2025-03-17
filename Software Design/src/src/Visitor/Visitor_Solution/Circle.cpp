#include "Circle.h"

#include <iostream>

double Circle::getRadius() const
{
    return radius_;
}

Point Circle::getCenter() const
{
    return center_;
}

void Circle::draw() const
{
    std::cout << "Draw Circle OO" << std::endl;
}