#pragma once

// The point here is not to have the enum, since the solution is based in OO
// The enum would be used in the switch case in draw all Shapes method, but no need anymore
// the virtual function takes care of calling the correct inhered object of the base class

class Shape
{
    public:
        Shape() = default;
        virtual ~Shape() = default;

        // Defining the draw function now as a virtual, so it MUST be implemented in
        // all inhered classes
        virtual void draw() const = 0;
};