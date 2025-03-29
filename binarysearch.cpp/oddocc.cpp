// find the element occurring odd number of times
//all elements occur even number of times except one, find that
#include<iostream>
#include<vector>
using namespace std;
int oddoccurence(vector<int>& arr) {
    int s=0, e= arr.size()-1;
    int mid= s+(e-s)/2;
    while(s<=e) {
        if(s==e){
            return s;
        }
        if(mid&1){ //fast method to check odd/even number
            if(mid-1>0 && arr[mid]== arr[mid-1]){
                s= mid+1;
            }
            else {
                e= mid-1;
            }
        }
        else {
            if(mid+1< arr.size() && arr[mid]== arr[mid+1]){
                s= mid+2;
            }
            else{
                e= mid;
            }
        }
        mid= s+(e-s)/2;
    }
}
int main(){
    vector<int>arr= {10,10,5,5,2,2,5,5,20,20,10,10,11,11,1};
    int ans= oddoccurence(arr);
    cout<< ans<< endl;
}