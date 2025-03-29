// you are given dividend and divisor, find quotient
#include<iostream>
using namespace std;
int quotient(int& dividend, int& divisor){
    int s=0, e= dividend;
    int mid= s+(e-s)/2;
    int ans=-1;
    while(s<=e){
        if(mid*divisor== dividend){
            return mid;
        }
        else if(mid* divisor > dividend){
            e= mid-1;
        }
        else {
            ans= mid;
            s= mid+1;
        }
        mid= s+(e-s)/2;
    }
    return ans;
}
int main(){
    int dividend, divisor;
    cout<< "enter dividend"<< endl;
    cin>> dividend;
    cout<< "enter divisor"<< endl;
    cin>> divisor;
    int ans= quotient(dividend, divisor);
    cout<< ans<< endl;
}