#pragma once

#include "Point.h"
#include "Shape.h"

class Circle : public Shape
{
    public:
        explicit Circle(double radius)
            : Shape( ShapeType::circle ), radius_(radius)
        {};

        // This const means that the methods CANNOT modify any member variables
       double radius() const;
       Point center() const;
       

    private:
        double radius_;
        Point center_{};
};