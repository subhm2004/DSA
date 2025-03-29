// find the missing element in the sorted array
//problem of relating index with element
#include<iostream>
using namespace std;
// int missing(int *arr, int& size) {
//     int s=0, e= size-1;
//     int mid= s+(e-s)/2;
//     while(s<=e) {
//         if(arr[mid] == mid+1) {
//             if(s==e) {
//                 return arr[mid] + 1;
//             }
//             s= mid+1;
//         }
//         else{
//             if(s==e) {
//                 return arr[mid] -1;
//             }
//             e = mid-1;
//         }
//         mid = s/2 + e/2;
//     }
// }
int missingelement(int *arr, int& size){
    int s=0, e= size-1;
    int mid= s+(e-s)/2;
    while(s<=e){
        if(arr[mid]== mid+1){
            if(s==e){
                return arr[mid]+1 ;
            }
            s= mid+1;
        }
        else {
            if(s==e){
                return arr[mid]-1 ;
            }
            e= mid-1;
        }
        mid= s/2 + e/2;
    }
}

int main() {
    int arr[] = {1,2,3,4,5,6,7,9};
    int size = 8;
    int ans= missingelement(arr, size);
    cout<< ans<< endl;
}
