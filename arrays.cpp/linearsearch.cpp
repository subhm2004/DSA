//linear search using loop
#include<iostream>
using namespace std;
int main() {
    int n;
    cout<< "enter number of elements in array"<< endl;
    cin>> n;
    int arr[n];
    cout<< "enter the elements of array"<< endl;
    for(int i=0; i<n; i++) {
        cin>> arr[i];
    }
    int search;
    cout<< "enter the element to search"<< endl;
    cin>> search;
    
   int flag=0;
    for(int i=0; i<n; i++) {
        if(arr[i]== search) {
            flag =1;
            cout<< "element is found at position"<< i<< endl;
            break;
        }

    }
    if(flag ==0) {
        cout<< "element not found"<< endl;

    }
    
}