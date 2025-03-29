// head and tail recursion
#include<iostream>
using namespace std;
// tail recursion- 1. processing  2.recurcive call
void counting(int n) {
    if(n==0) {
        return ;
    }
    cout<< n<< " ";
    counting(n-1);
}
// head recursion- 1.recurcive call  2. processing
void counting2(int n) {
    if(n==0){
        return;
    }
    counting2(n-1);
    cout<< n<< " ";
}
int main() {
    int n;
    cout<< "enter any number"<< endl;
    cin>> n;
    counting(n);
    cout<< endl;
    counting2(n);
}
