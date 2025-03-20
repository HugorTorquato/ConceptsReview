#include "Draw.h"

#include <iostream>


void Draw::operator()( Circle const& c ) const
{
    std::cout << "Draw Circle" << std::endl;
}

void Draw::operator()( Square const& c ) const
{
    std::cout << "Draw Circle" << std::endl;
}