#include "Draw.h"
#include <iostream>

void Draw::visit ( Circle const& c ) const {
    std::cout << "Drawing a Circle" << std::endl;
}

void Draw::visit ( Square const& s ) const {
    std::cout << "Drawing a Square" << std::endl;
}