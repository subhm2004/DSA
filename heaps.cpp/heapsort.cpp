#include<iostream>
using namespace std;
class Heap{
    public:
    int size;
    int capacity;
    int *arr;
    Heap(int capacity){
        this-> size=0;
        this-> capacity= capacity;
        this-> arr= new int[capacity];
    }
    void insert(int val){
        if(size== capacity){
            return;
        }
        size++;
        arr[size]= val;
        // place the elemnet at its correct position
        int index= size;
        while(index>1){
            int parent= size/2;
            if(arr[parent]< arr[index]){
                swap(arr[parent], arr[index]);
                index= parent;
            }
            else {
                break;
            }
        }
    }
    void printHeap(){
        for(int i=1; i<= size; i++){
            cout<< arr[i]<< " ";
        }
    }
    void deleteHeap(){
        // delete first element
        arr[1]= arr[size];
        size--;
        int index=1;
        while(index< size){
            int left= 2*index;
            int right= 2*index+1;
            int largest= index;
            if(left<= size && arr[largest]< arr[left]){
                largest= left;
            }
            if(right<= size && arr[largest]< arr[right]){
                largest= right;
            }
            if(largest!=index){
                swap(arr[largest], arr[index]);
                index= largest;
            }
            else {
                break;
            }
        }       
    }
};
void heapify(int arr[], int index, int size){
    int left= 2*index;
    int right= 2*index+1;
    int largest= index;
    if(left<= size && arr[largest]< arr[left]){
        largest= left;
    }
    if(right<= size && arr[largest]< arr[right]){
        largest= right;
    }
    if(largest!= index){
        swap(arr[largest], arr[index]);
        index= largest;
        heapify(arr,index,size); 
    }
}
void buildHeap(int arr[], int size){
    for(int i= size/2; i>0; i--){
        heapify(arr,i,size);
    }
}
void heapsort(int arr[], int size){
    while(size!=1){
        swap(arr[1], arr[size]);
        size--;
        heapify(arr,1,size);

    }
}