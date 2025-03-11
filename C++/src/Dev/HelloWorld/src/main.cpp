#include <iostream>
#include <cstring>
#include <memory>
#include <string>
#include <stdlib.h>

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

// Won't do this, because it's actually a copy of that object and give it to this function
// Since this is a ready only function, there is no need to copy the string... just access it. And it's very slow
// void PrintString31(std::string string)

// This version says that it's a reference, so it points to the original data alerady stored in memory
// And the constant says that it can't be modifiad within this scope, so we are good to acccess it without any danger
void PrintString31(const std::string& string)
{
    std::cout << string << std::endl;
}

class entity33
{
    private:
        int m_X, m_Y;
        // int *m_X, *m_Y; // To make everything as pointers in one line definition
    public:
        // This const defines that that this method will not modify any of the method classes m_X or m_Y
        // I promise that this method will not modify nothing here.
        // Makes sesne to write const with getters
        int GetX() const
        {
            return m_X;
        }


        void SetX(const int x) 
        {
            m_X = x;
        }
};

// Const reference, i don't want to copy my entity3 class, specially if something is read only
// This entity is const, and i can modify what it's pointing twords

void PrintEntity33(const entity33& e)
{
    // e = entity33(); // I CAN CHANGE IT   
    // If i remove the const from GetX, this would cause an error because the method can change the object. And i promised not do do it
    // Remember to always mark method as constant.
    std::cout << e.GetX() << std::endl;
}

class Entity34
{
    private:
        std::string m_Name;
        mutable int m_DebugCount = 0;
        

    public:
        // Second const -> says taht we re not allow to modify class members
        // In some situations, we want 
        const std::string& GetName() const
        {
            m_DebugCount++;
            std::cout << m_DebugCount << std::endl;
            // m_Name = "Hugo"; // Not allowed because of the second const
            return m_Name;
        }
};

class Entity35
{
    private:

        int m_Score; // Defined out of orther, compared to the initialization
        std::string m_Name;
        
    public:
        // same thing... 
        // Some compilers will complain about this out of other thing
        // Always initialize them in the same orther as we declare it
        // Entity35() : m_Name("Unknown"), m_Score(0) {}
        Entity35() : m_Score(0), m_Name("Unknown") {}
        // {
        //     m_Name = "Unknown";
        // }

        Entity35(const std::string& name) : m_Score(0), m_Name(name) {}
        // {
        //     m_Name = name;
        // }
        const std::string& GetName() const {return m_Name; }
};

static int s_Level36 = 1;
static int s_Speed36 = 2;

class Entity37
{
    private:
        std::string m_Name;
    public:
        Entity37() : m_Name("Unknown") {}
        Entity37(const std::string& name) : m_Name(name) {}

        const std::string& GetName() const {return m_Name; }
};

void Function()
{
    // When we reach the end of this function, this obect gets destroyed
    Entity37 entity37_3 = Entity37("Hugo");
}

class Entity39
{
    private:
        std::string m_Name;
        int m_Age;

    public:
        Entity39(const std::string& name): m_Name(name), m_Age(-1) {};
        Entity39(int age): m_Name("Unkknown"), m_Age(age) {};
        Entity39(const std::string& name, int age): m_Name(name), m_Age(age) {};

        int getAge() { return m_Age; }
};

class Entity39_2
{
    private:
        std::string m_Name;
        int m_Age;

    public:
        Entity39_2(const std::string& name): m_Name(name), m_Age(-1) {};
        explicit Entity39_2(int age) : m_Name("Unkknown"), m_Age(age) {};
        // Entity39_2(const std::string& name, int age): m_Name(name), m_Age(age) {};

        int getAge() { return m_Age; }
};

void printEntity39(Entity39 e39){
    std::cout << e39.getAge() << std::endl;
}

struct Vector2_40 {
    float x, y;

    Vector2_40(float x, float y) : x(x), y(y) {};

    // marked as const because i'll not change anything here, just create a new obj
    Vector2_40 Add(Vector2_40 vec2) const {
        return Vector2_40(x + vec2.x, y + vec2.y);
    }

    Vector2_40 Multiply(Vector2_40 vec2) const {
        return Vector2_40(x * vec2.x, y * vec2.y);
    }

    // Define operators as any other functions
    Vector2_40 operator+ (Vector2_40 vec2) const {
        return Add(vec2);
    }

    Vector2_40 operator* (Vector2_40 vec2) const {
        return Multiply(vec2);
    }
};

