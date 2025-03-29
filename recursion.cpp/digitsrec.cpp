// print digits of an number using recursion
#include<iostream>
using namespace std;
void printdigit(int n) {
    if(n==0) {
        return ;
    }
     int a = n/10;
    printdigit(a);
    int rem = n%10;
    cout<< "digit" << rem<< endl;
    // n = n/10;
    // printdigit(n);
}
int main() {
    int n;
    cout<< "enter any number"<< endl;
    cin>> n;
    printdigit(n);    
}