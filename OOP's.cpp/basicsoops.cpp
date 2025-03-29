#include<iostream>
using namespace std;
class Animal{
    //state or properties

    public:
    int age;
    int weight;
    string name;
    // behaviour
    void eat(){
        cout<< "eating"<< endl;
    }
    void sleep(){
        cout<< "sleeping"<< endl;
    }
};
int main(){
    // static memory allocation
    Animal a;
    a.age= 12;
    a.weight= 50;
    cout<< "age of a is:" << a.age<< endl;
    cout<< "weight of a is: "<< a.weight<< endl;
    a.eat();
    a.sleep();
     // dynamic memory allocation
    Animal* b= new Animal;
    b->age= 23;
    b->weight= 78;
    cout<< "age of b is: "<< b->age<< endl;
    cout<< "age of b is: "<< b->weight<< endl;
    b->eat();
    b->sleep();
    cout<< "size of class is: "<< sizeof(Animal)<< endl; 
    //**important: size of string name in the class is 24 bytes as per
    // the implementation of string.
}
