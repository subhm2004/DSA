#include<iostream>
#include<numeric>
using namespace std;
bool ispossiblesln(int *arr, int& size, int& k, int mid){
    int paintercount= 1;
    int boardlenalloc=0;
    for(int i=0; i<size; i++){
        if(boardlenalloc+ arr[i]<= mid){
            boardlenalloc+= arr[i];
        }
        else {
            paintercount++;
            if(paintercount> k || arr[i]> mid){
                return false;
            }
            else {
                boardlenalloc=arr[i];
            }
        }
    }
}
int mintime(int *arr, int& size, int& k){
    int s=0;
    int e= accumulate(arr,arr+size, 0);
    int mid= s+(e-s)/2;
    int ans= -1;
    while(s<=e){
        if(ispossiblesln(arr,size,k,mid)){
            ans= mid;
            e= mid-1;
        }
        else {
            s= mid+1;
        }
        mid= s+(e-s)/2;
    }
    return ans;
}
int main(){
    int arr[]= {5,10,30,20,15};
    int size= 5; // number of boards= length of array
    int k= 3;
    int ans= mintime(arr,size,k);
    cout<< ans<< endl;

}