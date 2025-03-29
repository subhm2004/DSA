#include<iostream>
using namespace std;
class CQueue{
    public:
    int front;
    int rear;
    int *arr;
    int size;
    CQueue(int s){
        this-> size=s;
        this-> front=-1;
        this-> rear= -1;
        arr= new int[size];
    }
    bool isfull(){
        if((rear== size-1 && front== 0) || (rear== front-1)){
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
    void push(int data){
        if(isfull()){
            cout<< "queue overflow"<< endl;
        }
        else if (rear== size-1 && front!= 0) {
            rear=0;
            arr[rear]= data;
        }
        else {
            if(front== -1 && rear== -1){
                front=0;
            }
            rear++;
            arr[rear]= data;
        }
    }
    void pop(){
        if(isempty()){
            cout<< "stack underflow"<< endl;
        }
        else if(front == rear){
            // single element
            arr[front]=-1;
            front=-1;
            rear=-1;
        }
        // circular nature
        if(front== size-1){
            front=0;
        }
        else {
            arr[front]=0;
            front++;
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
    CQueue* cq= new CQueue(5);
    cq-> push(10);
    cq-> print();

    cq-> push(20);
    cq-> print();

    cq-> push(30);
    cq-> print();

    cq-> push(40);
    cq-> print();
    cq-> push(50);
    cq-> print();

    cq-> pop();
    cq-> print();

    cq-> push(50);
    cq-> print();

}