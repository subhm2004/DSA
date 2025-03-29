// find prime number using loops
#include<iostream>
using namespace std;
 void isprime(int n) {
    if(n<=1) {
        cout<< "number is not prime"<< endl;
    }
    int flag=0;
    for(int i=2; i<n; i++) {
        if(n%i==0) {
            flag =1;
            break;
        }
    }
    if(flag==0) {
        cout<< "number is prime"<< endl;
    }
    else {
        cout<< "number is not prime"<< endl;
    }
}

void countprime(int n) {
    int flag = 0;
    for(int i=2; i< n; i++) {
        int count = 0;
        for(int j=2; j<i; j++) {
            if(i % j == 0) {
                count = 1;
                break;
            }
        }
        if(count == 0) {
            flag++;
        }
    }
    cout<< "number of prime numbers are "<< flag << endl;
}

int main() {
    int n;
    cout<< "enter any number"<< endl;
    cin>> n;
    countprime(n);
   // isprime(n);
}