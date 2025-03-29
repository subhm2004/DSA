// compile time polymorphism- > 1. function overloading
#include<iostream>
using namespace std;
class Maths{
    public:
    int sum(int a, int b){
        cout << "I'M inside function 1"<< endl;
        return a+b;
    }
    int sum(int a, int b, int c){
        cout<< "I'm inside second function"<< endl;
        return a+b+c;
    }
    float sum(int a, float b){
        cout<< "I'm inside third function"<< endl;
        return a+b;
    }
};
// opertor overloading-> + operator se - wala kaam krao
class Parameter{
    public:
    int value;
    int operator +(const Parameter &object2){
        int value1= this-> value;
        int value2= object2.value;
        return value1- value2;
    }
};

// runtime polymorphism
class Animal{
    public:
    virtual void speak(){
        cout<< "speaking up"<< endl;
    }
};
class Dog: public Animal{
    public:
    virtual void speak(){
        cout<< "Barking"<< endl;
    }
};
int main(){
    // dynamic creation: 4 methods
    Animal *a= new Animal();
    a->speak();
    Animal *b= new Dog();
    b-> speak();
    Dog *d= new Dog();
    d-> speak();
    Dog *e= (Dog*)new Animal();
    e-> speak();


    // Animal a;
    // a.speak();
    // Dog d;
    // d.speak();

    // Parameter object1, object2;
    // object1.value= 4;
    // object2.value= 1;
    // cout << object1 + object2;
    // Maths obj;
    // cout<< obj.sum(2,5.7f);
}