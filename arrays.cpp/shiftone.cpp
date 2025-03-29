// shift all the array elements to the right
#include<iostream>
using namespace std;

void shiftone(int arr[], int size) {
    int temp1 = arr[size-1];
    for(int j= size-1; j>=0; j--) {
        arr[j] = arr[j-1];
    }
    arr[0] = temp1;
}
void shifttwo(int arr[], int size) {
    int a = arr[size-1];
    int b = arr[size-2];
    
}
void printarray(int arr[] ,int size) {
    for(int i=0; i<size; i++) {
        cout<< arr[i]<< " ";
    }

}
int main() {
    int arr[] = { 10,20,30,40,50,60};
    int size = 6;
    shiftone(arr, size);
    printarray(arr,size);
    return 0;
}