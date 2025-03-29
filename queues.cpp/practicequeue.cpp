#include<iostream>
using namespace std;
class DEQueue{
    public:
    int *arr;
    int front;
    int rear;
    int size;
    DEQueue(int s){
        this-> size= s;
        this-> front=-1;
        this-> rear=-1;
        arr= new int[size];
    }
    void pushback(int data){
        if((rear== size-1&& front==0)|| (rear+1== front)){
            cout<< "Queue Overflow"<< endl;
        }
        else if(front==-1){
            front=0;
            rear++;
            arr[rear]= data;
        }
        else if(front!=0 && rear==size-1){
            rear=0;
            arr[rear]= data;
        }
        else {
            rear++;
            arr[rear]= data;
        }
    }
    void popfront(){
        if(front==-1 && rear==-1){
            cout<< "Queue underflow"<< endl;
        }
        else if(front== rear){
            arr[front]=-1;
            front=-1;
            rear=-1;
        }
        else if(front== size-1){
            arr[front]=-1;
            front=0;
        }
        else {
            arr[front]=-1;
            front++;
        }
    }
    void popback(){
        if(front==-1 && rear==-1){
            cout<< "Queue Overflow"<< endl;
        }
        else if(front== rear){
            arr[rear]=-1;
            rear=-1;
            front=-1;
        }
        else if(rear==0){
            arr[rear]= -1;
            rear= size-1; 
        }
        else {
            arr[rear]=-1;
            rear--;
        }
    }
    void pushfront(int data){
        if((front==0 && rear==size-1)||(rear+1== front)){
            cout<< "Queue Overflow"<< endl;
        }
        else if(front==-1 && rear==-1){
            front++;
            rear++;
            arr[front]= data;
        }
        else if(front==0 && rear!= size-1){
            front= size-1;
            arr[front]= data;
        }
        else{
            front--;
            arr[front]=data;
        }
    }
};
int main(){

}