#pragma once

#include "Circle.h"
#include "Shape.h"

struct Draw
{
    // Implement one operator() for each type; But this time there is no need to implement
    // any base class and no need to override any virtual function.
    void operator()( Circle const& c ) const;
    void operator()( Square const& c ) const;
    //...

    // It is strange, but we don't need to implement one operator() for each type. We can
    // combine them into one function and also chose the return type of the function. Right here
    // and not in some base class on the path ( Losing coupling )

    


};