#include<iostream>
using namespace std;
int main() {
    int n;
    cout<< "enter any number"<< endl;
    cin>> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<i+1; j++) {
            cout<< i+j+1;
        }
        cout<< "\n";
    }

}