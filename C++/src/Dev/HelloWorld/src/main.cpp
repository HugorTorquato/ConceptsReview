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

// void Increment(int value) // copy the value to a new one
void Increment(int* value) // pass the variable by value and we affect the one received as paramenter
{
    (*value)++; // want to increment the value so need to dereference
    // otherwise it would increase the pointer
}

void Increment2(int& value) // pass the variable by value and we affect the one received as paramenter
{
    value++; // samething as before but easier
}

// structure to represent a data structure
struct PlayerData
{
    int x, y;
};

// #define struct class // wont work kkk everything will be public still
// class Player
class Player
{
    public:
        PlayerData playerData;
        int speed;

    void Move(int xa, int ya)
    {
        // NO need to pass by value because we are going to chenge te object
        // IT ALREADY HAVE ACCESS TO THE CURRENT OBJECT
        playerData.x += xa;
        playerData.y += ya;
    }
};

// Example without class, need to pass the object
void Move( Player& player, int xa, int ya)
{
    // need to pass by value because we are going to chenge te object
    player.playerData.x += xa;
    player.playerData.y += ya;
}

// This variable is only linked internallly inside this transaction unit
// when is time to link this, it'll not look outside the unit to look for this variable

// static int s2_Variable21 = 6;

void function(){
    
}

int main()
{

    // extern int s_Variable21 = 5; 
    // when declare as static, it'll be visible only for that file
    // 5 if here is int and Static.cpp s static
    // if set as external it'll link outside of this files
    // std::cout<< s_Variable21 << std::endl; 
    // std::cout<< s2_Variable21 << std::endl;

    std::cout<< "" << std::endl;
    
    Log log20;

    log20.SetLevel(log20.LogLevelWarning);
    log20.warn("Hello!");
    log20.info("Hello!");
    log20.error("Hello!");


    std::cout<< "" << std::endl;

    // int Player1X = 2; Player2X = 3; // not susteinable to do it
    Player player; 
    player.playerData.x = 5;
    std::cout<< player.playerData.x << std::endl; // 5

    Move(player, 1, 1);
    std::cout<< player.playerData.x << std::endl;// 6

    player.Move(1, 1);
    std::cout<< player.playerData.x << std::endl;// 7


    std::cout<< "" << std::endl;

    int var = 8;
    int* ptr2 = &var;
    *ptr2 = 10;
    std::cout<< var << std::endl;
    std::cout<< *ptr2 << std::endl;

    // allocates 8 bytes of memory and return the pointer for the first one
    char* buffer = new char[8]; 
    // the a block of memory with a value.. Fill Buffer with zeros for 8 bytes
    memset(buffer, 0, 8);
    //pointer to a pointer that points to a
    char** ptr3 = &buffer;
    std::cout<< ptr3 << std::endl;
    std::cout<< &ptr3 << std::endl;
    std::cout<< &ptr3 << std::endl;
    // need to delete the allocated memory
    delete[] buffer;
    
    // References
    std::cout<< "" << std::endl;

    int a17 = 5;
    int aa17 = 6;
    int* b17 = &a17;

    int& ref17 = a17;
    // int& ref17_2 = aa17; can't do -> endded up with a17 = 6 ( value of aa17 ) 
    //( works if it's  pointer)

    int* ref17_3 = &a17;
    *ref17_3 = 2; //set a17 to 2
    ref17_3 = &aa17;
    *ref17_3 = 3; //set aa17 to 3

    std::cout<< a17 << std::endl;
    std::cout<< aa17 << std::endl;



    // int& ref17_2 ; requires an initializaztion


    a17 = 10;
    Increment(&a17);
    Increment2(a17);

    std::cout<< a17 << std::endl;
    std::cout<< &b17 << std::endl;
    std::cout<< ref17 << std::endl;




    std::cout<< "" << std::endl;


 




    Logr("Hey");
    Logr("Hey");
    Logr("Hey");
    Logr("Hey");
    Logr("Hey");

    Logr("");

    for (int i = 0; i < 5; i++ ){
        if(i == 1)
            continue; // display  4 Heys now

        if(i == 2)
            return 0; // Should end the program with 1 Hey ( end the int function and don' execute nothing more)
        
        if(i == 3)
            break; // stop the loop at iteration 3, display only 2 Heys

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