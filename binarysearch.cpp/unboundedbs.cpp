// search in an unbounded sorted array
// array with infinite number of elements
#include<iostream>
using namespace std;
int binarysearch(int *arr, int i, int j, int & target){
    int mid= i+j/2;
    while(i<=j){
        if(arr[mid]== target){
            return mid;
        }
        else if(arr[mid]> target){
            j= mid-1;
        }
        else {
            i= mid+1;
        }
        mid= i+j/2;
    }
    return -1;

}
int unboundedsearch(int *arr, int& target){
    int i=0, j= i+1;
    while(arr[j]<target){
        i=j;
        j<<1;
    }
    return binarysearch(arr,i,j,target);

}
int main() {

    
}