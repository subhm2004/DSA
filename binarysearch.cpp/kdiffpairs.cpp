// find the different pairs in the array whose difference is k
// method 1: two pointer approach
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
int findpair(int* arr,int& k, int& size){
    sort(arr, arr+size);
    set<pair<int,int>> ans;
    int i=0, j=i+1;
    while(j<size){
        if(arr[j]-arr[i]==k){
            ans.insert(arr[i],arr[j]);
            i++;
            j++;
        }
        else if(arr[j]-arr[i]> k){
            i++;
        }
        else if(arr[j]-arr[i]< k){
            j++;
        }
        if(i==j){
            j++;
        }
    }
    return ans.size();
}
// this two pointer approach will not give distinct pairs, hence set is used.
int binarysearch(int *arr, int& size, int s, int x){
    int e= size-1;
    int mid= s+(e-s)/2;
    while(s<=e){
        if(arr[mid]== x){
            return mid;
        }
        else if(arr[mid]> x){
            e= mid-1;
        }
        else {
            s= mid+ 1;
        }
        mid= s+(e-s)/2;
    }
    return -1;    
}
int findpairs(int *arr, int& size, int & k){
    sort(arr, arr+size);
    set<pair<int,int>> ans;
    for(int i=0; i< size-1; i++){
        if( binarysearch(arr,size,i+1, arr[i]+k)!=-1){
            ans.insert(arr[i], arr[i]+k);
        }
    }
    return ans.size();    
}
int main(){
    int arr[]= {1,1,3,4,5};
    int size= 5;
    int k=2;
    int f= findpairs(arr,size,k);
    cout<< f<< endl;
}