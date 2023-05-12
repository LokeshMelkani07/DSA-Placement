#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

// OOPS Documentation Complete: https://www.codingninjas.com/codestudio/guided-paths/basics-of-c/content/118817/offering/1381799



// OOPS Part 2
// Lecture 43 : 4 Pillars of OOPs Concept -Inheritance, Polymorphism, Encapsulation & Abstraction

class Student{
    private:
    string name;
    int age;
    int height;

    public:
    int getAge(){
        return this->age;
    }
};

class Human{

  private:
  int hands;

  protected:
  int foot;

  public:
  int height;
  int weight;
  int age;


  public:
  int getAge()
  {
    return this->age;
  }

  int setWeight(int w)
  {
    this->weight = w;
  }

};

// Inheritence
/*
    Mode of Access Indetifier during inheritence
    Refer to the table in Codestudio documentation
    Private data member of any class cannot be inherited
*/
class Male: public Human{
    public:
    string color;

    void sleep()
    {
        cout<<"Male is sleeping"<<endl;
    }
};

class Female: protected Human{
    public:
    string color;

    void sleep()
    {
        cout<<"Male is sleeping"<<endl;
    }

    void setFoot(int foot)
    {
        this->foot = foot;
    }

    void getFoot()
    {
        cout<<"Foot is "<<this->foot<<endl;
    }

};

/*
// Types of Inheritence using codestudio Documentation. Link at the top
 1. Single Inheritence = A -> B, A ne  ki inherit krli hai

 2. Multi-Level Inheritence = A -> B -> C
 , B ne A ko inehrit kra, C ne B ko inherit kra

 3. Multiple Inheritence = A,B -> C, A and B alag alag class the seperate, C ne A and B dono ko inherit kara.
  class C: public B, public A {

  };

  4. Hierarchical Inheritence = One class serve as parent class for more than one child class
  Like a binary tree
             A

        B         C

    E     F     G    H

  I  J  K  L  M  N  O  P

  5. Hybrid Inheritence = Combination of more than one type of inheritence type is called hyrid inheritence like single + hierearchical or multiple + multi-level or single + multiple.

  Inheritence Ambiguity
  When A and B has a function of same name "abc" now we inherit A and B in a new class C, now when we call that function "abc" from C which "abc" function will get called??
  So to Remove this ambiguity we use :: (Scope Resolution operator)
  C obj;  // object of class C
  obj.A::abc()
  or
  obj.B::abc()

*/


/*
Polymorphism
Poly = many, morphism = forms
Existing in multiple forms is polymorphism
Pitaji is "brother", "son", "father","husband", "Grandfather" etc etc.
This is polymorphism
There are 2 types of polymorphism:
1. Compile Time polymorphism
2. Run Time polymorphism

Compile Time Polymorphism (ALSO CALLED AS STATIC POLYMORPHISM)
1. Function Overloading
   Function with same name means overloading
   Function that differ only in return type cannot be overloaded.
   Functions should differ in number of input arguements or types of input arguements to be able to do function overloading.
2. Operator Overloading
   We know + operator is used to add or concatenate strings
   We want + operator to be able to say "Hello lokesh"
   There are some operators which can be overloaded (list is in codestudio documentation)
   :: and . and ?: and .* are only operators which cannot be overloaded in c++

   we want + to do following operation:
   subtract 2 integer numbers

   return-type operator (input)
   {

   }

   class B{
     public:
     int a;
     int b;

     public:
     int add()
     {
        return a+b;
     }

    // Operator Overloading
    void operator+ (B &obj)
    {
        int value1 = this->a;
        int value2 = obj.a;
        cout<<"Output is "<<value2 - value1<<endl;
    }

    void operator() ()
    {
        cout<<"Mai bracket hoon"<<this->a<<endl;
    }
   };



*/

class Transgender: private Human{
    public:
    string color;

    void sleep()
    {
        cout<<"Male is sleeping"<<endl;
    }

    void setFoot(int foot)
    {
        this->foot = foot;
    }

    void getFoot()
    {
        cout<<"Foot is "<<this->foot<<endl;
    }

};

int main()
{
    /*
    Inheritence
    Height papa pe gayi hai, papa takk -> you tall
    Mummy ke baal silky -> aap bhi silky
    Papa ganje -> aap bhi ganje
    So we inherit some features  from other classes to ourself this is inheritence
    Class Human{
        height,weight,age
    }
    We need to make Male and Female class, we inherit Human in it and add some extra features from our side.
    Human is Parent Class or Super class.
    Male and Female is Sub class or Child Class.
    */
    Male obj1;
    obj1.age = 10;
    cout<<obj1.age<<endl;
    obj1.color = "Black";
    cout<<obj1.color<<endl;
    obj1.sleep();
    obj1.setWeight(100);
    cout<<obj1.weight<<endl;

    // Female inherited as Protected Access Modifier
    Female obj2;
    obj2.setFoot(5);
    obj2.getFoot();

    Transgender T1;
    T1.setFoot(19);
    T1.getFoot(); // will run as we are using getter setter does not matter its privately inherited or not
    // cout<<T1.foot; will not run as its private inherited


    /*
    Protected Access Modifier
    It is same as Private like only members of class can access it inside class.
    but child / derived class can also access it unlike private
    */

    /*
    Encapsulation (Capsule)
    Wrapping up of data members/properties/state and functions/behaviour in a single capsule and single entity.
    It is a class
    Fully encapsulated class
    Where all data members are private that we can access these members only in same class.
    Why Encapsulation ?
    It is information hiding, or data hiding. we can hide our data using encapsulation like we make all data members private. so it increases the security.
    We can make our class READ Only.
    Code Reusability increases
    Helps in Unit Testing


    */

    Student first;

    return 0;
}