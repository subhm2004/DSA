#include<iostream>
using namespace std;
class DEqueue{
    public:
    int *arr;
    int front;
    int rear;
    int size;

    DEqueue(int s){
        this-> size= s;
        front=-1;
        rear=-1;
        arr= new int[size];
    }
    bool isfull(){
        if((rear== size-1 && front==0)|| (rear== front-1)){
            return true;
        }
        else {
            return false;
        }
    }
    bool isempty(){
        if(front==-1 && rear== -1){
            return true;
        }
        else {
            return false;
        }
    }
    void pushrear(int data){
        if(isfull()){
            cout<< "overflow"<< endl;
        }
        // circular nature
        else if(rear== size-1 && front!=0){
            rear=0;
            arr[rear]= data;
        }
        else {
            if(front ==-1){
                front=0;
            }
            rear++;
            arr[rear]= data;
        }
    }
    void popfront(){
        if(isempty()){
            cout<< "underflow"<< endl;
        }
        else if(front== rear){
            arr[front]=-1;
            front= -1;
            rear= -1;
        }
        else if(front==size-1){
            arr[front]=-1;
            front=0;
        }
        else{
            arr[front]=-1;
            front++;
        }
    }
    void pushfront(int data){
        if(isfull()){
            cout<< "overflow"<< endl;
        }
        // 1st insertion
        else if(front==-1 && rear== -1){
            front=rear=0;
            arr[front]= data;
        }
        // circular nature
        else if(front== 0 && rear!=size-1){
            front=size-1;
            arr[front]= data;
        }
        else {
            front--;
            arr[front]= data;
        }
    }
    void poprear(){
        if(isempty()){
            cout<< "underflow"<< endl;
        }
        else if(rear== front){
            arr[rear]= -1;
            rear=-1;
            front=-1;
        }
        // circular nature
        else if(rear== 0){
            rear= size-1;
        }
        else {
            arr[rear]=-1;
            rear--;
        }
    }
    void print(){
        cout<< "front: "<< front<< endl;
        cout<< "rear: "<< rear<< endl;
        for(int i=0; i< size; i++){
            cout<< arr[i]<< " ";
        }
        cout<< endl;
    }
};
int main(){
    DEqueue* deq= new DEqueue(5);
    deq->print();
    deq->pushrear(10);
    deq->print();
    deq->pushfront(20);
    deq->print();
    deq->pushfront(70);
    deq->print();
    deq->pushrear(50);
    deq->print();
    deq->pushfront(30);
    deq->print();
    deq->popfront();
    deq->print();
    deq->popfront();
    deq->print();
    deq->popfront();
    deq->popfront();
    deq->print();





}