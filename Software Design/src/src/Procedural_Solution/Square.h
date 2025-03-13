#pragma once

#include "Point.h"
#include "Shape.h"

class Square : public Shape
{
    public:
        explicit Square(double side) 
            : Shape(ShapeType::square), side_(side) {};

        double getSide() const;
        Point center() const;


    private:
        double side_;
        Point center_;
};