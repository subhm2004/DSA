//gap method is very important for in place merging
#include <bits/stdc++.h>
using namespace std;
void inplacemerging(vector<int> &arr, int& s, int& e){
    int gap= (e+1)/2 +(e+1)%2;
    while(gap>=1){
         int i=0;
         int j=i+gap;
         while(j<= e){
            if(arr[i]> arr[j]){
            swap(arr[i], arr[j]);
            i++;
            j++;
            }
            else{
            i++;
            j++;
            }
         }
         if(gap==1){
            return;
         }
         gap= (gap/2)+ (gap%2);   
    }
}
void mergesort(vector<int> &arr, int s, int e){
    if(s>=e){
        return;
    }
    int mid= s+(e-s)/2;
    mergesort(arr,s,mid);
    mergesort(arr,mid+1,e);
    inplacemerging(arr,s,e);
}
int main(){
    vector<int>arr{1,2,8,9,12,13,3,4,7,10};
    int s=0, e= arr.size()-1;
    mergesort(arr,s,e);
    cout<< "Array after in place merging is"<< endl;
    for(int i=0; i< arr.size(); i++){
        cout<< arr[i]<< " ";
    }
}