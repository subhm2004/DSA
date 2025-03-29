#include<iostream>
using namespace std;

int binarysearch(int *arr, int& size, int s, int e, int& target){
    s=0, e= size-1;
    int mid= s+(e-s)/2;
    while(s<=e){
        if(arr[mid]== target){
            return mid;
        }
        else if(arr[mid]> target){
            e= mid-1;
        }
        else {
            s= mid+1;
        }
        mid= s+(e-s)/2;
    }
    return -1;
}
int main(){
    cout<< "Name: Vanshika Aggarwal"<< endl;
    cout<< "Roll No. 22001003138"<< endl;
    int arr[] = {12,14,15,16,2,4,6,8,10};
    int size= 9;
    int s=0, e= size-1;
    int target= 4;
    int ans= binarysearch(arr,size,s,e,target);
    if(ans!= -1){
        cout<< "target found at index :"<< ans<< endl;
    }
    else {
        cout<< "target not found"<< endl;
    }
    
 }