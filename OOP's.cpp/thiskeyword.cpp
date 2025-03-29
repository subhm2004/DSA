// how to access a data member that is private marked

#include<iostream>
using namespace std;
class Animal{
    // state/properties
    private:
    int weight;
    // behaviour
    public:
    int getweight(){
        return weight;
    }
    void setweight(int weight){
       this-> weight = weight;  //this is a pointer to current object i.e. a
    }
};
int main() {
    Animal a;
    a.setweight(78);
    cout<< "weight of a is: "<< a.getweight() << endl;
}