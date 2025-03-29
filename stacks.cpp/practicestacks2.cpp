#include<iostream>
#include<stack>
#include<limits.h>
using namespace std;

void getmiddle(stack<int>&sp, int& size, int& mid){
    if(size== mid){
        cout<< sp.top()<< endl;
        return;
    }
    int temp= sp.top();
    sp.pop();
    size--;
    getmiddle(sp,size,mid);
    sp.push(temp);
}
void insertatbottom(stack<int>&sp, int &element ){
    if(sp.empty()){
        sp.push(element);
        return;
    }
    int temp= sp.top();
    sp.pop();
    insertatbottom(sp,element);
    sp.push(temp);
}
void reversestack(stack<int>&sp){
    if(sp.empty()){
        return;
    }
    int temp= sp.top();
    sp.pop();
    reversestack(sp);
    insertatbottom(sp,temp);
}
void insertinstack(stack<int>&sp, int& element){
    if( sp.empty() || sp.top() <element){
        sp.push(element);
        return;
    }
    int temp= sp.top();
    sp.pop();
    insertinstack(sp, element);
    sp.push(temp);
}
void sortstack(stack<int>&sp){
    if(sp.empty()){
        return;
    }
    int temp= sp.top();
    sp.pop();
    sortstack(sp);
    insertinstack(sp, temp);
    // timecomplexity O(n2);
}
int main(){
    stack<int>sp;
    sp.push(9);
    sp.push(8);
    sp.push(5);
    sp.push(12);
    sp.push(10);
    int size= sp.size();
    int mid;
    if(size&1){
         mid= sp.size()/2 +1;
    }
    else{
        mid= sp.size()/2;
    }
    int element;
    sortstack(sp);
    
    for(int i=0; i< size; i++){
        cout<< sp.top()<< endl;
        sp.pop();
    }
    //getmiddle(sp,size,mid);
}




// class Stack{
//     public:
//     int *arr;
//     int size;
//     int top;

//     Stack(int size){
//         int *arr = new int[size];
//         this-> size= size;
//         this-> top=-1;
//     }
//     void push(int data){
//         if(top== size-1){
//             cout<< "Stack Overflow" << endl;
//         }
//         else{
//             top++;
//             arr[top]= data;
//         }
//     }
//     void pop(){
//         if(top==-1){
//             cout<< "Stack Underflow"<< endl;
//         }
//         else {
//             top--;
//         }
//     }
//     bool isEmpty(){
//         if(top==-1){
//             return true;
//         }
//         else{
//             return false;
//         }
//     }
//     bool isFull(){
//         if(top== size-1){
//             return true;
//         }
//         else {
//             return false;
//         }
//     }

//     int gettop(){
//         if(top== -1){
//             return INT_MAX;
//         }
//         else {
//             return arr[top];
//         }
//     }
//     void printstack(){
//         cout<< "Stack is: "<< endl;
//         for(int i=0; i< size; i++){
//             cout<< arr[i]<< endl;
//         }
//     }
    
// }