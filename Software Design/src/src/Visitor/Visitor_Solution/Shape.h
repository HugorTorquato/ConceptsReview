#pragma once
#include "ShapeVisitor.h"

// The point here is not to have the enum, since the solution is based in OO
// The enum would be used in the switch case in draw all Shapes method, but no need anymore
// the virtual function takes care of calling the correct inhered object of the base class

class Shape
{
    public:
        Shape() = default;
        virtual ~Shape() = default;

        // Add one last method to the shpe hierarchy, the accept
        virtual void accept( ShapeVisitor const& v ) = 0;
};