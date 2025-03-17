#pragma once

#include "Point.h"
#include "Shape.h"

class Square : public Shape
{
    public:
        explicit Square( double side ) : side_(side) {} ;

    double getSide() const;
    Point getCenter() const;

    // Implement the virtual override function
    void draw() const override;


    private:
        double side_;
        Point center_;
};