// std::ostream& operator<<(std::string& stream, const Vector2_40& other){
//     stream << other.x << ", " << other.y;
//     return stream;
// }

class Entity41
{
    public:
        int x, y;

        // we could use an initialize list but lets be different
        Entity41(int x, int y)
        {
            // if we call as usual we would have a problem, because the name i the same
            // x = x;
            // we reference the x annd y that is member of the class, we can use this.
            // an pointer to the current instantiated object
            // We need to derreference, that is why we use -> instead of .
            this->x = x;
            this->y = y;

            // Pass the current instance to an static class to make it have access to it
            // PrintEntity41(this);
        }

        int GetX() const{
            // Whith the const definition, we can't modify anything in the class, so
            // the this is also const
            // this->x = 5; // Not allowed

            const Entity41* e = this;
            return e->x;
            // The same as 
            // return this->x;
        }
};

// void PrintEntity41(Entity41* p)
// {
//     // print something
// }

class Entity42
{
    private:
        int x;

    public:
        Entity42(){
            std::cout << "Create Entity42" << std::endl;
        }

        ~Entity42(){
            std::cout << "Delete Entity42" << std::endl;
        }
};

int* CreateArray42()
{
    // Creating array like this we are not allocating it on the heap, and when we return
    // the stack memory get's cleared when it returns to the scope. We need to allocate 
    // on the heap t meke it live longer
    int* array = new int[50];
    return array;
}

void FillTheArray(int* array)
{
    // fill the array
}

class ScopedPointer42
{
    private:
        Entity42* m_Ptr;
    public:
        ScopedPointer42(Entity42* e) : m_Ptr(e) {}
        ~ScopedPointer42() {delete m_Ptr; }
};

class Entity43
{
    public:
        Entity43()
        {
            std::cout << "Created Entity43!" << std::endl;
        }
        ~Entity43()
        {
            std::cout << "Deleted Entity43!" << std::endl;
        }

        void Print() {};
};


struct Vector43
{
    float x, y;
};

class String44
{
    private:
        char* m_Buffer;
        unsigned int m_Size;
    public:
        String44(const char* string)
        {
            m_Size = strlen(string);
            m_Buffer = new char[m_Size + 1];

            memcpy(m_Buffer, string, m_Size); // Copy the memory to the const char array
            m_Buffer[m_Size] = 0;
            
        }

        // C++ supply this copy constructor to you
        // String(const String44& other) delete; // remove the copy constructor
        String44(const String44& other) : m_Size(other.m_Size)
        {
            std::cout << "Copying..." << std::endl;
            m_Buffer = new char[m_Size + 1];
            // The idea is to allocate another memory adress to that constructor
            memcpy(m_Buffer, other.m_Buffer, m_Size +1);
        }

        ~String44()
        {
            delete[] m_Buffer;
        }

        const char* getBuffer()
        {
            return m_Buffer;
        }
        char& operator[](unsigned int index)
        {
            return m_Buffer[index];
        }

        // declare the operator as a frind to have access to the provate members
        friend std::ostream& operator<<(std::ostream& stream, const String44& string);
};

std::ostream& operator<<(std::ostream& stream, const String44& string)
{
    stream << string.m_Buffer;
    return stream;
}

// void PrintString44(String44 string) // Copy the string
// Every time we copy we allocate memory on the heap and we don't want that.
// We can do that by reference, since this function will not modify the string we can mark as const 
void PrintString44(const String44& string) // DON'T copy the string
{
    std::cout << string << std::endl;
}

class Entity45
{
    public:
        int x;
    public:
        void Print() const {std::cout << "Hello!" << std::endl;}
};

class Scoedtr45
{
    private:
        Entity45* m_Obj;
    public:
        Scoedtr45(Entity45* entity) : m_Obj(entity)
        {

        }

        // automated the deletion of that pointer object with this wrapper?
        ~Scoedtr45()
        {
            delete m_Obj;
        }

        Entity45* operator->()
        {
            return m_Obj;
        }
};

struct Vector45
{
    float x, y, z;

};

