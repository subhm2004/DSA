#include<iostream>
using namespace std;
int sqrt(int arr[], int size, int n) {
    int i=0, j=size-1;
    int mid = i+ (j-i)/2;
    int ans=0;
    while(i<=j) {
        if (arr[mid]* arr[mid] > n) {
            j= mid-1;
        }
        else if(arr[mid]* arr[mid] < n) {
            ans= mid;
            i= mid+1;
        }
        else if(arr[mid]* arr[mid] == n) {
            return mid;
        }
        mid= i+ (j-i)/2;
    }
    return ans;

}
int main() {
    int n=10;
    int arr[] = {0,1,2,3,4,5,6,7,8,9,10};
    int size = 11;
    int binary = sqrt(arr, size, n);
    cout<< " integral part of sqrt of " << n << " is "<< binary<< endl;
    return 0;
}