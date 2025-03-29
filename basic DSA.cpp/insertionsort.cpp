#include<iostream>
using namespace std;
void insertionsort(int arr[], int size) {
    for(int i=1; i<size; i++) { 
        int value=i;  // loop for fetching number of elements
       // loop for comparison
       int j= i-1;
       for(; j>=0; j--) {
        if(arr[value]< arr[j]) {
            //shift
           arr[j+1]= arr[j];
        }
       }
       // after completing the whole shift we need to copy the value
       arr[j+1]= arr[value];
    }
}
void printarray(int arr[], int size) {
    for(int i=0; i<size; i++) {
        cout<< arr[i]<< " ";
    }
}
int main() {
    int arr[] = {10,7,1,6,14,9};
    int size = 6;
    insertionsort(arr,size);
    printarray(arr,size);


}