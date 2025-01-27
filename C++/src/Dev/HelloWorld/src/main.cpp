#include <iostream>
#include "Log.h"
#include "Math.cpp"

// Just the declaration.... Need to add to the linker
void Log(const char* message);

int main()
{
    Logr("Hello World!");
    

    std::cout << Multply( 5, 8) << std::endl ;
    std::cin.get();
}