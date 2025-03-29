#include<iostream>
using namespace std;
class Queue{
    public:
    int size= 5;
    int arr[5];
    int front;
    int rear;
    Queue(){
        front = -1;
        rear= -1;
        bool isEmpty(); 
        bool isFull();
    }
     bool isEmpty() {
        if(front== -1|| front> rear){
            return true;
        }
        else {
            return false;
        }
    }
    bool isFull(){
        if(rear== size-1){
            return true;
        }
        else{
            return false;
        }
    }
    void enqueue(int data){
        if(isFull()){
            cout<< "Can't enqueue "<< data<< " in the queue"<< endl;
        }
        else {
            front =0;
            rear++;
            arr[rear]= data;
            cout<< "enqueued "<< data<< endl;
        }
    }
    int dequeue(){
        if(isEmpty()){
            cout<< "Can't dequeue "<< endl;
            return -1;
        }
        else {
            int x = arr[front];
            front++;
            cout<< "dequeued "<< x<< "from the queue "<< endl;
            
        }
    }
};
int main(){
    Queue* q= new Queue();
    q-> enqueue(10);
    q-> enqueue(20);
    q-> enqueue(30);
    q-> enqueue(40);
    q-> enqueue(50);
    q-> enqueue(60);
    q-> dequeue();


}