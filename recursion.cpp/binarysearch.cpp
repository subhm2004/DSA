// binary search using recursion
#include<iostream>
using namespace std;

int binarysearch(int arr[], int& size, int i, int j, int& target) {
    // base case
    if(i>j) {
        return -1;
    }
    int mid = i + (j-i)/2;
    if(arr[mid] == target) {
        return mid+1;
    }
    if(arr[mid] > target) {
        return binarysearch(arr , size, i, mid-1,target );
    }
    if(arr[mid] < target) {
        return binarysearch(arr, size, mid+1, j, target);
    }
}
int main() {
    int arr[] = {12,23,34,45,56,57} ;
    int size = 6;
    int i=0, j= size-1;
    int target = 56 ;
    int ans = binarysearch(arr, size, i, j, target);
    cout<< "element is present at "<< ans << endl;
    return 0;
}