#include<iostream>
using namespace std;
int partition(int* arr, int s, int e ) {
    int pivotindex = s;
    int pivotelement = arr[s];
    int count =0;
    for(int i=s+1; i<=e; i++) {
        if(arr[i] <= pivotelement) {
            count++;
        }
    }
    int rightindex = s + count;
    swap(arr[pivotindex], arr[rightindex]);
    pivotindex = rightindex;
    int i=s, j= e;
    while(i< pivotindex && j> pivotindex) {
        while(arr[i] < pivotelement) {
            i++;
        }
        while(arr[j] > pivotelement) {
            j--;
        }
        if(i< pivotindex && j> pivotindex) {
            swap(arr[i], arr[j]);
        }
    }
    return pivotindex;
}
void quicksort(int* arr, int s, int e) {
    if(s>=e) {
        return;
    } 
    int p= partition(arr, s, e);
    quicksort(arr, s, p-1);
    quicksort(arr, p+1, e);
}
int main() {
    int arr[] = {8,1,3,4,20,50,30};
    int size = 7;
    int s=0, e = size-1;
    quicksort(arr, s, e);
    cout<< "Name: Vanshika Aggarwal"<< endl;
    cout<< "Roll No. 22001003138"<< endl;
    cout<< "sorted array is "<< endl;
    for(int i=0; i<size; i++) {
        cout<< arr[i] << " ";
    } 
    cout<< endl;
}

