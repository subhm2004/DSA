// also known as doubling search,galloping serach and strazik search
// application- for infinite array(unbounded array)
// time complexity: O(log(2^(log m)-1)
#include<iostream>
#include<algorithm>
using namespace std;
int binarysearch(int *arr, int& size, int s, int e, int& target){
    int mid= s+(e-s)/2;
    while(s<=e){
        if(arr[mid]== target){
            return mid;
        }
        else if(arr[mid]> target){
            e= mid-1;
        }
        else{
            s= mid+1;
        }
        mid= s+(e-s)/2;
    }
    return -1;
}
int exponential(int *arr, int& size, int& target){
    if(arr[0]== target){
        return 0;
    }
    int i=1;
    while(i<size && arr[i]<= target){
        i= i<<1;
    }
    return binarysearch(arr, size, i/2, min(i,size-1),target);
}
int main(){
    int arr[] = {3,4,5,6,11,13,14,15,56,70};
    int size= 10;
    int target= 70;
    int ans= exponential(arr,size,target);
    cout<< ans<< endl;


}