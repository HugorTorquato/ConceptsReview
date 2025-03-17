#pragma once

#include "Point.h"
#include "Shape.h"

class Circle : public Shape
{
    public:
        explicit Circle( double radius ) : radius_(radius) {};

        double getRadius() const;
        Point getCenter() const;

        // This method must be implemented.
        // And this is ind of a problem. In this case it's used but could be cases
        // and operations that doesn't requires this operation and we still MUST implement it.
        // Otherwise, create a default case in the base class that covers everything (which is hard)
        void draw() const override;

    private:
        double radius_;
        Point center_;
};