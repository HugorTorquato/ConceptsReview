#include <iostream>
#include <cstring>

#include "Log.h"
// #include "Log.h" // Without this definition the compiler desn't know we have the Logr and InitLog functions
#include <Math.h>

// Just the declaration.... Need to add to the linker
// void Log(const char* message);


void MultipllyAndLog(const int a, const int b){
    int result = Multplly(a, b);
    std::cout << result << std::endl ;
}

int main()
{

    Logr("Hey");
    Logr("Hey");
    Logr("Hey");
    Logr("Hey");
    Logr("Hey");

    Logr("");

    for (int i = 0; i < 5; i++ ){
        Logr("Hey");
    }

    Logr("");

    int j = 0;
    bool condition = true;
    for ( ; condition ; ){
        Logr("Hey");
        j++;
        if (j >= 5)
            condition = false;
        
    }

    Logr("");

    int i = 0;
    while(i < 5){
        Logr("Hey");
        i++;
    }

    Logr("");

    int x = 5;
    bool omparisonResoult = x == 5;
    // if (x == 5) 
    if (omparisonResoult) 
    {
        std::cout << " x is 5" << std::endl;
    }

    const char* ptr = "Hello";
    if(!ptr)
        Logr(ptr);
    // else if(ptr == "Hello") // In C++, string literals are stored as arrays of characters, and their type decays into const char*. Comparing a pointer (like ptr) to a string literal using == checks if both pointers point to the same memory address, not if their contents are the same. This leads to unspecified behavior
    else if(strcmp(ptr, "Hello"))
        Logr("Ptr is Hellow"); // Only check this condition if the first one fails
    else   
        Logr("Ptr is Null");


    // This can be simpified ( and the compiler does it )
    // transfor it all into a const value


    InitLog();

    Logr("Hello World!");
    
    int varable = 8;
    std::cout << varable << std::endl;

    char a = 'A';
    char b = 65;
    char c = 65;
    float d = 5.5f; // 4 bytes
    float e = 5.5; // 8 bytes
    bool f = false; // 1 bytes
    std::cout << a << std::endl; // A
    std::cout << b << std::endl; // A
    std::cout << c << std::endl; // 65
    std::cout << d << std::endl; // 5.5
    std::cout << e << std::endl; // 5.5
    std::cout << f << std::endl; // 0
    std::cout << sizeof(bool) << std::endl; // 1

    // unsigner, short, int , long, long long

    // Logr((int)varable);

    // int result = Multplly(2, 3);
    // std::cout << result << std::endl ;
    MultipllyAndLog(2, 3);

    
    // int result2 = Multplly(2, 3);
    // std::cout << result << std::endl ;
    MultipllyAndLog(4, 5);

    
    // int result3 = Multplly(2, 3);
    // std::cout << result << std::endl ;
    MultipllyAndLog(6, 7);


    std::cin.get();
}