int main()
{

    
    std::cout<< "" << std::endl;

    // Getting the ofset of that x
    // // used when serializing data
    // int offsetx = (int)&((Vector45*)nullptr)->x;
    // int offsety = (int)&((Vector45*)nullptr)->y;
    // int offsetz = (int)&((Vector45*)nullptr)->z;

    // std::cout << offsetx << std::endl;
    // std::cout << offsety << std::endl;
    // std::cout << offsetz << std::endl;

    Entity45 e45;
    e45.Print(); // Works fine

    // But if it was a pointer
    Entity45* e45_2 = &e45;
    // e45.Print(); // Can't use the point, we need to derreference that pointer
    Entity45& entity45 = *e45_2;
    entity45.Print(); // works fine after the derreference
    // But we could also do is:
    (*e45_2).Print();  // Direclty derreference it, it's ok and works fine but looks ugly
    e45_2->Print(); // This do the same thing, derreferencing the pointer and calling the function ( shortut instead of manually derraferencing it)

    // We have a class that will delete the obkect when it goes out of scope
    Scoedtr45 se45 = new Entity45();
    se45->Print(); // Error, in this case we need to implement the arrow overload ->



    std::cout<< "" << std::endl;

    String44 string44 = "Hugo";
    // String44 string44_2 = string44;
    std::cout << string44 << std::endl;
    // std::cout << string44_2 << std::endl;
    // crashed
    // free(): double free detected in tcache 2 Aborted
    // Copyg the values to a new memory adress in memory, a direct copy.
    // the memory adress of the buffer is the same for the strings, and we are tring to release the same buffer twice and it's a problem

    // we need to allocate a new char aarray to fix the crash
    // we wANT THE SECOND MEMORY TO HAVE IT'S OWN BLOCK OF MEMORY
    // WE NEED TO PEORM A DEEP COPY, copy the whole object and not just a shallow copy
    // Write a copy constructor, which is called when coying the object. when assignng to a variable of the same type
    // Adter defining the copying constructor, no crash anymore
    String44 string44_3 = "Hugo";
    // Copy
    String44 string44_4 = string44;
    string44_4[2] = 'a';
    PrintString44(string44_3);
    std::cout << string44_3 << std::endl;
    std::cout << string44_4 << std::endl;


    // This is diferent, they are pointers and we are not copyng the vector itself
    // we are copyng the ointer, ending up with 2 pointers to the same variable
    // If accessing the pointer and change the vlue ther, both variables are affected
    // Vector43* a43_3 = new Vector43();
    // Vector43* b43_3 = a43_3;

    Vector43 a43_2 = {2, 3};
    Vector43 b43_2 = a43_2; // a copy of a43_2, bcause they are 2 variables that ocupy 2 diferent locations in memory

    b43_2.x = 5;

    int a43 = 2;

    int b43 = a43; // Creating a copy of a43, they are 2 diferent variables

    b43 = 3;

    // std::cout << a43_3 << std::endl;
    // std::cout << b43_3 << std::endl;
    std::cout << a43_2.x << std::endl;
    std::cout << b43_2.x << std::endl;
    std::cout << a43 << std::endl;
    std::cout << b43 << std::endl;


    std::cout<< "" << std::endl;

    // UNIQUE POINTER
    // Print when we create and destroy it
    {
        // needs to call the constructor explicity
        std::unique_ptr<Entity43> e43(new Entity43());
        e43->Print(); // we can call functions as normal

        // The preferable way to create something is 
        // Important based on exception feilures
        std::unique_ptr<Entity43> e43_2 = std::make_unique<Entity43>();

        // we can't do copies
        // std::unique_ptr<Entity43> e43_2 = e43;

        std::cout << "End Of Unique Pointer!" << std::endl;
    }

    // SHARED POINTER
    {
        std::shared_ptr<Entity43> e43_shared_2 = std::make_shared<Entity43>();
        {
            std::shared_ptr<Entity43> e43_shared = std::make_shared<Entity43>();
            e43_shared_2 = e43_shared;
            

            std::cout << "End Of Unique Pointer!" << std::endl;
        }
        std::cout << "End Of Unique Pointer!" << std::endl;
    }

    // WEAK POINTER
    {
        std::weak_ptr<Entity43> e43_shared_4;
        {
            std::shared_ptr<Entity43> e43_shared_3 = std::make_shared<Entity43>();
            e43_shared_4 = e43_shared_3;
            
            // Get's destroyed leaving the first scope
            std::cout << "End Of Unique Pointer!" << std::endl;
        }
        std::cout << "End Of Unique Pointer!" << std::endl;
    }


    std::cout<< "" << std::endl;

    // Scopes -- Out of this scope e42 will be distroyed but e42_2 don't
    {
        Entity42 e42;
        Entity42* e42_2 = new Entity42();
        if(e42_2) {}

        // int array[4250];
        // int a42 = CreateArray42();

        // Let's go back to the e42_2 example, we want to delete it when it get's out of scope
        // Instead of writing new Entity42 to initialize e42_2, we can do the following

        ScopedPointer42 e42_3 = new Entity42();

        // In this case e42_3 gets deleted since it's a scoped class in the stack.
        // And the destructor will delete the member variable defined with the new Entity42
    }

    

    std::cout<< "" << std::endl;


    Vector2_40 position40(4.0f, 2.0f);
    Vector2_40 speed40(4.0f, 2.0f);
    Vector2_40 Multiply40(4.0f, 2.0f);

    Vector2_40 result40 = position40.Add(speed40.Multiply(Multiply40));
    if(result40.x) std::cout << result40.x << std::endl;
    // THis is where it gets hard to read

    // let's use overloads
    Vector2_40 result40_2 = position40 + speed40 * Multiply40;
    if(result40.x) std::cout << result40_2.x << std::endl;

    // overload defined but not sure if it'll affect any other code
    // std::cout << result40_2 << std::endl;




    std::cout<< "" << std::endl;

    // explicity constructors must be called to create an object, like Entity39_2.
    // Must pass an valid variable type to the constructor. Otherwise it'll fail and will not try to implicity convert it
    // Just accept that type

    Entity39_2 e39_1_2(22); // works fine because it's the explicity
    // Entity39_2 e39_2_2 = "Hugo"; // Fails because it's not called as explicity

    // THis is also allowed because it's a implicity convertion, since we also have a constuctor thet supports is
    // Entity39 e39_1("Hugo");

    // This case we have omre than one convertion and the compiler an't work
    // const char* -> Std::string -> Entity39
    // Entity39 e39_1 = "Hugo";
    Entity39 e39_2 = 28;

    printEntity39(28);

    
    // Entity39 e39_3("Hugo", 28);
    // Entity39 e39_3 = "Hugo", 28;



    std::cout<< "" << std::endl;


    int a38 = 2; // stack
    int* b38 = new int; // 4 bytes allocated in the heap ( returns a pointer )
    int* c38 = new int[5]; // 200 bytes allocated in the heap ( returns a pointer )

    // new actualy call the malloc(50) function -> which llocate the amount of memory we need and return a pointer
    // The only difference is that using new we call the class constructor
    // Allocate the memory and call the constructor
    Entity37* e37_38 = new Entity37();// pointer to a pointer of the heap memory

    // It's an operator and we can overload it

    if(a38) std::cout << a38 << std::endl;
    if(b38) std::cout << b38 << std::endl;
    if(c38) std::cout << c38 << std::endl;

    // when use the new keyword, we need to delete to free the heap memory
    // Memory is not automatcli released
    delete b38;
    delete[] c38;
    delete e37_38;


    std::cout<< "" << std::endl;

    // Create on the stack

    // stack is usually small... if large objects are large... we need to allocate on the heap
    // call the default constructor ( we need to have it)
    // If we can create objects like this.... do it...
        // It's the fastest way and also the most reliable in therms of memory management
            // Beause it'll be dealocated in the end of the scope
    Entity37 entity37;
    Entity37 entity37_2("Hugo");

    std::cout << entity37.GetName() << std::endl;
    std::cout << entity37_2.GetName() << std::endl;

    // We can't do that if we want to make the instance to ive outside of that particular scope
        // Scopes an also be if statements
    Function();

    Entity37* e37;
    {
        Entity37 entity37_4("Hugo inside the scope");
        e37 = &entity37_4;
        std::cout << entity37_4.GetName() << std::endl;
    }
    // This entity37_4 is gone.... apears trash in the console... intresting...
    std::cout << e37->GetName() << std::endl;

    Entity37* e37_2;
    {  
        // Returns the location on the heap where is object is actually allocated
        Entity37* entity37_5 = new Entity37("Hugo inside the 2 scope");
        e37_2 = entity37_5;
        std::cout << entity37_5->GetName() << std::endl;
    }
    // The same content is in the e37_2... kept for outside the scope ( when we know the locaton from the heal)
    std::cout << e37_2->GetName() << std::endl;
    delete e37_2;




    std::cout<< "" << std::endl;

    // Original if declaration - simpe conditional assigment
    if(s_Level36 > 5)
        s_Speed36 = 10;
    else
        s_Speed36 = 5;

    // This two statements are identical
    // Not everyone likes it , i think this is cleaner, athough it's more code to read
    
    // When we nest the condition it starts to get confusion
    s_Speed36 = s_Level36 > 5 ? s_Level36 > 10 ? 15 : 10 : 5;

    std::cout << s_Speed36 << std::endl;

    // No need to create a intermediary string
    std::string rank36 = s_Level36 > 10 ? "Master" : "Beginner";

    std::string rank36_2; // Create an empty string
    // And then assign a value to it... it's tecnicly slower than the ternary
    if(s_Level36 > 5)
        rank36_2 =  "Master" ;
    else
        rank36_2 = "Beginner";


    std::cout<< "" << std::endl;

    Entity35 e35;
    std::cout << e35.GetName() << std::endl;

    Entity35 e35_2("Hugo");
    std::cout << e35_2.GetName() << std::endl;

    std::cout<< "" << std::endl;

    const Entity34 e34;

    // Due to that second const in the method definition, we can call that function in a const object
    // That is why we markk them s const in ths situation
    // But in some situations we want to tuch that variable that is in that class but is not ment to be there....
    e34.GetName();

    // For example, we want to count how many times the GetName function wa called.
    // We can't do it if this is a const method.... but we can mock that variable as mutable.
        // Allowing constant methods to change that specific variable

        // Before the mutable :  error: increment of member 'Entity34::m_DebugCount' in read-only object
    
    int x34 = 8;

    // can pass variables by reference [&x34], by value [x34] or everything [=] or [&]
    auto f34 = [=]() mutable
    {
        // When passing by value, it becomes private... and w can't increment it
        // x34++;

        // We can defien the lambda as mutable, saying that the values we pass b value,
            // we can change them
        x34++;

        std::cout << "Hello " << x34 << std::endl; // 9
    };

    std::cout << "Hello " << x34 << std::endl; // Still 8

    // call the lambda
    f34();


    std::cout<< "" << std::endl;

    entity33 e33;
    e33.SetX(1);

    PrintEntity33(e33);


    int* const_pointer_33 = new int;
    // const before or after the *
    const int* const_pointer_33_2 = new int; // can't change the content of the pointer but i can reassign
    int* const const_pointer_33_3 = new int; // can change the content of the pointer but i cant reassign
    const int* const const_pointer_33_4 = new int; // can't change the content of the pointer but i cant reassign




    int const_33 = 5; // Thid i can change
    const int const_33_2 = 5; // Thid i can NOT change. A way that this variable is not going to be modified latter on

    if(const_33 && const_33_2 && const_pointer_33_3 && const_pointer_33_4) const_33 = 2;
    if(const_pointer_33_3) const_33 = 2;
    if(const_pointer_33_4) const_33 = 2;
    // const_33_2 = 2; // Not valid

    *const_pointer_33 = 2;
    // *const_pointer_33_2 = 2;
    std::cout << *const_pointer_33_2 << std::endl; // 2
    const_pointer_33 = (int*)&const_33; // way to break the const promise, not suppose to do often // We reassogned the content
    const_pointer_33_2 = (int*)&const_33; // We can't change the content of that pointer, the data at that memory adress
    std::cout << *const_pointer_33 << std::endl; // 2
    std::cout << *const_pointer_33_2 << std::endl; // 2


    std::cout<< "" << std::endl;

    const char* string_32 = "Hugo"; // const char array of 5 bytes, because of the null ptr at the end \0
    // string_32[2] = "a"; // undefined behavior -> pointer of a string literal location ( which is read only memory locations )

    //#include <stdlib.h>

    const char string_32_2[8] = "Hu\0go";

    std::cout << strlen(string_32) << std::endl; // 4
    std::cout << strlen(string_32_2) << std::endl; // 2

    const wchar_t* string_32_3 = L"Hugo"; // might be 2 bytes per character -> 
    const char16_t* string_32_4 = u"Hugo"; // 2 bytes per character
    const char32_t* string_32_5 = U"Hugo"; // 4 bytes per character

    if(string_32_3 || string_32_4 || string_32_5)
        std::cout << "Hugo" << std::endl;

    using namespace std::string_literals;

    std::string string_32_6 = "Hugo"s + " Hello"; // With this s AND THE USING, WE CAN ADAD STRINGS

    // Usefull to write paragraphs, this R before ""
    const char* string_32_7  = R"(Line1
    Line2
    Line3)";

    std::cout << string_32_6 << std::endl;
    std::cout << string_32_7 << std::endl;






    std::cout<< "" << std::endl;


    // base form to declara a string
    // const is to prevent the user from change it, it's a fixed alocated memory. If decides to change, needs to allocate another portion of the memory
    // no need to delete this, because we don't use the new keyword ( rule of  tomb )
    const char* string31 = "Hugo";
    // need to use strcpy(), strlen() .....
    // name[2] = "A"; // Not allowed 
    // Represented as byters but converted to ASCII to represent letters ( there is a table for that convertion, to associate memory with letters )
    // We don't know the size of the string. End in the nul termination pointer

    char string31_2[5] = {'H', 'u', 'g', 'o', 0}; // this is an array of 6 chars


    if(string31 && string31_2)
    {
        std::cout << string31 << std::endl;
        // still represents an array, but will access dead memory because there is no null termator pointer. We need to defined it with the '\0' at the end
        // which represents the null pointer
        std::cout << string31_2 << std::endl; 
    }

    // How should we actually use it....
    // It is a template specialization of the char datatype ( behind the sceenes) - but we use std::strings

    // need to include <string>
    std::string string31_3 = "Hugo"; //+ "Hugo2"; // Can't do this, because it's 2 const char* arrays and we can't modify that
    // There are some functions defined here with the string definition

    // gorup strings
    string31_3+= " Hugo2"; // there is a overload that allow us to do that
    // or
    std::string string31_4 = std::string("Hugo") + " Hugo2";
    // both peform the same results
    PrintString31(string31_3);
    PrintString31(string31_4);

    // find text on strings
    bool contains31 = string31_3.find("u") != std::string::npos; // check if it's equal to an iligal position

    if(contains31)
    {
        std::cout << contains31 << std::endl;
    }   

    std::cout<< "" << std::endl;

    static const int exampleSieOfTheArray30 = 5;
    int exemple30[exampleSieOfTheArray30]; // Definition of an array of 5 integers // Gets destroied wen getting out of the scope
    int* ptr30 = exemple30; // creating ap ointer to the first element of the array
    // If allocated in the stack, we can get the size with the sizeof() method. But we need to convert
        // It's actually the size of the aray with the specific data type
        // The convertion to find the number of elemnts is
        // better way is to keep the size by our selfs
    // static const int exampleSieOfTheArray30 = 5;
    int count = sizeof(exemple30) / sizeof(int);
    std::cout << "Size of the array : " << count << std::endl;
    
    // Creating array with the keyword new
        // This one is created on the heap, we need to manualy delete it
        // Be arround until we delete it... can be good... and usefull
        // we holds a pointer
        // If... we anocate the entire array, it'll be alive after we move out of the scope
        // but if we allocate just the pointer to the array, it'll no be thete ( int* )
            // However, we have the current adress to the current data, so we don'tactually delete it
            // To access we need to jump arround to find the data 
            // It's a performance issue, don't do it 
        // There is no way to know the size of the array, like get_size() method for example
    int* example30_2 = new int[5];

    // c++ 11 array example ( standard array)
    // Advantages on tools to use and security on acessing memory
    // been super safe, use it. 
    std::array<int, exampleSieOfTheArray30> example30_3;
    

    //To access an array - index starts with 0
    exemple30[0] = 10; // This is any other integer and we can set it
    exemple30[4] = 14; // lest element of the array
    exemple30[3] = 3;
    // we dereference the pointer to the array and increase 3 positions
    // same as acessing the pointer using the index
    *(ptr30 + 3) = 4; 

    std::cout << exemple30[0] << std::endl;
    std::cout << exemple30[4] << std::endl;
    std::cout << exemple30[3] << std::endl; // suppose to be 4 and not 3 because we changed using the pointer to the beginning of the array
    // This is bad... can cause problems difficult to debug
    // std::cout << example30[-1] << std::endl; // Memory access violation
    // std::cout << example30[5] << std::endl; // Memory access violation

    // loop with arrays - very usefull
    for (int i=0; i<5; i++)
    {        
        exemple30[i] = 2;
        example30_2[i] = 3;
        example30_3[i] = 4;
    }
    
    std::cout << exemple30[0] << std::endl;
    std::cout << exemple30[4] << std::endl;

    std::cout << example30_2[0] << std::endl;
    std::cout << example30_2[4] << std::endl;

    std::cout << example30_3[0] << std::endl;
    std::cout << example30_3[4] << std::endl;

    delete[] example30_2; // delete an array created with new

    std::cout<< "" << std::endl;
    

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