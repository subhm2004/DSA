// binary search in a nearly sorted array
// the get all universe
#include<iostream>
#include<vector>
using namespace std;
int nearlysorted(vector<int>arr,  int target) {
    int i=0;
    int j= arr.size() -1;
    int mid= i+(j-i)/2;
    while(i<=j) {
        if(arr[mid]== target) {
            return mid;
        }
        else if(arr[mid+1]== target) {
            return mid+1;
        }
        else if(arr[mid-1]== target) {
            return mid-1;
        }
        else if(arr[mid]> target) {
            j= mid-2;
        }
        else {
            i= mid+2;
        }
        mid = i+(j-i)/2;
    }
    return -1;
   }
   int main() {
    vector<int> arr = {10,3,40,20,50,80,70};
    int target = 70;
    int ans= nearlysorted(arr,target);
    cout<< "index of target element is "<< ans<< endl;
    return 0;
   }
