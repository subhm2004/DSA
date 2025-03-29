// intersection of two arrays
#include<iostream>
using namespace std;
int main() {
    int arr[] = { 1,3,3,4,4,5,5,6};
    int sizearr = 8;
    int brr[] = {3, 3,5,5,8, 9};
    int sizebrr = 4;
    for(int i=0; i< sizearr; i++) {
        for(int j=0; j< sizebrr; j++) {
            if(arr[i] == brr[j]) {
                cout<< arr[i] << " ";
            }
        }
    }
}