#include "drawAllShapes.h"
#include "ShapeVisitor.h"
#include "Draw.h"

void drawAllShapes(std::vector< std::unique_ptr<Shape> > const& shapes)
{
    for(auto const& shape : shapes){
        shape->accept( Draw{} );
    }
}