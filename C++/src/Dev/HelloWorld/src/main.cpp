#include <iostream>
#include "Log.cpp"

// Just the declaration.... Need to add to the linker
// void Logr(const char* message);

int main()
{
    Log("Hello World!");
    std::cin.get();
}