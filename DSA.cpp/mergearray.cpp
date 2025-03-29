// merge two sorted array
#include<iostream>
using namespace std;
int main(){
    int arr1[]= {2,4,6};
    int size1= 3;
    int arr2[]= {3,5,7,9,11};
    int size2= 5;
    int mainarr[size1+size2];
    int i=0, j=0, k=0;
    while(i<size1 && j<size2){
        if(arr1[i]<= arr2[j]){
            arr[k]= arr1[i];
            k++;
            i++;
        }
        else if(arr2[j]< arr1[i]){
            arr[k]= arr2[j];
            k++;
            j++;
        }
    }
    while(i<size1){
        mainarr[k++]= arr1[i++];
    }
    while(j<size2){
        mainarr[k++]= arr2[j++];
    }

}