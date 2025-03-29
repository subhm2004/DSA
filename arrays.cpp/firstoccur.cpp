#include<iostream>
using namespace std;

int firstoccur(int arr[], int size,int i=0, int j= 9, int target= 4) {
    int mid = i+ (j-i)/2;
    
    while(i<=j) {
       
        
        if(arr[mid] == target) {
           int ans= mid;
           return ans;
           firstoccur( arr,size,i, j=mid-1, target);
           
                     
        }
        
        else if(arr[mid]< target) {
            i = mid+1;
        }
        else {
            j= mid-1;
        }

    }
    
}
int main() {
    int arr[] = { 1,2,4,4,4,4,4,6,7,9};
    int size = 10;
    int target =4;
    int i=0, j= size-1;
    int foccur = firstoccur(arr,size, i, j, target);
    cout<< "first occurrence of target element is "<< foccur<< endl;
}