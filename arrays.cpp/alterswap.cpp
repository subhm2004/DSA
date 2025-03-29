// swap alternate element of an array
#include<iostream>
using namespace std;
void printarray(int arr[], int size) {
    for(int i=0; i<size; i++) {
        cout<< arr[i] << " ";
    }

}
void alterswap(int arr[], int size) {
    for(int i=0; i<=size-1; i=i+2) {
        if(arr[i] == arr[size-1]) {
                cout<< arr[i]<< " ";
            }
        else {
            int j= i+1; 
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            cout<< arr[i] << " "<< arr[j] << " "; 
        }         
        }
    }
int main() {
    int arr[] = {1,2,3,5,6,7,8 ,9};
    int size = 8;
    cout<< "elements of array are"<< endl;
    printarray(arr, size);
    cout<< endl;
    cout<< "array after swapping are"<< endl;
    alterswap(arr, size);
    cout<< endl;
    return 0;
}
