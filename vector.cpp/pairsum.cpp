#include<iostream>
#include<vector>
using namespace std;
int main() {
    int n;
    cout<< "enter size of array"<< endl;
    cin>> n;
    vector<int> arr(n);
    cout<< "enter the elements of dynamic array"<< endl;
    for(int i=0; i< arr.size(); i++) {
        cin>> arr[i];
    }
    int sum =9;
    for(int i=0; i<n-1; i++) {
        for(int j= i+1; j<n; j++) {
            if(arr[i] + arr[j] == sum) {
                cout<< "pair with sum 9 is " << arr[i]<< " "<< arr[j]<< endl;
            }

        }
    }
   
}