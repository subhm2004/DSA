// types; single, multilevel, multiple, hierarchial, hybrid
#include<iostream>
using namespace std;
// multilevel
class fruit{
    public:
    string name;
};
class mango: public fruit{
    public:
    int weight;
};
class alphanso: public mango{
    public:
    int sugarlevel;
};

// multiple inheritance
class A {
    public:
    int physics;
};
class B{
    public:
    int chemistry;
};
class C: public A, public B{
    public:
    int maths;
};
int main() {
    // alphanso a;
    // cout<< a.name<< " "<< a.weight<< " "<< a.sugarlevel<< endl;
    C obj;
    cout<< obj.physics<< " "<< obj.chemistry<< " "<<obj.maths<< endl;
}