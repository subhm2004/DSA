#include<iostream>
using namespace std;
int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int size = 7;
    int start = 0; 
    int end = size -1;
    int temp;
    while(start <= end) {     
        // swapping  
            temp= arr[start];
            arr[start]= arr[end];
            arr[end]= temp;
            
        start++;
        end--;
    }
    for(int i=0; i<size; i++) {
        cout<< arr[i] << " ";

    }
    return 0;

}