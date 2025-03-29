// nth term of fibonacci series
#include<iostream>
using namespace std;

int fibonacci(int n) {
    if(n==1) {
        return 0;
    }
    if(n==2) {
        return 1;
    }
    int fib = fibonacci(n-1) + fibonacci(n-2);
    return fib;
}
int main() {
    int n;
    cout<< "enter number of last term of fibonacci series"<< endl;
    cin>> n;
    int ans = fibonacci(n);
    cout<< n<< " term of series is "<<ans<< endl;
    return 0;
}
