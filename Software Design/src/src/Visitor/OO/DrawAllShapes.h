#pragma once

#include <vector>
#include <memory>

#include "Shape.h"

void drawAllShapes(std::vector< std::unique_ptr<Shape> > const& shapes);