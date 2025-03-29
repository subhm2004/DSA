#include<iostream>
using namespace std;
class Stack{
    public:
    int size= 5;
    int arr[5];
    int top;
    Stack(){
        // ctor
        top= -1;
        bool isEmpty();
        bool isFull();
        void push(int data);

    }
    bool isEmpty(){
        if(top== -1){
            return true;
        }
        else {
            return false;
        }
    }
    bool isFull(){
        if(top== size-1){
            return true;
        }
        else {
            return false;
        }
    }
    void push(int data){
        if(isFull()){
            cout<< "Stack Overflow "<<" can't push "<< data<< " into the stack" <<endl;
            return;
        }
        else {
            top++;
            arr[top]= data;
            cout<< "pushed "<< data<< "in the stack "<< endl;
        }
    }
    int pop(){
        if(isEmpty()){
            return -1;
        }
        else {
            int x= arr[top];
            top--;
            cout<< "popped "<< x<< " from stack"<< endl;
            return x;
        }
    }
};
int main(){
    
    Stack* s= new Stack();
    s-> push(10);
    s-> push(20);
    s-> push(30);
    s-> push(40);
    s-> push(50);
    s-> push(60);
    

}