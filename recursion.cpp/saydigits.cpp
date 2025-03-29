#include<iostream>
#include<math.h>
using namespace std;

void printdigit(string arr[10], int& n) {
    if(n==0) {
        return;
    }
    int digit = n % 10;
    n= n/10;
    printdigit(arr, n);
    cout<< arr[digit]<< endl;
}

int main() {
    int n;
    cout<< "enter any number"<< endl;
    cin>> n;
    string arr[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    printdigit(arr, n);    
}