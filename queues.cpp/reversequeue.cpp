#include<iostream>
#include<queue>
#include<stack>
using namespace std;
void reversequeue(queue<int>&q){
    stack<int>st;
    while(!q.empty()){
        st.push(q.front());
        q.pop();
    }
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
}
void recursionreverse(queue<int>&q){
    if(q.empty()){
        return;
    }
    int temp= q.front();
    q.pop();
    recursionreverse(q);
    q.push(temp);
}
int main(){
    queue<int>q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    recursionreverse(q);
}
