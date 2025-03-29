#include<iostream>
using namespace std;

void printarray(int arr[], int size) {
    cout<< "array is \n";
    for(int i=0; i<size; i++) {
        cout<< arr[i]<< " ";
    }
}
void selection(int arr[],int size ) {
   
    for(int i=0; i< size-1; i++) {
        int smallest = arr[i];
        for(int j = i; j< size; j++) {
        if(arr[j] < smallest) {
            smallest = arr[j];
        }
      }
      swap(arr[i], smallest);
    } 
    cout<< "sorted array is\n"<< endl;
    for(int i=0; i<size; i++) {
        cout<< arr[i]<< " ";
    }
}
int main() {
    int arr[] = { 12,4,7,11,56,34,2};
    int size = 7;
    selection(arr,size);
    

}