#include<iostream>
using namespace std;
class Heap{
    public:
    int size;
    int *arr;
    int capacity;
    Heap(int capacity){
        this-> size=0;
        this-> arr= new int[capacity];
        this-> capacity= capacity;
    }
    void insert(int val){
        if(size== capacity){
            cout<< "heap overflow"<< endl;
            return;
        }
        size++;
        int index= size;
        arr[index]= val;
        // value is inserted in the heap, now place the value at its correct position
        while(index>1){
            int parent= index/2;
            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else {
                break;
            }
        }
    }
    void printHeap(){
        for(int i=0; i<= size; i++){
            cout<< arr[i]<< " ";
        }
    }
};
int main(){
    Heap h(10);
    h.insert(10);
    h.insert(1);
    h.insert(11);
    h.insert(15);
    h.insert(5);
    h.insert(6);
    cout<< "Printing heap: "<< endl;
    h.printHeap();

}