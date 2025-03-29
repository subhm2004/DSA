#include<iostream>
#include<limits.h>
using namespace std;
class Stack{
    public:
    int *arr;
    int size;
    int top;
    // ctor called
    Stack(int size){
        int *arr= new int[size];
        this-> size= size;
        this-> top= -1;
    }
    void push(int data){
        if(top == size-1){
            cout<< "stack overflow"<< endl;
            return;
        }
        else {
            top= top + 1;
            arr[top]= data;
        }
    }
    int pop(){
        if(top== -1){
            cout<< "stack underflow can't delete"<< endl;
            return INT_MIN;
        }
        else {
            int x= arr[top];
            top= top-1;
            return x;
        }
    }
    int gettop(){
        if(top == -1){
            cout<< "stack underflow"<< endl;
            return INT_MAX;
        }
        else {
            return arr[top];
        }
    }
    int getsize(){
        if(top==-1){
            cout<< "Stack is empty"<< endl;
        }
        else {
            return top+1;
        }
    }
    bool isEmpty(){
        if(top==-1){
            return true;
        }
        else {
            return false;
        }
    }
    bool isfull(){
        if(top== size-1){
            return true;
        }
        else {
            return false;
        }
    }
    void print(){
        cout<< "Stack:"<< endl;
        for(int i=top; i>=0; i--){
            cout<< arr[i]<< endl;
        }
    }
};
int main(){
    cout<< "Name: Vanshika Aggarwal"<< endl;
    cout<< "Roll No. 22001003138"<< endl;
    Stack* sp= new Stack(5);
    sp-> push(10);
    sp-> push(20);
    sp-> push(30);
    sp-> push(40);
    sp-> push(50);
    sp-> print();
    cout<< "Size of stack is: "<< sp-> getsize() << endl;
    cout<< "Is stack full: "<< sp-> isfull()<< endl;
    cout<< "popped: "<< sp-> pop()<< " from stack "<< endl;
    cout<< "New stack is:"<< endl;
    sp-> print();   
}
