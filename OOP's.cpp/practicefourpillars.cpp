#include<iostream>
using namespace std;
class Animal {
    public:
    Animal(){
        cout<< "constructor called of animal class"<< endl;
    }
    void speak(){
        cout<< "speaking up"<< endl;
    }
};
class Dog: public Animal{
    public:
    Dog (){
        cout<< "constructor of dog class"<< endl;
    }
    void speak(){
        cout<< "barking"<< endl;
    }   
};
int main(){
    Animal *a= new Animal();
    Dog *b= new Dog();
    Dog *c= (Dog*)new Animal();
    Animal *d= new Dog();

}