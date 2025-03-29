// maximum element in an array using recursion
#include<iostream>
#include<limits.h>
using namespace std;

void maxelement(int arr[], int size, int& max , int i) { 
    // reference variable is created here because variables are pass by value
    // har function k liye max variable pass by value hua tha jo return krne pr khatam ho gya
    if(i>=size) {
        return;
    }
    
    if(arr[i]> max) {
        max = arr[i];
    }
    maxelement(arr, size , max, i+1);
    
}
int main() {
    int arr[] = { 10,12,34,35,45,67};
    int size = 6;
    int i=0;
    int max = INT_MIN;

    maxelement(arr, size, max, i);
    cout<< "maximum element is "<< max << endl;
    return 0;
}
