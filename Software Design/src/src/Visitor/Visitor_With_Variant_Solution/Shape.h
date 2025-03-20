
// Here is where the actual use of std::variant happens
#include <variant>
#include "Circle.h"
#include "Square.h"

// Since our closed set of types is a set of shapes, variant contains Circle and Square now
using Shape = std::variant<Circle, Square>;