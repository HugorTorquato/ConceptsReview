#include "Circle.h"
#include "Square.h"
#include "Shapes.h"
#include "DrawAllShapes.h"

#include <chrono>
#include <iostream>

int main()
{
    std::cout << "---------------------------------------------------------------------" << std::endl;
	std::cout << "Visitor with std::variant() Solution starting Using Visit" << std::endl;
	std::cout << "---------------------------------------------------------------------" << std::endl;

    auto start = std::chrono::high_resolution_clock::now();
    Shapes shapes;

    shapes.emplace_back( Circle{ 2.3 });
    shapes.emplace_back( Square{ 1.2 });
    shapes.emplace_back( Circle{ 4.1 });

    drawAllShapesVisitor(shapes);

    auto end = std::chrono::high_resolution_clock::now();

    // Calculate duration in milliseconds
    std::chrono::duration<double, std::milli> duration = end - start;

    std::cout << "Execution time: " << duration.count() << " ms\n";

    std::cout << "---------------------------------------------------------------------" << std::endl;
	std::cout << "Visitor with std::variant() Solution starting Using Get_if" << std::endl;
	std::cout << "---------------------------------------------------------------------" << std::endl;

    auto start2 = std::chrono::high_resolution_clock::now();
    Shapes shapes2;

    shapes2.emplace_back( Circle{ 2.3 });
    shapes2.emplace_back( Square{ 1.2 });
    shapes2.emplace_back( Circle{ 4.1 });

    drawAllShapesGetIf(shapes);

    auto end2 = std::chrono::high_resolution_clock::now();

    // Calculate duration in milliseconds
    std::chrono::duration<double, std::milli> duration2 = end2 - start2;

    std::cout << "Execution time: " << duration2.count() << " ms\n";

}