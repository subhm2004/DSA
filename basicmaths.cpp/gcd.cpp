#include<iostream>
using namespace std;
int gcd(int a, int b) {
    if(a==0) {
        return b;
    }
    if(b==0) {
        return a;
    }
    while(a!= 0) {
        if(b>a) {
            b = b-a;
        }
        else {
            a = a-b;
        }
    }
    return b;
    
}
int main() {
    int a, b;
    cout<< "enter two numbers"<< endl;
    cin>> a>> b;
    int ans = gcd(a,b);
    cout<< "gcd is "<< ans << endl;
    return 0;
}
