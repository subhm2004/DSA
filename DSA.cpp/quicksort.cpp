#include<iostream>
using namespace std;
int partition(int *arr, int s, int e){
    int pivotindex= s;
    int pivotelement= arr[s];
    int count=0;
    for(int i=s+1; i<=e; i++){
        if(arr[i]<=pivotelement){
            count++;
        }
    }
    int rightindex= s+count;
    swap(arr[pivotindex], arr[rightindex]);
    pivotindex= rightindex;
    // place smaller elemnet in left and greater element in right
    int i=s;
    int j=e;
    while(i<pivotindex && j>pivotindex ){
        if(arr[i]< pivotelement){
            i++;
        }
        if(arr[j]> pivotelement){
            j--;
        }
    }
        // 2 case ho skte h
        if(i<pivotindex && j> pivotindex){
            swap(arr[i], arr[j]);
        }
    
    return pivotindex;
}
void quicksort(int* arr, int s, int e){
    if(s>=e){
        return ;
    }
    // partition logic
    int index= partition(arr,s,e);
    // recurcive call for left part
    quicksort(arr,s,index-1);
    quicksort(arr,index+1,e);
}
int main(){
    int arr[]= {12,11,1,56,34,23,22};
    int size= 7;
    int s=0, e= size-1;
    quicksort(arr,s,e);
    for(int i=0; i< size; i++){
        cout<< arr[i]<< " ";
    }
}