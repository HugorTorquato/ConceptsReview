#include "DrawAllShapes.h"
#include "Circle.h"
#include "Draw.h"

#include <iostream>
#include <variant>

void drawAllShapes(Shapes const& shapes)
{
    for (auto const& shape : shapes) 
    {
        // Refactored to make use of the visit(). Applying the Draw visitor
        // onto all variants stored in a vector.

        // The std::visitor() peforms the necessary type dispatch for you. If
        // the variant is a Circle, it'll call the Draw::operator() for circles... and so on

        // 

        std::visit( Draw{}, shape);
    }

    std::cout << std::endl;

     // Or we canimplement things here
    for (auto const& shape : shapes) 
    {
        // get_if is a good way to retrieve types from the variant, if not found returns a nullptr
        if(const Circle* circle = std::get_if<Circle>(&shape))
        {
            std::cout << "Draw Circle" << std::endl;
        }
        if(const Square* square = std::get_if<Square>(&shape))
        {
            std::cout << "Draw Square" << std::endl;
        }
    }
}