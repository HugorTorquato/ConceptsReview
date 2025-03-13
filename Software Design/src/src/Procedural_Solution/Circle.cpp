#include "Circle.h"

Circle::Circle(double radius)
    : Shape( ShapeType::circle ), radius_(radius)
{}

double Circle::radius() const
{
    return radius_;
} 

Point Circle::center() const 
{
    return center_;
} 