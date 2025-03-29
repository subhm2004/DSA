// merge sort
#include<iostream>
using namespace std;
void merge(int* arr, int s, int e) {
    int mid = s+(e-s)/2;
    int length1 = mid-s+1;
    int length2 = e-mid;
    // creating two arrays
    int* left = new int[length1];
    int* right = new int[length2];
    // copying the values in left array
    int k=s;
    for(int i=0; i<length1; i++) {
        left[i] = arr[k];
        k++;
    }
    // copying the values in right array
    k= mid+1;
    for(int i=0; i< length2; i++) {
        right[i] = arr[k];
        k++;
    }
    // values are copied in two different arrays, now merge the two arrays
    int i=0, j=0;
    k=s;
    while(i<length1 && j< length2) {
        if(left[i]< right[j]) {
            arr[k++] = left[i++];
        }
        if(left[i] >= right[j]) {
            arr[k++] = right[j++];
        }
    }
    while(i<length1) {
        arr[k++] = left[i++];
    }
    while(j< length2) {
        arr[k++] = right[j++];
    }
}
 
 void mergesort(int* arr, int s, int e) {
    if(s>=e) {
        return;
    }
    int mid = s+ (e-s)/2;
    // recurcive call for left array
    mergesort(arr, s, mid);
    // recurcive call for right array
    mergesort(arr, mid+1, e);
    // merge the two arrays
    merge(arr, s, e);

}
int main() {
    int arr[]= {4,2,12,5,13};
    int size = 5;
    int s=0, e = size-1;
    mergesort(arr,s,e);
    // printing the sorted array
    cout<< "sorted array is"<< endl;
    for(int i=0; i< size; i++) {
        cout<< arr[i] << " ";
    }
}
