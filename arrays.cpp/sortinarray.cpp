// sort zeroes and ones in an array
#include<iostream>
#include<vector>
using namespace std;
int main() {
    vector<int>arr{1,0,1,1,0,1,1,0,0,0,1,0};
    int zero= 0, one =0;
    for(int i=0; i<arr.size(); i++) {
        if(arr[i] == 0) {
            zero++;
        }
        else {
            one++;
        }
    }
    cout<< zero<< endl;
    cout<< one<< endl;

    vector<int>brr; // size insert krne par uss size ka element 0 consider ho rha h

    for(int i=0; i< one; i++) {
        brr.push_back(1);
    }
    cout<< endl;
    for(int i = 0; i < one; i++) {
        cout<< brr[i] << " ";
    }
    cout<< endl;
    for(int i=0; i<zero; i++) {
        brr.push_back(0);
    }
    cout<< "elements of final array are "<<endl;
    // printing the array
    for(int i=0; i< brr.size(); i++) {
        cout<< brr[i] << " ";
    }

}