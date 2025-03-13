#pragma once

#include "Point.h"
#include "Shape.h"

class Square : public Shape
{
    public:
        explicit Square(double side) 
            : Shape(ShapeType::square), side_(side) {};

        ~Square() {};

        double getSide() const;
        Point center() const;


    private:
        double side_;
        Point center_;
};