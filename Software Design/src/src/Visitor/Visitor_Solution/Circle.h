#pragma once

#include "Point.h"
#include "Shape.h"

class ShapeVisitor;

class Circle : public Shape {
    public:
        explicit Circle( double radius ) : radius_(radius) {};

        double getRadius() const;
        Point getCenter() const;

        void accept( ShapeVisitor const& v ) override;

    private:
        double radius_;
        Point center_;
};