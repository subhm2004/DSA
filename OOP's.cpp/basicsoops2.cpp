// default argumnt
#include<iostream>
using namespace std;
class A{
    public:
    int x;
    int *y = new int;
    int z;
    A(int x, int y, int z = 2){ //z is default argument
        this-> x = x;
        this-> y = new int(y) ;
        this-> z= z;
    }
};
int main(){
    A obj(1,2);
    cout<< obj.x << " "<< obj.y << " "<< obj.z<<  endl;

}