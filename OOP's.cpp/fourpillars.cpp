// four pillars of OOP's are encapsulation, inheritance, abstraction, polymorphism.
#include<iostream>
using namespace std;
// parent class
class Animal{
    // states/properties
    public:
        int age;
        int weight;
    // behaviour
    private:
        void eat(){
            cout<< "eating"<< endl;
        }
        void sleep(){
            cout<< "sleeping"<< endl;
        }
};
//child class
class dog: public Animal{
    public:
    void print(){
        cout<< this->age << endl;
       }
    
};
// operator overloading
class parameter{
    public:
    int value;

    void operator+(parameter &obj2){
        int value1= this->value;
        int value2= obj2.value;
        cout<< value1- value1<< endl;
    }
};
int main(){
    Animal a;
    //cout<< a.age<< endl;
    dog d1;
    parameter obj1, obj2;
    obj1.value = 7;
    obj2.value = 2;
    obj1+obj2;
    

    //cout<< d1.age<< endl; 
    // declared protected inside the parent class, hence can't be accessed here
    
    d1.print();
    
}