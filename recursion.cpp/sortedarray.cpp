// check whether given array is sorted or not
#include<iostream>
using namespace std;
bool sortedarray(int arr[], int size, int i) {
    if(i == size-1) {
        return true;
    }    
    if(arr[i]< arr[i+1]) {
        sortedarray(arr,size, i+1);    
    }
    else {
        return false;
    } 
}
int main() {
    int arr[] = {12, 34,45,57,677,78};
    int size = 6;
    int i=0;
    int ans = sortedarray(arr, size, i);
    cout<< ans<< endl;
    // for(int i=0; i< size-1; i++) {
    //     int sorted = 0;
    //     if(arr[i]< arr[i+1]) {
    //         sorted = 1;
    //         cout<< "array is sorted"<< endl;
    //     }
    //     else if(sorted == 0) {
    //         cout<< "array is not sorted"<< endl;
    //         break;
    //     }
    // }   
}