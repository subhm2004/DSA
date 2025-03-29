// twosum
#include<iostream>
using namespace std;

bool twosum(int arr[], int& size, int& sum) {
    for(int i=0; i< size-1; i++) {
        for(int j=i+1; j< size; j++) {
            if(arr[i] + arr[j]== sum) {
                return true;
            }
        }
    }
    return false;
}
void bubblesort(int arr[], int size) {
    for(int i=0; i<size; i++) {  // loop for number of rounds
        for(int j=0; j< size-i-1; j++) {
            if(arr[j]> arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}
void printarray(int arr[], int size) {
    for(int i=0; i< size; i++) {
        cout<< arr[i] << " ";
    }
}
void merge(int arr[], int& s, int& e) {
    int mid = s+(e-s)/2;
    int length1 = mid -s+1;
    int length2= e- mid;
    int* left= new int[length1];
    int* right = new int[length2];
    // copy the values of left sorted array in dynamically made left array
    int k=s;
    for(int i=0; i<length1; i++) {
        left[i] = arr[k];
        k++;
    }
    // copy the values of right sorted array into dynamically made right array
    k = mid+1;
    for(int i= 0; i< length2; i++) {
        right[i] = arr[k];
        k++;
    }
    int i=0, j=0;
    int mainindex = s;
    while(i< length1 && j< length2) {
        if(left[i]< right[j]) {
            arr[mainindex++] = left[i++] ;
        }
        else {
            arr[mainindex++] = right[j++];
        }   
    }
    while(i< length1) {
        arr[mainindex++] = left[i++];
    }
    while(j< length2){
        arr[mainindex++] = right[j++];
    }
}
void mergesort(int arr[], int s, int& e) {
    if(s>=e) {
        return;
    }
    int mid = s+(e-s)/2;
    // left part ko sort karo
    mergesort(arr, s, mid);
    // right part ko sort karo 
    mergesort(arr, mid+1, e);
    // merge both the arrays
    merge(arr, s, e);
}
void twosum2(int arr[], int& size,int& s, int& e, int& sum) {
    mergesort(arr, s, e);
    printarray(arr, size);
    cout<< endl;
    int i=0, j= size-1;
    while(i<j) {
        if(arr[i] + arr[j] == sum) {
            cout<< arr[i]<< " "<< arr[j]<< endl;
            break;
        }
        else if(arr[i] + arr[j] > sum) {
            j--;
        }
        else {
            i++;
        }
    }
}
int main() {
    int arr[] = {1,45,4,6,10,8};
    int size = 6;
    int s=0, e= size-1;
    int sum = 16;
    twosum2(arr, size, s, e, sum);
    // bool ans = twosum(arr, size, sum);
    // cout<< ans<< endl;
    
}