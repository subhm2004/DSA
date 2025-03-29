#include<iostream>
using namespace std;

void mergearray(int *arr, int s, int e){
    int mid= s+(e-s)/2;
    int size1= mid-s+1;
    int *left = new int[size1];
    int size2= e-mid;
    int *right= new int[size2];
    // copy the values in left array
    int k= s;
    for(int i=0;i< size1; i++){
        left[i]= arr[k];
        k++;
    }
    // copy the values in right subarray
    k= mid+1;
    for(int i=0;i< size2; i++){
        right[i]= arr[k];
        k++;
    }

    int i=0, j=0;
    int index=s;
    while(i<size1 && j<size2){
        if(left[i]<= right[j]){
            arr[index]= left[i];
            index++;
            i++;
        }
        else if(right[j]< left[i]){
            arr[index]= right[j];
            index++;
            j++;
        }
    }
    while(i<size1){
        arr[index++]= left[i++];
    }
    while(j<size2){
        arr[index++]= right[j++];
    }
}
void mergesort(int *arr, int s, int e){
    if(s>=e){
        return;
    }
    int mid= s+(e-s)/2;
    mergesort(arr,s,mid);
    mergesort(arr,mid+1,e);
    mergearray(arr,s,e);

}
int main(){
    int arr[]= {23,2,11,4,1,33,10};
    int size= 7;
    int s=0, e= size-1;
    mergesort(arr,s,e);
    for(int i=0; i<size; i++){
        cout<< arr[i]<< " ";
    }

}