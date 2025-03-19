#pragma once

class Square;
class Circle;

class ShapeVisitor
{
    public:
        virtual ~ShapeVisitor() = default;

        virtual void visit( Circle const&) const = 0;
        virtual void visit( Square const&) const = 0;
};