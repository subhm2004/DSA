// sort all negative and positive numbers in an array
#include<iostream>
using namespace std;
void sortarray(int *arr, int size) {
    int j=0;
    for(int i=0; i<size; i++) {
        if(arr[i] < 0) {
            swap(arr[i],arr[j] );
            j++;
        }
    }
}
// sort colors
void sortcolor(int arr[], int size) {
    int j=0, k= size-1;
    int i=0;
    while(i <= k) {
        if(arr[i] == 0) {
            swap(arr[i], arr[j]);
            j++;
            i++;
        }
        else if(arr[i] == 2) {
            swap(arr[i], arr[k]);
            k--;
        }
        else {
            i++;
        }
    }
}
void printarray(int arr[], int size) {
    for(int i=0; i<size; i++) {
        cout<< arr[i]<< " ";
    }
}
int main() {
    int arr[] = {1,0,2,2,1,0,1,0,2};
    int size = 9;
    //sortarray(arr,size);
    sortcolor(arr,size);
    printarray(arr,size);
}