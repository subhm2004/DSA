#include<iostream>
#include<stack>
using namespace std;
void insertatbottom(stack<int> &sp, stack<int> &st, int& element){
    while(!sp.empty()){
        st.push(sp.top());
        sp.pop();    
    }
    st.push(element);
    // cout<< st.top()<< endl;
    while(!st.empty()){
        sp.push(st.top());
        st.pop();
    }
}
// this method takes extra space of a stack, solve without extra space
void insertrec(stack<int> &sp, int& element, int temp){
    if(sp.empty()){
        sp.push(element);
        return;
    }
    sp.pop();
    insertrec(sp,element, sp.top());
    sp.push(temp);
}
int main(){
    int element= 5;
    stack<int>sp;
    sp.push(10);
    sp.push(20);
    sp.push(30);
    sp.push(40);
    sp.push(50);
    stack<int>st;
    int temp= sp.top();
    insertatbottom(sp,st,element);
    cout<< "Stack is : "<< endl;
    while(!sp.empty()){
        cout<< sp.top()<< endl;
        sp.pop();
    }
}