#include <iostream>
#include <cstring>
#include <memory>

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

struct Entity22
{
    int x22, y22;

    void Print(){
        std::cout << "Entity 22 x22 " << x22 << " Y22 " << y22 << std::endl;
    }
};

struct StaticEntity22
{
    // static int x22, y22;
    static int x22, y22;

    static void Print(){
        std::cout << "Static Entity 22 x22 " << x22 << " Y22 " << y22 << std::endl;
    }
};

// When making this variables static, we need ot initialize 
// them without any instantiation
int StaticEntity22::x22;
int StaticEntity22::y22;

// MIGHT GET SOME ISSUES IF LET THE CODE LIKE THIS;
// Because it's not a group anymore and we can change this values since it's variables
int A23 = 0;
int B23 = 1;
int C23 = 2;

enum Example23
{
    // can list the values we want to have

    // iF TRY TO SET SOMETHING ELSE, WILL GET AN ERROR. because it has to be one of these 3
    
    // they are al integers in the end of the day and kees incrementing
    // By default its 32 bit integers
    A, B, C
};

// But we can change the type of the enum
// can't change the type, just the number of bits it will store each variable
enum Example23_2 : unsigned char // 8 bit variables
{
    A2, B2, C2
};

class Entity24
{
    public:
        float X, Y;

    // // Default constructore that does nothing.... Defined by default
    // Has to manua
    // Entity24() 
    // {}

    Entity24() 
    {
        std::cout << "Created Entity!" << std::endl;
        X = 0;
        Y = 0;
    }

    // We can write as much constructors as we want, but with different parameters to have diferent signatures
    Entity24(int x, int y) 
    {
        std::cout << "Created Entity!" << std::endl;
        X = x;
        Y = y;
    }

    ~Entity24() 
    {
        // Appears the message in the end of the program
        std::cout << "Destroyed Entity!" << std::endl;
    }

    void Init()
    {
        X = 0;
        Y = 0;
    }

    void Print(){
        std::cout << "Entity 24 x24 " << X << " Y24 " << Y << std::endl;
    }
};

class LogWithoutConstructor
{
    // Remove the default onstructure of the class
    // This way there is no way anyone instantiate this class
    public:
        LogWithoutConstructor() = delete;

        static void Write()
        {

        }
};

void PrintFunction26()
{
    // Object will be created and deleted within this function
    // Deleted when leaving it
    Entity24 e24_6(10, 11);
    e24_6.Print();
}


// Lets create a base class  to avoid duplications

class Entity_26 // Base
{
    public:
        int X, Y;

        void Move(float xa, float ya)
        {
            X += xa;
            Y += ya;
        }

};

// Sub class of Entity_26
class Player26 : public Entity_26
{
    public:
        const char* Name;

        // No need to have duplicated code since it is a sub class from
        // form Entity_26 and this is already defined there
        
        // int X, Y;

        // void Move(floatxa, float ya)
        // {
        //     X += xa;
        //     Y += ya;
        // }

        void PrintName()
        {
            std::cout << "Player26 Name : " << Name << std::endl;
        }
};

class Entity27
{
    public:
        // generate a v table for this function so if it is overriden, 
        // we can call the proper function 
        virtual std::string GetName() {return "Entity27"; }
};

class EntitySub27 : public Entity27
{
    private:
        std::string m_Name;
    public:
        EntitySub27(const std::string& name)
            : m_Name(name) {}

        std::string GetName() override {return m_Name; }
};


class Printable28
{
    public:
        virtual std::string GetClassName() = 0;
};

class UsePrintable28 : public Printable28
{
    public:
        std::string GetClassName() override {return "Entity"; }
};

class Entity28
{
    public:
        // Defining a pure virtual function ( wit no implementation )
        virtual std::string GetName() = 0;
};

class EntitySub28 : public Entity28
{
    private:
        std::string m_Name;
    public:
        EntitySub28(const std::string& name)
        : m_Name(name) {}

        // If we comment this function out, will generate an error,
        // because we don't have a base class method implemented, that is required
        std::string GetName() override {return m_Name; }
        
};

void Print28(Printable28* obj)
{
    // In this case, we need a class that ensures we have this method implemented
    // In this case, everything that is Printable28 has a GetClassName method implemented
    // or the object is not allowed to be instantiated and causes an compilation error
    std::cout << obj->GetClassName() << std::endl;
}

