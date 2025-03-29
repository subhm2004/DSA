#include<iostream>
using namespace std;
int main() {
    int arr[] = {10, 20 ,30, 40, 50, 60, 70, 80};
    int size = 8;
    int i = 0, j = size -1;
    while(i <= j) {
        if( i == j) {
            cout<< arr[i]<< " ";
        }
        else {
        cout<< arr[i]<< " ";
        cout<< arr[j]<< " ";
        }
        i++;
        j--;
        
    }
    return 0;
}