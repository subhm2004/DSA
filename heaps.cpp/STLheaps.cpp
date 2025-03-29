#include<iostream>
#include<queue>
using namespace std;
int findingksmallest(priority_queue<int, vector<int>, greater<int>> p, int& k){
    if(p.empty()){
        return -1;
    }
    while(k!= 1){
        p.pop();
        k--;
    }
    return p.top();
}
int main(){
    // declaring max-heap
    priority_queue<int>pq;
    // inserting element into pq
    pq.push(10);
    pq.push(20);
    pq.push(30);
    pq.push(40);
    pq.push(50);
    // accessing elements
    cout<< "topmost element of queue"<< pq.top()<< endl;
    // deleting element
    pq.pop();
    cout<< "topmost element of queue: "<< pq.top()<< endl;
    cout<< "size of queue is: "<< pq.size()<< endl;
    // check for empty or not
    if(pq.empty()){
        cout<< "empty"<< endl;
    }
    else {
        cout<< "not empty"<< endl;
    }
    // creating min-heap
    priority_queue<int, vector<int>, greater<int>> p;
    // inserting element
    p.push(10);
    p.push(20);
    p.push(30);
    p.push(40);
    p.push(50);
    p.push(60);
    if(p.empty()){
        cout<< "empty"<< endl;
    }
    else {
        cout<< "not empty"<< endl;
    }
    // finding kth smallest elemnt
    int k;
    cout<< "enter k"<< endl;
    cin>> k;
    int ans= findingksmallest(p,k);
    cout<< "kth smallest element is: "<< ans << endl;





}