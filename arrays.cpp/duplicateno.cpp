// you are given an array of n+1 integers 
// numbers in the array are ranging from 1 to n 
// an elemnt is repeating at least twice, find the duplicate number
#include<iostream>
#include<algorithm>
using namespace std;
int duplicate (int *arr, int& size) {
    sort(arr, arr+size); // this sln takes timecomplexity nlogn
    for(int i=0; i<size-1; i++) {
        if(arr[i]== arr[i+1] ) {
            return arr[i];
        }
    }
    return -1;
}
int duplicate2(int *arr, int& size) {
    
}
int main() {
    int arr[] = {1,2,4,4,3};
    int size = 5;
    int ans = duplicate(arr, size);
    cout<< ans<< endl;
}