class Entity29
{   
    // DEFAULT VISIBILITY IS PRIVATE, if structure it would be public
    //private:
        // only this entity class can acess this variables
    protected:
        int X, Y;

    void Print() {};

    public:
        // Works just fine with the own class
        Entity29() : X(0) { Print(); };
    

};

class EntitySub29 : public Entity29
{
    // Will not work if it's a private base class
    EntitySub29() 
    { 
        X = 0;
        Y = 0;
        Print(); 
    }

};




int main()
{

    // Entity28* e28 = new Entity28(); // We can't instnatiate the subclass as pure virtual
    // std::cout << e27->GetName() << std::endl;

    EntitySub28* esub28 = new EntitySub28("Hugo");
    std::cout << esub28->GetName() << std::endl;

    // UsePrintable28 useP28 = new UsePrintable28();
    // std::cout << Print28(new UsePrintable28()) << std::endl;

    std::unique_ptr<Printable28> useP28 = std::make_unique<UsePrintable28>(); 
    Print28(useP28.get()); // Pass the raw pointer to the Print28 function
    

    std::cout<< "" << std::endl;

    Entity27* e27 = new Entity27();
    std::cout << e27->GetName() << std::endl;

    EntitySub27* esub27 = new EntitySub27("Hugo");
    std::cout << esub27->GetName() << std::endl;

    // things starts to crac, this is actually a player but references the base class
    // So we get the base class method output
    Entity27* e27_2 =esub27;
    // if not virtual function output is "entity27"
    // if virtual function output is "hugo"
    std::cout << e27_2->GetName() << std::endl;
    

    std::cout<< "" << std::endl;


    Player26 player26;

    // We can access all the declaration from the base class using the derived one
    player26.Move(5, 5);
    player26.Name = "Hugo";
    player26.PrintName();

    std::cout<< "" << std::endl;

    PrintFunction26();

    Entity24 e24;

    //When we instantiate a class without initializing the parameters, there is no actual value and they would receive garbage
    e24.Print(); // GARBAGE

    Entity24 e24_2;
    e24_2.Init(); // eXTRA CODE AND NOT CLEAN, BUT IT WORKS AS WELL
    e24_2.Print(); // ZERO VALUES

    Entity24 e24_3;
    e24_3.Print(); // Using the constructore, no need to call the init

    Entity24 e24_4(2, 3);
    e24_4.Print(); // Using the constructore wth parameters, output as 2 and 3

    // LogWithoutConstructor e24_5; // will generate an error, deleted the constructor





    std::cout<< "" << std::endl;

    // int value23 = B23;
    int value23 = Example23::B;

    // they are al integers in the end of the day
    if(value23 == Example23::B && Example23::B == 1)
    {
        // DO SOMETHING
    }

    std::cout<< "" << std::endl;

    // No need this definition anymore... can access the variables using the class
    StaticEntity22 se22; 
    se22.x22 = 2;
    se22.y22 = 3;
    se22.Print();

    // StaticEntity22 se22_2 = {5, 8}; // This would fail for static classes
    StaticEntity22 se22_2; // This would fail for static classes
    // se22_2.x22 = 5;
    // se22_2.y22 = 8;
    se22_2.Print(); // result should be the same as the other instantiation

    // we can access them by the class and not by the instance
    // And it'll change its value
    StaticEntity22::x22 = 5;
    StaticEntity22::y22 = 8;
    StaticEntity22::Print(); // 5, 8

    // Not static struct parameters
    Entity22 e22;

    e22.x22 = 2;
    e22.y22 = 3;
    e22.Print();

    Entity22 e22_2 = { 5, 8 };

    e22_2.Print();


    std::cout<< "" << std::endl;

    // extern int s_Variable21 = 5; 
    // when declare as static, it'll be visible only for that file
    // 5 if here is int and Static.cpp s static
    // if set as external it'll link outside of this files
    // std::cout<< s_Variable21 << std::endl; 
    // std::cout<< s2_Variable21 << std::endl;

    std::cout<< "" << std::endl;
    
    Log log20;

    log20.SetLevel(Log::LevelError);
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