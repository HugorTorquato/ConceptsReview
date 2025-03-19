#pragma once

#include "Point.h"
#include "Shape.h"

class ShapeVisitor;

class Square : public Shape
{
    public:
        explicit Square( double side ) : side_(side) {} ;

        double getSide() const;
        Point getCenter() const;

        void accept(ShapeVisitor const& v) override;

    private:
        double side_;
        Point center_;
};