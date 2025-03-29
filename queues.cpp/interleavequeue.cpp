#include<iostream>
#include<stack>
#include<queue>
using namespace std;
int main(){
    queue<int>q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);
    int n= q.size()/2;
    queue<int>q1;
    while(n--){
        q1.push(q.front());
        q.pop();
    } 
    queue<int>q2;
    while(!q.empty()&& !q1.empty()){
        q2.push(q1.front());
        q2.push(q.front());
        q.pop();
        q1.pop();
    }
    while(!q2.empty()){
        cout<< q2.front()<< " ";
        q2.pop();
    }
    // solve without taking new queue

}