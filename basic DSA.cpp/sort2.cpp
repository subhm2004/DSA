#include<iostream>
using namespace std;
void selection(int arr[] , int size) {    
    for(int i=0; i<size-1; ) {
        int min= arr[i];
        for(int j=i+1; j<size; j++) {
        if(arr[j] < min) {
            min= arr[j];
        }
        }
        swap(arr[i], min);
        i++;        
    }    
}
void printarray(int arr[], int size) {
    cout<< "sorted array is\n";
    for(int i=0; i<size; i++) {
        cout<< arr[i]<< "  ";
    }
}
int main() {
    int arr[] = { 12,3,1,9,5,7};
    int size = 6;
     for(int i=0; i<size-1;i++ ) {
        int min= arr[i];
        for(int j=i+1; j<size; j++) {
        if(arr[j] < min) {
            min= arr[j];
        }
        }
        swap(arr[i], min);      
    }    
    printarray(arr, size);
}