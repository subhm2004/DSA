#include<iostream>
using namespace std;
int peakelement(int *arr, int& size) {
    int s=0, e= size-1;
    int mid = s+(e-s)/2;
    int ans=-1;
    while(s<e) {
        if(arr[mid] < arr[mid+1]) {
            s= mid+1;
        }
        else if(arr[mid]> arr[mid+1]) {
            ans= mid;
            e= mid;
        }
        mid= s+(e-s)/2;    
    }
    return ans;
}
int main() {
    int arr[] = {5,10,15,11,9,8,7,6,5};
    int size= 9;
    int ans = peakelement(arr, size);
    cout<< ans<< endl;

}