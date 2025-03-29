// given a sorted array, find the total occurence of an element
#include<iostream>
using namespace std;
int firstocc(int *arr, int& size, int& target) {
    int s=0, e= size-1;
    int mid= s+(e-s)/2;
    int ans= -1;
    while(s<=e) {
        if(arr[mid] == target) {
            ans = mid;
            // left me search kro
            e= mid-1;
        }
        else if(arr[mid] > target) {
            e= mid-1;
        }
        else {
            s= mid+1;
        }
    }
    return ans;
}
int lastocc(int *arr, int& size, int& target) {
    int s=0, e= size-1;
    int mid= s+(e-s)/2;
    int ans1 = -1;
    while(s<=e) {
        if(arr[mid] == target) {
            ans1 = mid;
            s= mid+1;
        }
        else if(arr[mid] < target) {
            s= mid+1;
        }
        else {
            e= mid-1;
        }
    }
    return ans1;
}
int totalocc(int *arr, int& size, int& target) {
    int c= lastocc(arr, size, target);
    int d= firstocc(arr, size, target);
    int total = c -d + 1;
    return total;
}
int main() {
    int arr[] = {10,20,30,30,30,30,30,40,50,60};
    int size= 10;
    int target = 30;
    int a= totalocc(arr, size, target);
    cout<< a<< endl;    
}