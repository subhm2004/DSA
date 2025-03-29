#include<iostream>
#include<queue>
using namespace std;
int getksmallest(int arr[], int &size, int &k){
    priority_queue<int>pq;
    for(int i=0; i<k; i++){
        pq.push(arr[i]);
    }
    for(int i=k; i< size; i++){
        if(arr[i]< pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}
int main(){
    int arr[]= {3,4,7,9,8,1,6};
    int size= 7;
    int k=3;
    int ans= getksmallest(arr,size,k);
    cout<< ans<< endl;   
}