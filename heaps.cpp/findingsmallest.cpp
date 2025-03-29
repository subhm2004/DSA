#include<iostream>
#include<queue>
using namespace std;
int ksmallest(int arr[], priority_queue<int>pq, int& size, int& k){
    for(int i=0; i<k; i++){
        pq.push(arr[i]);
    }
    for(int i=k; i<size; i++){
        if(arr[i]< pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}
int main(){
    int arr[]= {3,7,4,5,6,8,9};
    int size= 7;
    priority_queue<int>pq;
    int k;
    cout<< "Enter k"<< endl;
    cin>> k;
    cout<< "kth smallest element is: "<< ksmallest(arr,pq,size,k)<< endl;
}