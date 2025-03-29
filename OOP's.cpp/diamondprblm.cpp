// problem in multiple inheritance 
// jb do classes me same integer variable ho aur child class dono ko inherit kre
#include<iostream>
using namespace std;
class A{
    public:
    int chemistry;
    // CONSTRUCTOR
    A() {
        chemistry= 45;
    }

};
class B{
    public:
    int chemistry;
    B() {
        chemistry= 67;
    }
};
class C: public A, public B{
    public:
    int maths;

};
int main(){
    C obj;
    cout<<  obj.B::chemistry<< " "<< obj.maths<< endl;
    // scope resolution operator is used to remove this ambiguity
}
