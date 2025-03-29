#include<iostream>
using namespace std;
class Heap{
    public:
    int *arr;
    int size;
    int capacity;
    Heap(int capacity){
        this-> size= 0;
        this-> arr= new int[capacity];
        this-> capacity= capacity;
    }
    void insert(int val){
        if(size== capacity){
            return;
        }
        size++;
        arr[size]= val;
        // place the element at its correct position
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
    void HeapPrint(){
        for(int i=0; i<size; i++){
            cout<< arr[i]<< " ";
        }
    }
    // deletion hamesha root ka hoga
    void deleteHeap(){
        arr[1]= arr[size];
        size--;
        // position the 1st elemnet to its correct place
        int index= 1;
        while(index< size){
            int largest= index;
            int left= 2*index;
            int right= 2*index+1;
            if(left<= size && arr[largest]< arr[left]){
                largest= left;
            }
            if(right<= size && arr[largest]< arr[right]){
                largest= right;
            }
            if(largest!= index){
                swap(arr[largest], arr[index]);
                index = largest;
            }
            else {
                break;
            }
        }
    }

};
void Heapify(int arr[], int index, int size){
            int largest= index;
            int left= 2* index;
            int right= 2*index+1;
            if(left<= size && arr[largest]< arr[left] ){
                largest= left;
            }
            if(right<= size && arr[largest]< arr[right]){
                largest= right;
            }
            if(largest!= index){
                swap(arr[largest], arr[index]);
                index= largest;
                Heapify(arr,index,size);
            }
 
}
void buildHeap(int arr[], int size){
            for(int i=size/2; i>0; i--){
                Heapify(arr,i,size);
            }

}
void HeapSort(int arr[], int size){
            while(size >0){
                swap(arr[1], arr[size]);
                size--;
                Heapify(arr,1, size);
              
            }
}
int main(){
    int arr[]= {-1,12,56,43,6,78,87,5,44,3,23,32};
    int size= 11;
    buildHeap(arr,size);
    cout<< "Printing Heap"<< endl;
    for(int i=0; i<= size; i++){
        cout<< arr[i]<<" ";
    }
    cout<< endl;
    HeapSort(arr, size);
    cout<< "Printing Heap after sorting"<< endl;
    for(int i=0; i<= size; i++){
        cout<< arr[i]<<" ";
    }




    

}