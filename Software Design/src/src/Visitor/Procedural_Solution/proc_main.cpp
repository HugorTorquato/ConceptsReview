#include <chrono>
#include <iostream>
#include <memory>
#include <vector>

#include "Circle.h"
#include "Square.h"
#include "DrawAllShapes.h"


int main(int argc, char** argv){

	std::cout << "---------------------------------------------------------------------" << std::endl;
	std::cout << "Procedural Solution starting" << std::endl;
    std::cout << "---------------------------------------------------------------------" << std::endl;

    auto start = std::chrono::high_resolution_clock::now();
    using Shapes = std::vector< std::unique_ptr<Shape>>;

    // Creating some shapes
    Shapes shapes;
    shapes.emplace_back( std::make_unique<Circle>( 2.3 ) );
    shapes.emplace_back( std::make_unique<Square>( 1.2 ) );
    shapes.emplace_back( std::make_unique<Circle>( 4.1 ) );

    // Drawing all shapes
    drawAllShapes( shapes );

    auto end = std::chrono::high_resolution_clock::now();

    // Calculate duration in milliseconds
    std::chrono::duration<double, std::milli> duration = end - start;

    std::cout << "Execution time: " << duration.count() << " ms\n";

    return EXIT_SUCCESS;








	return 0;
}