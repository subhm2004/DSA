#include<iostream>
using namespace std;
class NStack{
    public:
    int *arr, *top, *next;
    int number;
    int freespot;
    int size;
    NStack(int n, int s){
        this-> size= s;
        number= n;
        arr= new int[size];
        top= new int[number];
        next= new int[size];
        freespot=0;
        // initialisation
        for(int i=0; i<number; i++){
            top[i]= -1;
        }
        for(int i=0; i<size; i++){
            next[i]= i+1;
        }
        next[size-1]= -1;
    }
    void push(int data, int m){
        if(freespot==-1){
            cout<< "Can't be pushed"<< endl;
        }
        else {
            int index= freespot;
            freespot= next[index];
            arr[index]= data;
            next[index]= top[m-1];
            top[m-1]= index;
        }
    }
    int pop(int m){
        // check if that particular stack is empty 
        if(top[m-1] ==-1){
            return -1;
        }
        else {
            int index= top[m-1];
            top[m-1]= next[index];
            next[index]= freespot;
            freespot= index;
            return arr[index];

        }

    }
    ~NStack(){
        delete []arr;
        delete []top;
        delete []next;
    }
};
int main(){
    // dynamic memory allocation
    NStack* st= new NStack(2,6);
}