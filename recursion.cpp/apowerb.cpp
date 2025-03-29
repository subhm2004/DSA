// print a to the power b for any input of a and b
#include<iostream>
using namespace std;

int power(int& a, int b) { // not an optimised approach
    if(b==0) {
        return 1;
    }
   int ans = a* power(a, b-1);
}

int fastpower(int& a, int b) {
    if(b==0) {
        return 1;
    }
    if(b%2==0) { // even
        return fastpower(a,b/2) * fastpower(a, b/2);
    }
    else {
        return a* fastpower( a,  b/2) * fastpower(a, b/2);
    }
}
int main() {
    int a,b;
    cout<< "enter base and exponent"<< endl;
    cin>>a>> b;
    int final= fastpower(a,b);
    cout<< a<< " to the power "<< b<< " is "<< final<< endl;   

}