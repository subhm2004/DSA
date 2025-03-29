#include <iostream>
#include<stack>
using namespace std;
// void insertAtBottom(stack<int> &st, int &element) {
//   if(st.empty()) {
//     st.push(element);
//     return;
//   }
//   int temp = st.top();
//   st.pop();
//   insertAtBottom(st, element);
//   st.push(temp);
// }

// void reverseStack(stack<int> &st) {
//   //base case
//   if(st.empty()) {
//     return;
//   }
//   //1 case main solve krega
//   int temp = st.top();
//   st.pop();
//   //refcursion
//   reverseStack(st);
//   //backtrack
//   insertAtBottom(st,temp);
// }
void insertatbottom(stack<int> &sp, int &temp, int &element){
    if(sp.empty()){
        sp.push(element);
        return;
    }
    sp.pop();
    insertatbottom(sp,sp.top(),element);
    sp.push(temp);
}
void reversestack(stack<int> &sp, int &temp, int& element){
    // base case
    if(sp.empty()){
        return;
    }
    sp.pop();
    reversestack(sp,sp.top(), element);
    insertatbottom(sp,temp,temp);
}
int main(){
    stack<int> sp;
    sp.push(10);
    sp.push(20);
    sp.push(30);
    sp.push(40);
    sp.push(50);
    int temp= sp.top();
    int element= sp.top();
    reversestack(sp,temp,element);
    while(!sp.empty()){
        cout<< sp.top()<< endl;
        sp.pop();
    }
}