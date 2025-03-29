// mereg two sorted arrays without consuming extra space
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void partitioning(vector<int> &arr2, int s,int e){
    int pivotindex= s;
    int pivotelement= arr2[s];
    int count=0;
    for(int i=s+1; i<=e; i++){
        if(arr2[i]< arr2[s]){
            count++;
        }
    }
    int rightindex= s+count;
    swap(arr2[rightindex], arr2[pivotindex]);
    pivotindex= rightindex;
    int i=s, j= e;
    while(i< pivotindex && j> pivotindex){
        while(arr2[i]< arr2[pivotindex]){
            i++;
        }
        while (arr2[j]> arr2[pivotindex]){
            j--;
        }
        if(i< pivotindex && j> pivotindex){
            swap(arr2[i], arr2[j]);
        }
    }
    cout<< "second array is\n";
    for(int i=0; i< arr2.size(); i++){
        cout<< arr2[i] << " ";

    }
    cout<< endl;
}
void inplacesorting(vector<int>&arr1, vector<int>& arr2){
    int i=0, j=0;
    int s=0, e= arr2.size()-1;
    while(i<arr1.size()){
        if(arr1[i]<= arr2[j]){
            i++;
        }
        else {
            swap(arr1[i], arr2[j]);
            sort(arr2.begin(), arr2.end());
        }
    }
}
int main(){
    vector<int>arr1{1,2,8,9,12,13};
    vector<int>arr2{3,4,7,10};
    inplacesorting(arr1,arr2);
    //printing array 1
    for(int i=0; i< arr1.size(); i++){
        cout<< arr1[i]<< " ";
    }
    cout<< endl;
    for(int i=0; i< arr2.size(); i++){
        cout<< arr2[i]<< " ";
    }
}