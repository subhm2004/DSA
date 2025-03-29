// numeric full pyramid
#include<iostream>
using namespace std;
int main() {
    int n;
    cout<< "enter any number"<< endl;
    cin>> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n-i-1; j++) {
            cout<< " ";
        }
        int start= i+1;
        for(int j=n-i-1; j<n; j++) {
           
            cout<< start;
            start++;
        }
        for(int j=0; j<i; j++) {
            cout<< start-2;
            start--;
        }
        cout<< "\n";
    }
}