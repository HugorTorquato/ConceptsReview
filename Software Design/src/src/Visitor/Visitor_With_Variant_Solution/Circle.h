#pragma once

#include "Point.h"

class Circle
{
    public:
        explicit Circle(double radius) : radius_(radius) {};

        double getRadius() const {return radius_;}
        Point getCenter() const {return center_;}



    private:
        double radius_;
        Point center_{};
};