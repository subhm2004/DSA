// linear search using recursion
#include<iostream>
using namespace std;

void linearsearch(int arr[], int& size,int i, int& target) {
    if(arr[i] == target) {
        cout<< "target found at index "<< i<< endl;
        return;
    }
    linearsearch(arr, size, i+1, target);
}
int main() {
    int arr[] = {1,34,23,21,45,43};
    int size= 6;
    int target = 21;
    int i=0;
    linearsearch(arr,size,i,target);
}