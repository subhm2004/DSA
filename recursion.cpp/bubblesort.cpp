// bubble sort using recursion
#include<iostream>
using namespace std;

void bubblesort(int arr[], int size) {
    for(int i=0; i<size-1; i++) {
        for(int j=0; j<size-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}
void bubblesort2(int *arr, int& size, int i, int j) {
    if(i>= size-1 || j>= size-i-1) {
        return;
    }
    
    if(arr[j] > arr[j+1]) {
        swap(arr[j], arr[j+1]);
    }
    bubblesort2(arr,size,i,j+1);
    bubblesort2(arr, size, i+1,j );
}

void printarray(int *arr, int size) {
    cout<< "sorted array is "<< endl;
    for(int i=0; i < size; i++) {
        cout<< arr[i]<< " ";
    }
}

int main() {
    int arr[] = { 12,1,8,90,4,2};
    int size = 6;
    int i=0, j= 0;
    bubblesort2(arr, size, i, j);
    printarray(arr, size);   
}