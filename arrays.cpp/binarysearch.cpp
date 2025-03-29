// binary search
#include<iostream>
using namespace std;
void printarray(int arr[], int size) {
    for(int i=0; i<size; i++) {
        cout<< arr[i]<< " ";
    }
    cout<< endl;
}
int binary_search(int arr[], int size, int search) {
    int i=0, j= size -1;    
    while(i<=j) {
        int mid = (i+j)/2;
        if(arr[mid]== search) {
            return mid+1;
            break;
        }
        else if(arr[mid]< search){
            i= mid +1;
        }
        else if(arr[mid] > search) {
            j= mid-1;
        }
    }
    return -1;
}
int main() {
    int arr[] = { 1,4,5,7,9,11,23,45};
    int size = 8;
    int search;
    cout<< "enter the elemnet to search"<< endl;
    cin>> search;
    printarray(arr,size);
    int key = binary_search(arr, size, search);
    cout<< key<< endl;

}