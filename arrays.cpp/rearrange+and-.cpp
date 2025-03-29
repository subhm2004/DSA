// you are given an array arrange consecutive elements into positive and negative numbers respectively

#include<iostream>
using namespace std;
void rearrangearray(int arr[], int size, int i){
    for(i=0; i< size; i= i+2) {
        if(arr[i] < 0){
            for(int j= i+1; j<size; j++) {
                if(arr[j]> 0){
                    arr[i]= arr[j];
                    break;
                }
            }
        }       
    }
}
int main() {
    int arr[] = {-5,-3,2,1,-1,0,9,-8};
    int size =8;
    int i=0;
    rearrangearray(arr, size, i);
}