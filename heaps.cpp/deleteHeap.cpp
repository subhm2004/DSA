#include<iostream>
using namespace std;
class Heap{
    public:
    int size;
    int capacity;
    int *arr;
    Heap(int capacity){
        this-> capacity= capacity;
        this-> size= 0;
        this-> arr= new int[capacity];
    }
    void insert(int val){
        if(size== capacity){
            cout<< "Overflow"<< endl;
            return;
        }
        size++;
        arr[size]= val;
        // element ko uski sahi place pr pahunchao
        int index= size;
        while(index>1){
            int parent= index/2;
            if(arr[parent]< arr[index]){
                swap(arr[parent], arr[index]);
                index= parent;
            }
            else {
                break;
            }
        }
    }
    void deleteElement(){
        // always delete element from root
        arr[1]= arr[size];
        size--;
        int index=1;
        while(index< size){
            int largest= index;
            int left= 2* index;
            int right= 2* index+1;
            if(left<= size && arr[largest] < arr[left]){
                largest= left;
            }
            if(right<= size && arr[largest] < arr[right]){
                largest= right;
            }
            if(largest!= index){
                swap(arr[largest], arr[index]);
                index= largest;
            }
            else {
                break;
            }
        }
    }
};
void Heapify(int arr[], int size, int index){
    int largest= index;
    int left= 2* index;
    int right= 2* index+ 1;
    if(left<= size && arr[largest]< arr[left]){
        largest= left;
    }
    if(right<= size && arr[largest]< arr[right]){
        largest= right;
    }
    if(largest!= index){
        swap(arr[largest], arr[index]);
        index= largest;
        Heapify(arr, size, index);
    }
}
void buildHeap(int arr[], int size){
    for(int i= size/2; i>0; i--){
        Heapify(arr,size,i);
    }
}
void HeapSort(int arr[], int size){
    while(size >0){
        swap(arr[1], arr[size]);
        size--;
        Heapify(arr,size,1);
    }
}
