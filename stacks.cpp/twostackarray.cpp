// implement two stacks using single array
#include<iostream>
using namespace std;
class Stack{
    public:
    int *arr;
    int size;
    int top1;
    int top2;
    Stack(int size){
        this-> size= size;
        this-> arr= new int[size];
        this-> top1 = -1;
        this-> top2= size;
    }
    bool isempty1(){
        if(top1 == -1){
            cout<< "stack1 is empty"<< endl;
            return true;
        }
        else{
            return false;
        }
    }
    bool isempty2(){
        if(top2== size){
            cout<< "stack2 is empty"<< endl;
            return true;
        }
        else {
            return false;
        }
    }
    bool isfull(){
        if( top2 - top1 == 1){
            return true;
        }
        else{
            return false;
        }
    }
    void push1(int data){
        if(isfull()){
            cout<< "stack is full, can't push"<< endl;
            return;
        }
        else {
            top1++;
            arr[top1]= data;
        }
    }
    void push2(int data){
        if(isfull()){
            cout<< "stack is full, can't push"<< endl;
            return;
        }
        else {
            top2--;
            arr[top2]= data;
        }
    }
    void pop1(){
        if(isempty1()){
            cout<< "stack is empty, can't delete "<< endl;
            return;
        }
        else {
            arr[top1]= -1;
            top1--;
        }
    }
    void pop2(){
        if(isempty2()){
            cout<< "stack is empty, can't delete"<< endl;
            return;
        }
        else {
            arr[top2]= -1;
            top2++;
        }
    }
    void print(){
        cout<< "top1: "<< top1<< endl;
        cout<< "top2: "<< top2<< endl;
        for(int i=0; i< size; i++){
            cout<< arr[i]<< " ";
        }
        cout<< endl;
    }
};
int main(){
    Stack sp(8);
    sp.push1(10);
    sp.push1(20);
    sp.push2(30);
    sp.push2(40);
    sp.pop1();
    sp.pop2();
    sp.pop1();
    sp.pop1();
    sp.print();


}
