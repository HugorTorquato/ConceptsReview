
#include <variant>
#include <vector>

#include "Circle.h"
#include "Shape.h"

using Shapes = std::vector<Shape>;

// we could create abstrations based on variant since there is no cyclic dependency

// Like if Ellipse was defiined. Group similar behaviors under the same group.
// We can easily do this becase we don't need to derive from multiple Visitor base classes, and
//      with this approach, the shape classes ( Circle, Square... ) would be unaffected ( Non-intrusive)


// using RoundShapes = std::variant<Circle, Ellipse>