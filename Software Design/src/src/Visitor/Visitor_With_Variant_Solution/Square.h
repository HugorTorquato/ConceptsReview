#pragma once

#include "Point.h"

class Square
{
    public:
        explicit Square(double side) : side_(side) {};

        double getSide() const {return side_;}
        Point getCenter() const {return center_;}



    private:
        double side_;
        Point center_{};
};