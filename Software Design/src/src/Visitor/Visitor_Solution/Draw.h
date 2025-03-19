#pragma once
#include "ShapeVisitor.h"

class Draw : public ShapeVisitor
{
        // To add operations, just need to add a new derived class to the shapeVisitor base class
    // in order to add new operations. There is no need to modify the existing classes, just need
    // to create ne ones
    public:
        void visit ( Circle const& c ) const override;
        void visit ( Square const& s ) const override;
        // ...
};