#include<iostream>
#include<queue>
using namespace std;
int kgreatest(int arr[], int& size, int& k){
    priority_queue<int, vector<int>, greater<int>>pq;
    for(int i=0; i<k; i++){
        pq.push(arr[i]);
    }
    for(int i=k; i<size; i++){
        if(arr[i]> pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}
int main(){
    int arr[]= {3,6,9,8,7,1,2};
    int size= 7;
    int k=3;
    int ans= kgreatest(arr,size,k);
    cout<< ans<< endl;
}