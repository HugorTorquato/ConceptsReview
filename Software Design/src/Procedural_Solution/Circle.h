#pragma once

#include <Point.h>
#include <Shape.h>

// #inherits from Shape
class Circle : public Shape
{
    public:
        explicit Circle(double radius)
            : Shape( ShapeType::circle ), radius_(radius){}

       double radius() const {return radius_;} 
       Point center() const {return center_;} 
       

    private:
        double radius_;
        Point center_{};
};