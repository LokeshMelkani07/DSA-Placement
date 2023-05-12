// OOPS Documentation Complete: https://www.codingninjas.com/codestudio/guided-paths/basics-of-c/content/118817/offering/1381799
#include<iostream>
#include<cstring>
// Accessing hero.cpp from outside which has a class of type Hero, we can use it here also but we need to include Hero.cpp like this
// #include "Hero.cpp"
#include<vector>
#include<algorithm>
using namespace std;

// OOPS in C++
// OOPS is a Way of programming which deals with objects, it increases readability
// Class is a user defined data type
// Object is something which has a properties/state and a behaviour
class Hero{

    // Access Modifiers
    /*
    There are 3 types of access modifiers
    1. Public: Everybody can access, inside the class and outside the class both.
    2. Private: Only class ke andar hi access kari ja skti h properties voh bhi sirf class ke andar ke methods se only.
    3. Protected
    These are used to give permission that who can use these properties or methods
    By default private access modifier is applied in the class
    */

    // Properties
    // char name[10];

    /*

    private:

    int health;

    */

    public:
    char *name;
    int health;
    char level;

    // static keyword makes an data member which belongs to class
    // That is to access that data member we do not need to make any object
    // We need to initialise static member outside class suing :: (scope resoltuion operator)
    // int Hero::timetoComplete = 10;
    static int timeToComplete;

    // Constructor
    // Once we make this constructor ourself, the default cons which is made by the CPU will get automatically destroyed

    Hero()
    {
        cout<<"Constructor called"<<endl;
        name = new char[100];
    }


    // Parameterised Constructor
    /*
    Hero(int health)
    {
        // this keyword
        // When name of parameter is same as name of variable, we use this keyword
        // this is an pointer which points to current object

        this->health = health;
    }

    Hero(int health, char level)
    {
        this->health = health;
        this->level = level;
    }
    */

    // Our own implementation of Copy Constructor
    // We do pass by reference in Copy constructor so that real Suresh object is passed directly and copies are not formed

    Hero(Hero &temp)
    {
        // Default constructor does shallow copy (Same memory location, called by 2 different names)
        // To do deep copy (Different memory copy is made) we use our own Copy constructor

        char *ch = new char[strlen(temp.name) +1];

        strcpy(ch,temp.name);

        cout<<"Copy Constructor is called"<<endl;
        // Once we write our own implementation of Copy constructor, the default copy constrcutor gets destroyed
        this->health = temp.health;
        this->level = temp.level;
        // Deep copy of name is shared
        this->name = ch;
    }


    void print()
    {
        cout<<"Level is "<<this->level<<endl;
        cout<<"Health is "<<this->health<<endl;
        cout<<"Name is "<<this->name<<endl;
    }

    // When our variable is private and we need to set it and get it
    // we use setters() and getters()
    // Like we do for health as health is private variable now
    int getHealth()
    {
        // Read
        return health;
    }

    char getLevel()
    {
        // Read
        return level;
    }

    // void setHealth(int h,char name)
    void setHealth(int h)
    {
        // Write
        // We can use setter as a security also like when name is lokesh then only allow it to set the health
        /*
        if(name=="lokesh")
        {
            health = h;
        }
        */
        health = h;
    }

    void setLevel(char ch)
    {
        // Write
        level = ch;
    }

    void setName(char *name)
    {
        strcpy(this->name,name);
    }


    // Static Functions
    // Same as Staic variable
    // These do not have this keyword as this means pointer to current object and here we do not have any object so it does not have this keyword
    // Static function can onllly access
    static int random()
    {
        // cout<<this->health<<endl;  // error
        return timeToComplete;
    }

    // Destructor
    // This is a memory de-allocater
    // When object is getting out of scope or is dieing then destructor is called to free up that memory
    // Name of destructor = name of class
    // No return type
    // No parameter
    // Destructor is automatically made but we can make it manually also
    // we need to use ~ sign
    // More on destructor inside int main() line 320
    ~Hero()
    {
        cout<<"Destructor is called"<<endl;
    }

};

