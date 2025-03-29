#include<iostream>
#include<queue>
using namespace std;
int findksmallest(int arr[], int &k, int& size){
    priority_queue<int, vector<int>, greater<int>>pq;
    for(int i=0; i<size; i++){
        pq.push(arr[i]);
    }
    while(k!=1){
        pq.pop();
        k--;
    }
    return pq.top();
}
int main(){
    int arr[]= {3,2,9,7,6,5,1,8};
    int size= 8;
    int k=4;
    int ans= findksmallest(arr,k, size);
    cout<< ans<< endl;
}


















