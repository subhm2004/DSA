#include<iostream>
#include<stack>
#include<queue>
using namespace std;
void reversekgrp(queue<int>&q,int& n, int &k){
    stack<int>st;
    int rem= n-k;
    while(k--){
        st.push(q.front());
        q.pop();     
    }
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
    while(rem--){
        int temp = q.front();
        q.pop();
        q.push(temp);
    }
}
int main(){
    queue<int>q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    int n= q.size();
    int k;
    cout<< "enter k"<< endl;
    cin>> k;
    reversekgrp(q,n,k);
    while(!q.empty()){
        cout<< q.front()<< " ";
        q.pop();
    }
}