// Static Variable initialisation
int Hero::timeToComplete = 10;


int main()
{
    // Made an object h1 of type Hero
    // Size of empty class ka object is 1
    Hero h1;
    cout<<"Size : "<<sizeof(h1)<<endl; // 1*10 for char + 4 for int + 1 for int

    // Concept of Padding
    /*
    class pading{
        int age; // 4 bytes
        double salary; // 8 bytes
        short int ID; // 2 bytes
    };


    Let say we make a object of type padding
    What will be size allocated to that object?
    4+8+2 = 14 bytes?
    NO, it will take 8+8+8=24 bytes
    because we have 32 bits OS and 64 bits OS.
    32 bits/8 = 4 bytes, means it process 4 bytes at a time
    64 bits/8 = 8 bytes, means it process 8 bytes at a time
    so int is given 4 bytes of its own + 4 bytes of padding = 8
    so double takes 8 bytes of its own as usual
    so short is given 2 bytes of its own + 6 bytes of padding = 8
    So that when 64 bits OS runs the program it runs it efficiently.
    so total 8+8+8 = 24 bytes is alloted to the object

    We can solve this problem and save memory by writing the code efficiently like

     class pading{
        double salary; // 8 bytes
        int age; // 4 bytes
        short int ID; // 2 bytes
    };

    Now double takes 8 bytes + int and short int takes 6 + 2 bytes and we save some memory, This is called as greedy allignment which solved the issue of padding adn saves memory

    Data structure alignment is the way data is arranged and accessed in computer memory. Data alignment and Data structure padding are two different issues but are related to each other and together known as Data Structure allignment.

    More on Data allignment and Data Padding:

    Data alignment: Data alignment means putting the data in memory at an address equal to some multiple of the word size. This increases the performance of the system due to the way the CPU handles memory.
    Data Structure Padding: Now, to align the data, it may be necessary to insert some extra bytes between the end of the last data structure and the start of the next data structure as the data is placed in memory as multiples of fixed word size. This insertion of extra bytes of memory to align the data is called data structure padding.

    */

    // we can access these properties of the class using . operator
    // cout<<"Health is : "<<h1.health<<endl; // garbage value as we have not initialised them
    cout<<"Level is : "<<h1.level<<endl; // garbage value as we have not initialised them

    // Initialising the values
    // h1.health = 50;
    h1.level = 'A';

    // cout<<"Health is : "<<h1.health<<endl;  // 50
    cout<<"Level is : "<<h1.level<<endl; // A

    // Using setter and getter for health as its private
    h1.setHealth(30);
    cout<<"Health from getter is "<<h1.getHealth()<<endl;

    // This is Static Allocation
    Hero a;
    a.level = 'D';
    cout<<"Level of a is "<<a.level<<endl;

    // We can also make an object using dynamic allocation

    Hero *h = new Hero;
    // Assigning value dynamically we use (*h)
    (*h).level = 'C';
    // or we can also use -> operator inside of * operator
    h->health = 11;
    cout<<"Level of h is "<<(*h).level<<endl;
    cout<<"Health of h is "<<h->health<<endl;

    // Constructor
    // Whenever we create an object, its constructor is called
    // It has no return type
    // No input paramter
    Hero lokesh;
    // lokesh.Hero(); is our constructor which is called on making lokesh
    // As soon as we make lokesh, "Constructor Called" will get printed
    // Constructor will get called does not matter we make object statically or dynamically

    // Calling parameterised Constructor
    /*

    Hero mukesh(40);
    cout<<"Value of health from parameterised constructor is "<<mukesh.health<<endl;

    */


    // Copy Constructor
    Hero Suresh;
    Suresh.setHealth(100);
    Suresh.setLevel('S');


    cout<<"Print() for Suresh is "<<endl;
    Suresh.print(); // 100 'S'


    Hero Mohit(Suresh);  // Copy values of level and health for suresh in mohit
    // The above line is same as writing
    // Mohit.health = Suresh.health;
    // Mohit.level = Suresh.level;
    cout<<"Print() for Mohit is "<<endl;
    Mohit.print();  // 100  'S'
    // So this is copy constructor which copies the value from one object to other


    // Shallow and Deep Copy
    // Default copy constructor does the shallow copy
    Hero h3;
    h3.setHealth(100);
    h3.setLevel('M');
    char name[7] = "lokesh";
    h3.setName(name);

    h3.print();

    // Use default copy const and make another Hero
    Hero h4(h3);
    Hero h5 = h3; // another way of doing above work
    cout<<"h4 printing"<<endl;
    h4.print(); // name = mokesh
    cout<<"h3 printing after changing lokesh to mokesh"<<endl;
    h3.name[0] = 'M';
    h3.print(); // name = mokesh
    cout<<"h4 printing after changing h3 lokesh to mokesh"<<endl;
    h4.print();  // It also changes to mokesh
    // So default constructor does the shallow copy which means
    // We access same memory from 2 different name h3 and h4
    // Sameway Deep copy means, Another copy of same thing will be made and changes do not get reflected
    // To implement Shallow copy, we have default constructor
    // To implemement Deep copy we need to implement it through Our own copy constructor
    h4.print(); // gives lokesh now because now we have made a deep copy of it

    // Copy Assignment Operator
    // Let say h3 and h4 are two objects with some value of health and level
    // We write h3 = h4 which means h3.health = h4.health and h3.level = h4.level, h3.name = h4.name
    // h4 ka maal h3 mai aa jayega
    cout<<"Assigning h3 material inside h5 which is empty currently"<<endl;
    h5 = h3;
    cout<<"Printing h3 in h5"<<endl;
    h5.print(); // name = mokesh


    // Destructor
    // This is a memory de-allocater
    // When object is getting out of scope or is dieing then destructor is called to free up that memory
    // Name of destructor = name of class
    // No return type
    // No parameter
    // Destructor is automatically made but we can make it manually also
    // we need to use ~ sign
    // Once we write our own implementationof an destructor, the default destuctor gets killed automatically
    // For any object constructor is called only once (during its birth)
    // For any object destructor is called only once (during its death)
    /*
    ~Hero()
    {
        cout<<"Destructor is called"<<endl;
    }
    */
    // For object made by static allocation, destructor is called automatically
    // For object made by dynamic allocation, we need to call the desctructor manually
    // Dynamically allocated object h6
    Hero *h6 = new Hero();
    // manually calling the destructor
    delete h6;


    // When do we use Initializer List in C++?
    // Initializer List is used in initializing the data members of a class. The list of members to be initialized is indicated with constructor as a comma-separated list followed by a colon. Following is an example that uses the initializer list to initialize x and y of Point class.
    /*
    class Point {
        private:
        int x;
        int y;
        public:
    Point(int i = 0, int j = 0):x(i), y(j) {}
    /*  The above use of Initializer list is optional as the
    constructor can also be written as:
    Point(int i = 0, int j = 0) {
                x = i;
                y = j;
    }
    */

    // int getX() const {return x;}
    // int getY() const {return y;}
// };


    // Static Keyword
    // static keyword makes an data member which belongs to class
    // That is to access that data member we do not need to make any object
    // We need to initialise static member outside class suing :: (scope resoltuion operator)
    // int Hero::timetoComplete = 10;
    // static int timeToComplete;
    // Accessing Static member which is initialised outside class and declared inside class
    cout<<"Hero ka time to complete is "<<Hero::timeToComplete<<endl;
    // we can also access it using a object but that is not needed

    // Static Functions
    // Same as Staic variable
    // These do not have this keyword as this means pointer to current object and here we do not have any object so it does not have this keyword
    // Static function can onllly access static members
    /*
    static int random()
    {
        // cout<<this->health<<endl;  // error
        return timeToComplete;
    }
    */
    cout<<Hero::random()<<endl;








    return 0;
}