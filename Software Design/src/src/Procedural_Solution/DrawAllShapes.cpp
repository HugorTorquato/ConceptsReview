#include "DrawAllShapes.h"
#include "Square.h"
#include "Circle.h"
#include "DrawCircle.h"
#include "DrawSquare.h"



void drawAllShapes(std::vector< std::unique_ptr<Shape> > const& shapes)
{
    for (auto const& shape : shapes)
    {
        switch (shape->getType())
        {
        case ShapeType::circle:
            draw(static_cast<Circle const&>(*shape));
            break;
        case ShapeType::square:
            draw(static_cast<Square const&>(*shape));
            break;
        
        default:
            break;
        }
    }
    
}