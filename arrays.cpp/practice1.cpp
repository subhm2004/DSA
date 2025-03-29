#include<iostream>

using namespace std;
int main(){
    int arr[] = { 1,2,4,5,6,7,8,9,10};
    int size = 9;
    int largest = arr[0];
    
    for(int i=0; i<size; i++) {
        if(arr[i] > largest ) {
            largest = arr[i];
        }

    }
    cout<< "largest element of array is  "<< largest<< endl;
    
    return 0;
}
