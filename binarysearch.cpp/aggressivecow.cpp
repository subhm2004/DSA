// place k cows such that minimum distance between them is maximum
#include<iostream>
#include<algorithm>
using namespace std;
bool ispossible(int *arr, int& size, int& mid, int& k){
    int cowcount= 1;
    int stallallocate= arr[0];
    for(int i=1; i<size; i++){
        if(arr[i]-stallallocate>= mid){
            cowcount++;
            stallallocate= arr[i];
        }
        if(cowcount==k){
            return true;
        }
    }
    return false;
}
int mindistance(int *arr, int& size, int& k){
    sort(arr,arr+size);
    int s=0;
    int e= arr[size-1];
    int mid= s+(e-s)/2;
    int ans= -1;
    while(s<=e){
        if(ispossible(arr,size,mid,k)){
            ans= mid;
            s= mid+1;
        }
        else {
            e= mid-1;
        }
        mid= s+(e-s)/2;
    }
    return ans;
}
int main(){
    int arr[]= {10,1,2,7,5};
    int size= 5;
    int k= 3;
    int ans= mindistance(arr,size,k);
    cout<< ans<< endl;
}