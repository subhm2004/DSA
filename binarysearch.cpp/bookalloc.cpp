// allocate n books to m students such that 
// maximum pages allocated to a student is minimum
#include<iostream>
#include<algorithm>
#include<numeric>
using namespace std;
bool ispossible(int *arr, int& student, int& size, int mid){
    int scount = 1;
    int pagesum = 0;
    if(student> size){
            return false;
        }
    for(int i=0; i<size; i++){
        if(pagesum + arr[i]<= mid){
            pagesum= pagesum+ arr[i];   
        }
        else {
            scount++;
            if(scount> student || arr[i]> mid) {
                return false;
            }
            pagesum= arr[i];
        }
    }
}
int findpages(int *arr, int& size, int& student){
    int s=0;
    int e= accumulate(arr, arr+size, 0);
    int mid= s+(e-s)/2;
    int ans= -1;
    while(s<=e){
        if(ispossible(arr,student,size,mid)){
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
    int arr[]= {12,34,67,90};
    int size= 4;
    int student= 2;
    int ans= findpages(arr,size,student);
    cout<< ans<< endl;
}