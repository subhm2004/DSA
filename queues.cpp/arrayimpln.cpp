#include<iostream>
using namespace std;
class Queue{
    public:
    int *arr;
    int size;
    int front;
    int rear;
    Queue(int s){
        this-> size= s;
        this-> front =-1;
        this-> rear= -1;
        arr= new int[size];
    }
    bool isfull(){
        if(rear== size-1){
            return true;
        }
        else {
            return false;
        }
    }
    bool isempty(){
        if(front== -1 && rear== -1){
            return true;
        }
        else {
            return false;
        }
    }
    void push(int data){
        if(isfull()){
            cout<< "queue overflow"<< endl;
        }
        else {
            rear++;
            if(front == -1){
                front=0;
            }
            arr[rear]= data;
        }
    }
    void pop(){
        if(isempty()){
            cout<< "queue underflow"<< endl;
        }
        else {
            if(front== rear){
                // single element
                front= -1;
                rear= -1;
            }
            else {
                arr[front]=0;
                front++;
            }
        }
    }
    int getfront(){
        if(!isempty()){
            return arr[front];
        }
    }
    int getrear(){
        if(!isempty()){
            return arr[rear];
        }
    }
    void printqueue(){
        cout<< "front is: "<< front<< endl;
        cout<< "rear is: "<< rear<< endl;
        for(int i=0; i< size; i++){
            cout<< arr[i]<< " ";
        }
    }

};
int main(){
    Queue* q= new Queue(8);
    q->push(10);
    q->push(20);
    q->push(30);
    q->printqueue();
    cout<< endl;
    q->push(40);
    q->push(50);
    q->printqueue();
    cout<< endl;
    q->pop();
    q->printqueue();

}