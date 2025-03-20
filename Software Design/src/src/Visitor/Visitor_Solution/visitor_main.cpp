#include <iostream>
#include <memory>
#include <vector>

#include "Circle.h"
#include "Square.h"
#include "DrawAllShapes.h"

int main(int argc, char** argv){


	std::cout << "---------------------------------------------------------------------" << std::endl;
	std::cout << "OO Solution starting" << std::endl;
	std::cout << "---------------------------------------------------------------------" << std::endl;
	
    using Shapes = std::vector< std::unique_ptr<Shape>>;

    // Creating some shapes
    Shapes shapes;
    shapes.emplace_back( std::make_unique<Circle>( 2.3 ) );
    shapes.emplace_back( std::make_unique<Square>( 1.2 ) );
    shapes.emplace_back( std::make_unique<Circle>( 4.1 ) );

    // Drawing all shapes
    drawAllShapes( shapes );

    return EXIT_SUCCESS;

	// FZER ANOTAÇÕES VISITOR E ENTENDER MELHOR IMPLEMENTAÇÃO


}