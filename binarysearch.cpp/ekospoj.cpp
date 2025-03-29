// m- metres of wood required by mirko
// h- height of sawblade
// mirko h height se higher wala part kr skta h. find maximum height 
#include<iostream>
#include<algorithm>
using namespace std;
bool ispossible(int *arr, int& size, int& woodreq, int& mid){
    int sum = 0;
    for(int i=0; i<size; i++){
        if(arr[i]- mid> 0){
            sum = sum+ (arr[i]- mid);
        }
    }
    //cout<< sum<< endl;
    if(sum>= woodreq){
        return true;
    }
    else {
        return false;
    }
}
int maximumheight(int *arr, int& size, int& woodreq){
    int maxi= -1;
    for(int i=0; i<size; i++){
        maxi= max(maxi, arr[i]);
    }
    int ans= -1;
    int s=0;
    int e= *max_element(arr, arr+size); // stl function
    int mid= s+(e-s)/2;
    while(s<=e){
        if(ispossible(arr, size,woodreq,mid)){
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
    int arr[]= {4,42,40,26,46};
    int size= 5;
    int woodreq= 20;
    int f= maximumheight(arr,size,woodreq);
    cout<< f<< endl;
}