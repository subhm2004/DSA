// apply binary search in a nearly sorted array
// nearly sorted array is the one in which element at ith index in sorted array
// is at i+1 or i-1 orith position in nearly sorted array
#include<iostream>
using namespace std;
int nearlysorted(int *arr, int& size, int& target){
    int s=0, e= size-1;
    int mid= s+(e-s)/2;
    while(s<=e){
        if(arr[mid]== target){
            return mid;
        }
        else if(mid-1>=0 && arr[mid-1]== target){
            return mid-1;
        }
        else if(mid+1 < size && arr[mid+1]== target){
            return mid+1;
        }
        else if(arr[mid]> target){
            e= mid-2;
        }
        else{
            s= mid+2;
        }
        mid= s+(e-s)/2;    
    }
    return -1;
}
int main(){
    int arr[]={20, 10, 30, 50, 40, 70, 60};
    int size= 7;
    int target= 20;
    int ans= nearlysorted(arr, size, target);
    cout<< ans<< endl;
}