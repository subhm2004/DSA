// minimum element in an array using recursion
#include<iostream>
#include<limits.h>
using namespace std;

void minelement(int arr[], int size, int i, int& min) {
    if(i>= size) {
        return;
    }
    if(arr[i] < min) {
        min = arr[i];
    }
    minelement(arr, size, i+1, min);

}
int main() {
    int arr[] = { 23, 34, 45, 56, 12, 67};
    int i=0, size = 6;
    int min = INT_MAX;
    minelement(arr, size, i, min);
    cout<< "minimum element is "<< min << endl;

}
