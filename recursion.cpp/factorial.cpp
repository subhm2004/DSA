#include<iostream>
using namespace std;

int factorial(int n) {
    if(n==0 || n==1) {
        return 1;
    }
    int fact = n* factorial(n-1);
    return fact;
}
void counting(int n) {
    if(n==0) {
        return;
    }
    cout<< n<< " ";
    counting(n-1);


}
int main() {
    int n;
    cout<< "enter any number"<< endl;
    cin>> n;
    counting(n);
   // int ans = factorial(n);
    //cout<< "factorial is "<< ans<< endl;
    return 0;
}