#include<iostream>
using namespace std;

class Animal{
    // states or properties
    int age;
    public:
    int weight;
    string name;
    // methods
    void eat(){
        cout<< "eating" << endl;
    }
    void sleep(){
        cout<< "sleeping"<< endl;
    }
    int getage(){
        return age;
    }
    void setage(int age){
        this->age = age;
    }
    // default constructor
    Animal(){
        this-> weight= 0;
        this-> setage(0);
        cout<< "constructor called"<< endl;
    }
    // parameterised constructor
    Animal(int weight, string name){
        this-> weight= weight;
        this-> name= name;
        cout<< "parameterised constructor called"<< endl;
    }
    // copy constructor
    Animal(const Animal &obj){
        this-> weight= obj.weight;
        this-> name= obj.name;
        cout<< "copy constructor called"<<endl;
    }
    ~Animal(){
        cout<< "I'm inside destructor"<< endl;
    }
};
int main(){
    Animal *b= new Animal(77,"babbar"); 
    cout<< "age is: "<< (*b).getage() << endl;
    cout<< "weight is: "<< (*b).weight << endl;
    cout<< "name is: "<< b-> name<< endl;
     Animal c= *b;
    // delete b;
 


    // object creation
    // Animal dog;
    // dog.setage (124);
    // dog. weight= 53;
    // cout<< "age is: "<< dog.getage() << endl;
    // cout<< "weight is: "<< dog.weight << endl;
    // dog.eat();
    // dog.sleep();

}