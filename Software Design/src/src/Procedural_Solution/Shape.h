#pragma once

enum ShapeType
{
    circle,
    square
};

class Shape
{
    // - Protected constructor says that this is a base class
    // - The explicit keyword prevents implicit conversions.
        //Preventing accidental conversions from a ShapeType to a Shape object.
    // - Derived classes must call the base class constructor in their
    // initialization lists. If they don't, the compiler will generate an error.
    protected:
        explicit Shape(ShapeType type)
            : type_(type) {}

    public:
        virtual ~Shape() = default;

        ShapeType getType() const { return type_; }

    private:
        ShapeType type_;
};