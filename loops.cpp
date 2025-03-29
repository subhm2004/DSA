// check whether given number is prime or not
#include<iostream>
using namespace std;
int main() {
    int n;
    
    cout<< "enter any number "<< endl;
    cin>> n;
    bool isprime=1;
    for(int i=2; i<n; i++) {
        if(n%i==0) {
            isprime=0;
            break;
        }
        
        }
        if(isprime ==0) {
            cout<< "number is not prime"<< endl;
        }
        else {
            cout<< "number is prime"<< endl;
        }
    }
   

