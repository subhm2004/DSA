#include<iostream>
using namespace std;
void insertion(int arr[], int size) {
    for(int i=1; i<size; i++) { // number of rounds
        int value = arr[i];
        // comparing i with previous elements
        int j= i-1;
        for(; j>=0; j--) {
            if(arr[j] > value) {
                // shifting
                arr[j+1] = arr[j];
            }
            else {
                break;
            }
            // else condition is important kyuki agar nhi lgaayege toh har baar j decrease hota hota -1 ho jaayega aur value galat jagah copy ho jaayegi
            
           
        }
        // copying the value
        arr[j+1]= value;
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
    insertion(arr,size);
    printarray(arr,size);
}