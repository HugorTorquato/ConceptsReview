#pragma once

enum ShapeType
{
    circle,
    square
};

class Shape
{
    // Protected constructor says that Shae is a base class
    protected:
        explicit Shape(ShapeType type)
            : type_(type) {}

    public:
        virtual ~Shape() = default;

        ShapeType getType() const { return type_; }

    private:
    // Data member of type ShapeType initialized by the constructor
    // can be queried via getType() member function
    // Store the it's type in the form of the enumerations
        ShapeType type_;
};