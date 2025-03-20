#include "Circle.h"
#include "Square.h"
#include "Shapes.h"
#include "DrawAllShapes.h"

#include <iostream>

int main()
{
    std::cout << "---------------------------------------------------------------------" << std::endl;
	std::cout << "Visitor with std::variant() Solution starting" << std::endl;
	std::cout << "---------------------------------------------------------------------" << std::endl;

    Shapes shapes;

    shapes.emplace_back( Circle{ 2.3 });
    shapes.emplace_back( Square{ 1.2 });
    shapes.emplace_back( Circle{ 4.1 });

    drawAllShapes(shapes);

}