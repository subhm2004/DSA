#include<iostream>
#include<limits.h>
using namespace std;
class Stack{
    public:
    int *arr;
    int top1;
    int top2;
    int size;
    Stack(int size){
        this-> size = size;
        arr= new int[size];
        this-> top1= -1;
        this-> top2= size;
    }
    bool isEmpty(){
        if(top1== -1 && top2== size){
            return true;
        }
        else {
            return false;
        }
    }
    bool isFull(){
        if(top2 == top1+1){
            return true;
        }
        else {
            return false;
        }
    }
    void push1(int data){
        if(top2== top1+1){
            cout<< "Stack Overflow"<< endl;
        }
        else {
            top1++;
            arr[top1]= data;

        }
    }
    void push2(int data){
        if(top2== top1+1){
            cout<< "Stack Overflow"<< endl;
        }
        else{
            top2--;
            arr[top2]= data;
        }
    }
    void pop1(){
        if(top1 == -1 ){
            cout<< "Stack Underflow"<< endl;
        }
        else {
            top1--;
        }
    }
    void pop2(){
        if(top2== size){
            cout<< "Stack Underflow"<< endl;
        }
        else {
            top2++;
        }
    }
    int gettop1(){
        if(top1== -1){
            cout<< "Stack1 Underflow"<< endl;
            return INT_MIN;
        }
        else {
            return arr[top1];
        }
    }
    int gettop2(){
        if(top2== size){
            cout<< "Stack2 Underflow"<< endl;
            return INT_MIN;
        }
        else {
            return arr[top2];
        }
    }
    void print(){
        cout<< "Top1: "<< top1<< endl;
        cout<< "Top2: "<< top2<< endl;
        for(int i=0; i< size; i++){
            cout<< arr[i]<< " ";
        }
        cout<< endl;
    }   
};

int main(){
    Stack sp(6);
    sp.push1(10);
    sp.push2(20);
    sp.push1(30);
    sp.push2(40);
    sp.push1(50);
    sp.push2(60);
    sp.print();
}
